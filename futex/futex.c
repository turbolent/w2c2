#include <stdio.h>
#include <assert.h>
#include "futex.h"
#include "list.h"
#include "map.h"

#ifndef WASM_THREAD_TYPE
#error "Please define a threads implementation to use (WASM_THREADS_*)"
#endif

typedef enum WaitStatus {
    waitStatusWaiting = 0,
    waitStatusNotified = 1
} WaitStatus;

typedef struct Wait {
    ListLink link;
    WaitStatus status;
    WASM_COND_TYPE cond;
} Wait;

#define FUTEX_BUCKET_COUNT 1024

static
W2C2_INLINE
void
waitFree(
    Wait* wait
) {
    WASM_COND_FREE(&wait->cond);
    free(wait);
}

static
void
waitLinkFree(
    ListLink* link
) {
    waitFree((Wait*)link);
}

static
W2C2_INLINE
void
futexValueFree(
    void* value
) {
    Wait* wait = (Wait*)value;
    listFree((ListLink*)wait, waitLinkFree);
}

static
void
futexMapFree(
    void* futexMap
) {
    mapFree((Map*)futexMap, futexValueFree);
    free(futexMap);
}

U32
wasmMemoryAtomicWait(
    wasmMemory* mem,
    U32 address,
    U64 expect,
    I64 timeout,
    bool wait64
) {
    bool isTimeout = false;
    Wait** waitList = NULL;
    Map* futexMap = NULL;

    WASM_MUTEX_TYPE* mutex = &mem->mutex;
    WASM_MUTEX_LOCK(mutex);

    /* Check expected */

    if (wait64
        ? i64_atomic_load(mem, address) != expect
        : i32_atomic_load(mem, address) != (U32)expect
    ) {
        WASM_MUTEX_UNLOCK(mutex);
        /* "not-equal", the loaded value did not match the expected value */
        return 1;
    }

    /* Suspend */
    {
        /* Create wait */
        Wait* wait = calloc(sizeof(Wait), 1);
        if (!wait) {
            WASM_MUTEX_UNLOCK(mutex);
            trap(trapAllocationFailed);
            return (U32)-1;
        }

        wait->status = waitStatusWaiting;

        if (!WASM_COND_INIT(&wait->cond)) {
            WASM_MUTEX_UNLOCK(mutex);
            free(wait);
            trap(trapAllocationFailed);
            return (U32)-1;
        }

        /* Insert wait into futex map */

        /* Create futexMap, if needed */
        futexMap = (Map*)mem->futex;
        if (!futexMap) {
            futexMap = (Map*)calloc(1, sizeof(Map));
            if (!futexMap) {
                WASM_MUTEX_UNLOCK(mutex);
                waitFree(wait);
                trap(trapAllocationFailed);
                return (U32)-1;
            }
            mapInitialize(futexMap, FUTEX_BUCKET_COUNT);
            mem->futex = futexMap;
            mem->futexFree = futexMapFree;
        }

        /* Get or insert wait list */
        waitList = (Wait**)mapGet(futexMap, address);
        if (!waitList) {
            waitList = (Wait**)mapInsert(futexMap, address);
            if (!waitList) {
                WASM_MUTEX_UNLOCK(mutex);
                waitFree(wait);
                trap(trapAllocationFailed);
                return (U32)-1;
            }
        }

        /* Add wait to wait list */
        *waitList = (Wait*)listPrepend(
            (ListLink*)*waitList,
            &wait->link
        );

        /* Wait for notification */
        if (timeout < 0) {
            while (true) {
                WASM_COND_WAIT(&wait->cond, mutex);
                if (wait->status == waitStatusNotified) {
                    break;
                }
            }
        } else {
            while (true) {
                if (!WASM_COND_RELATIVE_WAIT(&wait->cond, mutex, timeout)) {
                    break;
                }
                if (wait->status == waitStatusNotified) {
                    break;
                }
            }
        }

        isTimeout = wait->status == waitStatusWaiting;

        /* Remove wait from wait list */

        *waitList = (Wait*)listRemove(
            (ListLink*)*waitList,
            &wait->link
        );

        /* Remove wait list from futex map, if empty */
        if (*waitList == NULL) {
            Wait* removedWaitList = (Wait*)mapRemove(futexMap, address);
            assert(removedWaitList == NULL);
        }

        /* Free wait */
        waitFree(wait);
    }

    WASM_MUTEX_UNLOCK(mutex);

    return isTimeout
           ? 2 /* "timed-out", not woken before timeout expired */
           : 0 /* "ok", woken by another agent in the cluster */;
}

U32
wasmMemoryAtomicNotify(
    wasmMemory *mem,
    U32 address,
    U32 count
) {
    void** value = NULL;
    Map* futexMap = NULL;

    U32 notifiedCount = 0;

    WASM_MUTEX_TYPE *mutex = &mem->mutex;

    if (!mem->shared) {
        return notifiedCount;
    }

    WASM_MUTEX_LOCK(mutex);

    /* Get wait list */

    futexMap = (Map*)mem->futex;
    if (!futexMap) {
        WASM_MUTEX_UNLOCK(mutex);
        return 0;
    }

    value = mapGet(futexMap, address);
    if (!value) {
        WASM_MUTEX_UNLOCK(mutex);
        return notifiedCount;
    }

    /* Notify wait list */
    {
        Wait *wait = *value;
        while (wait && notifiedCount < count) {
            if (wait->status == waitStatusWaiting) {
                wait->status = waitStatusNotified;
                WASM_COND_SIGNAL(&wait->cond);
                notifiedCount++;
            }
            wait = (Wait*)wait->link.next;
        }
    }

    WASM_MUTEX_UNLOCK(mutex);

    return notifiedCount;
}
