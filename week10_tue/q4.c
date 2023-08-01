#include <stdio.h>
#include <pthread.h>

void *thread_run(void *data) {
    printf("Hello from thread!\n");

    return "retval";
}

int main(void) {
    pthread_t thread;
    // start other thread
    pthread_create(
        &thread,    // the pthread_t handle that will represent this thread
        NULL,       // thread-attributes -- we usually just leave this NULL
        thread_run, // the function that the thread should start executing
        NULL        // data we want to pass to the thread -- this will be
                    // given in the `void *data` argument above
    );

    // main thread continues... instantly returns

    // fix - wait for the other thread to finish
    char *retval;
    pthread_join(thread, (void **)&retval);

    printf("%s\n", retval);

    return 0;
}
