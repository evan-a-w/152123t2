#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *thread_run(void *data) {
    (void)data; // so the compiler doesnt complain about unused variables
    for (;;) {
        printf("feed me input!\n");
        sleep(1);
    }

    return NULL;
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

    char *line_ptr = NULL;
    size_t n = 0;
    while (getline(&line_ptr, &n, stdin) != -1) {
        printf("you entered: %s", line_ptr);
    }
    free(line_ptr);

    /* if (pthread_join(thread, NULL) != 0) { */
    /*     printf("Error joining thread!\n"); */
    /*     return 1; */
    /* } */

    return 0;
}
