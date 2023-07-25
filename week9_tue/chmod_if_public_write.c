#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

void chmod_if_public_write(char *path) {
    struct stat s;
    if (stat(path, &s) != 0) {
        perror(path);
        exit(1);
    }

    if (s.st_mode & 0b10) {
        printf("removing public write from %s\n", path);
        // change mode to not have public write
        s.st_mode &= ~0b10;

        if (chmod(path, s.st_mode) != 0) {
            perror(path);
            exit(1);
        }
    } else {
        printf("%s is not publically writable\n", path);
    }
}

int main(int argc, char **argv) {
    for (int i = 1; i < argc; i++) {
        chmod_if_public_write(argv[i]);
    }
}
