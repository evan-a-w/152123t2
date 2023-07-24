#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

static uint16_t a;

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void *next_byte(void *byte) { return byte + 1; }

int main2(void) {
    // arr + 1 == &arr[1];
    uint8_t chars[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    uint32_t ints[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    printf("%16p - %16p\n", (void *)&chars[0], (void *)next_byte(&chars[0]));
    printf("%16p - %16p\n", (void *)&ints[0], (void *)next_byte(&ints[0]));

    return 0;
}

int main(void) {
    uint16_t b;

    uint16_t *pa = &a;
    uint16_t *pb = &b;
    uint16_t *pc = malloc(sizeof(uint16_t));

    *pa = 0xAAAA;
    *pb = 0xBBBB;
    *pc = 0xCCCC;

    printf("a:\n\tvalue: 0x%X\n\taddress: %16p\n", *pa, (void *)pa);
    printf("b:\n\tvalue: 0x%X\n\taddress: %16p\n", *pb, (void *)pb);
    // wants void *, gets uint16_t *
    printf("c:\n\tvalue: 0x%X\n\taddress: %16p\n", *pc, (void *)pc);
}
