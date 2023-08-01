#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *thread_run(void *data) {
    for (;;) {
        printf("Feed me input!\n");
        sleep(1);
    }

    return NULL;
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

    char *line = NULL;
    size_t n = 0;

    while (getline(&line, &n, stdin) != -1) {
        printf("You entered: %s", line);
    }

    free(line);

    // pthread_join(thread, NULL);

    return 0;
}
