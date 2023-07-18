#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int main(void) {
    struct stat buf;
    stat("q2.c", &buf);
    printf("q2.c: %ld\n", buf.st_size);
    printf("perms: %o\n", buf.st_mode);
    printf("%s\n", S_ISDIR(buf.st_mode) ? "directory" : "regular file");

    return 0;
}
