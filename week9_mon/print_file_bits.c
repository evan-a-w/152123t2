#include <stdio.h>
#include <stdint.h>

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *f = fopen(argv[1], "r");
    if (f == NULL) {
        perror(argv[1]);
        return 1;
    }

    // little endian
    // smaller bytes come first
    // 0b 00001000 0000001
    uint32_t num = 0;
    int c;

    // first second third fourth
    // assumes our system is little endian because it reads in the earlier bytes
    // into the earlier bit of memory
    // this would work, but its not portable - its wrong if our system is big
    // endian
    /* fread(&num, 1, 4, f); */

    // assume its encoded as little endian in the file
    for (int i = 0; i < 4; i++) {
        c = fgetc(f);
        if (c == EOF) {
            return 1;
        }
        num |= c << (i * 8);
    }

    printf("%d\n", num & 0xFF);

    fclose(f);
    return 0;
}
