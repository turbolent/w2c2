#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 4
#define NUM_ITER 10

int g_count = 0;

static void* thread(void *arg) {
    printf("Entering thread\n");

    for (int i = 0; i < NUM_ITER; i++) {
        printf(
            "Incremented counter: %d\n",
            __atomic_add_fetch(&g_count, 1, __ATOMIC_SEQ_CST)
        );
    }

    printf("Leaving thread\n");

    return NULL;
}

int main(int argc, char **argv) {
    pthread_t tids[NUM_THREADS];

    printf("Starting threads\n");

    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_create(&tids[i], NULL, thread, NULL) != 0) {
            printf("Thread creation failed\n");
        }
    }

    printf("Joining threads\n");

    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_join(tids[i], NULL) != 0) {
            printf("Thread join failed\n");
        }
    }

    printf(
        "Value of counter after update: %d (expected=%d)\n",
        g_count,
        NUM_THREADS * NUM_ITER
    );
    if (g_count != NUM_THREADS * NUM_ITER) {
        __builtin_trap();
    }

    return 0;
}
