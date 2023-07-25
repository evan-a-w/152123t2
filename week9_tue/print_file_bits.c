#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

void print_integer_to_file(uint64_t num, int num_bytes, FILE *f);
uint64_t read_integer_from_file(int num_bytes, FILE *f);

int main(void) {
    // little endian integers in a file
    // read from the file, in a portable way

    // string always represented in memory like this
    // "hello"
    // 'h' 'e' 'l' 'l' 'o' '\0'
    // "1234"
    // '1' '2' '3' '4' '\0'

    // 0b 11110000 00001111
    // numbers are represented depending on their endianness

    // little endian
    //        0        1
    // 00001111 11110000
    //
    // big endian
    //        0        1
    // 11110000 00001111

    // 0b 11110000 00001111 00011000 00100100
    // little endian
    //        0        1        3        4
    // 00100100 00011000 00001111 11110000
    // big endian
    //        0        1        3        4
    // 11110000 00001111 00011000 00100100

    FILE *f;
    uint64_t x = 0;
    // wrong - not portable
    fread(&x, 8, 1, f);

    // we go over bytes from smallest to largest
    for (int i = 0; i < 7; i++) {
        int c = fgetc(f);
        assert(c != EOF);
        uint64_t bits = c;
        x |= bits << (i * 8);
    }

    int *p = malloc(sizeof(int) * 3);
    p[0] = 1;
    p[1] = 2;
    p[2] = 3;

    // wrong - dcc would complain
    fwrite(&x, 8, 1, f);
    // wrong - dcc wouldnt complain but we will see it and mark down
    fwrite((char *)&x, 8, 1, f);

    // do similar thing for writing
}
