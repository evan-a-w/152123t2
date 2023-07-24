#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int main(void) {
    extern char **environ;
    char *home = getenv("HOME");
    char *rest = "/.diary";
    int size = strlen(rest) + strlen(home) + 1;
    char *path = malloc(size);

    snprintf(path, size, "%s%s", home, rest);

    struct stat s;
    if (stat(path, &s) == 0) {
        // success
        printf("%lu\n", s.st_size);
    }

    FILE *diary = fopen(path, "r");
    if (diary == NULL) {
        perror(path);
        return 1;
    }
    int c;
    while ((c = fgetc(diary)) != EOF) {
        fputc(c, stdout);
    }

    free(path);
    fclose(diary);
}
