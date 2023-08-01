#include <stdio.h>
#include <pthread.h>

void *thread_run(void *data) {
    printf("Hello from thread!\n");

    return "retval";
}

int main(void) {
    pthread_t thread;
    if (pthread_create(
            &thread,    // the pthread_t handle that will represent this thread
            NULL,       // thread-attributes -- we usually just leave this NULL
            thread_run, // the function that the thread should start executing
            NULL        // data we want to pass to the thread -- this will be
                        // given in the `void *data` argument above
            )
        != 0) {
        printf("Error creating thread!\n");
        return 1;
    }

    void *retval;
    if (pthread_join(thread, &retval) != 0) {
        printf("Error joining thread!\n");
        return 1;
    }

    printf("Thread returned: %s\n", (char *)retval);

    return 0;
}
