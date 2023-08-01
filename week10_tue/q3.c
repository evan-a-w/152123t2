#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

void *thread_run(void *data) {
    char *to_print = (char *)data;

    for (;;) {
        printf("%s\n", to_print);
    }

    return NULL;
}

int main(void) {
    pthread_t thread;
    if (pthread_create(
            &thread,    // the pthread_t handle that will represent this thread
            NULL,       // thread-attributes -- we usually just leave this NULL
            thread_run, // the function that the thread should start executing
            "there!"    // data we want to pass to the thread -- this will be
                        // given in the `void *data` argument above
            )
        != 0) {
        fprintf(stderr, "Failed to start thread!\n");
        return 1;
    }

    for (;;) {
        printf("Hello\n");
    }

    return 0;
}
