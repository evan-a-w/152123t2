#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *other_thread(void *p) {
    char *string_to_print = (char *)p;
    for (;;)
        fputs(string_to_print, stdout);

    return NULL;
}

int main(void) {
    char *main_message = "there!\n";
    char *other_message = "Hello\n";

    pthread_t thread;
    pthread_create(
        &thread,      // the pthread_t handle that will represent this thread
        NULL,         // thread-attributes -- we usually just leave this NULL
        other_thread, // the function that the thread should start executing
        (void *)other_message // data we want to pass to the thread -- this will
                              // be given in the `void *data` argument above
    );

    for (;;) {
        fputs(main_message, stdout);
    }

    pthread_join(thread, NULL); // not needed since we loop infinitely above

    return 0;
}
