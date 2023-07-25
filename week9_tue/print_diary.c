#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int main(void) {
    char *home = getenv("HOME");

    if (home == NULL) {
        fprintf(stderr, "no home directory!\n");
        return 1;
    }

    char *second_part = "/.diary";

    int len = strlen(home) + strlen(second_part) + 1;
    char *path = malloc(len);

    snprintf(path, len, "%s%s", home, second_part);

    FILE *diary_file = fopen(path, "r");
    if (diary_file == NULL) {
        perror(path);
        return 1;
    }

    int c;
    while ((c = fgetc(diary_file)) != EOF) {
        putchar(c);
    }

    struct stat s;
    stat(path, &s);

    fclose(diary_file);
    free(path);
}
