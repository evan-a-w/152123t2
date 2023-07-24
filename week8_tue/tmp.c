#include <stdint.h>
#include <stdio.h>

int main(void) {
    uint16_t x;
    fwrite(&x, 2, 1, stdout);
}
