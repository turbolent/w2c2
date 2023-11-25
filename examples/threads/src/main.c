#include <assert.h>
#include <stdlib.h>
#include <wasi/api.h>

static const int64_t SECOND = 1000 * 1000 * 1000;

typedef struct
{
    char *stack;
    int th_ready;
    int th_continue;
    int th_done;
    int failed;
    int tid;
    int value;
} shared_t;

void __wasi_thread_start_C(int thread_id, int *start_arg)
{
    shared_t *data = (shared_t *)start_arg;

    __atomic_store_n(&data->th_ready, 1, __ATOMIC_SEQ_CST);
    __builtin_wasm_memory_atomic_notify(&data->th_ready, 1);

    // so we can have all the threads alive at the same time
    if (__builtin_wasm_memory_atomic_wait32(&data->th_continue, 0, SECOND) == 2)
    {
        data->failed = 1;
        return;
    }

    assert(data->value == 52);

    data->value += 8;
    data->tid = thread_id;

    __atomic_store_n(&data->th_done, 1, __ATOMIC_SEQ_CST);
    __builtin_wasm_memory_atomic_notify(&data->th_done, 1);
}

int main(int argc, char **argv)
{
    shared_t data[3] = {0};
    int tid[3];
    int data_count = sizeof(data) / sizeof(data[0]);
    int i, j;


    for (i = 0; i < data_count; i++)
    {
        data[i].stack = malloc(128);
        data[i].value = 52;
        tid[i] = __wasi_thread_spawn(&data[i]);
        assert(tid[i] > 0);
        assert(__builtin_wasm_memory_atomic_wait32(&data[i].th_ready, 0,
                                                   SECOND) != 2); // not a timeout
    }

    for (i = 0; i < data_count; i++)
    {
        __atomic_store_n(&data[i].th_continue, 1, __ATOMIC_SEQ_CST);
        __builtin_wasm_memory_atomic_notify(&data[i].th_continue, 1);
    }

    for (i = 0; i < data_count; i++)
    {
        assert(__builtin_wasm_memory_atomic_wait32(&data[i].th_done, 0,
                                                   SECOND) != 2); // not a timeout
        assert(data[i].tid == tid[i]);
        assert(data[i].value == 60);

        for (j = 0; j < i; j++)
        {
            assert(data[i].tid != data[j].tid);
        }

        assert(data[i].failed == 0);
        free(data[i].stack);
    }

    return 0;
}
