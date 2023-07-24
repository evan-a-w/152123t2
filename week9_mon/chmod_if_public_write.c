#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdbool.h>

bool is_publically_writeable(mode_t mode) { return mode & 0b10; }

void chmod_file_if_publically_writeable(char *filename) {
    struct stat s;
    if (stat(filename, &s) != 0) {
        perror(filename);
        exit(1);
    }

    if (is_publically_writeable(s.st_mode)) {
        printf("removing public write from %s\n", filename);
        s.st_mode &= ~0b10;
        if (chmod(filename, s.st_mode) != 0) {
            perror(filename);
            exit(1);
        }
    } else {
        printf("%s is not publically writeable\n", filename);
    }
}

int main(int argc, char **argv) {
    for (int i = 1; i < argc; i++) {
        chmod_file_if_publically_writeable(argv[i]);
    }
}
