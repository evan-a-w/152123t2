#include <stdint.h>
#include <stdio.h>

uint32_t set_bit(uint32_t x, uint32_t i) {
    uint32_t one_set = 1 << i;
    return x | one_set;
}

// return a number with 1 in i index iff the bit at that index in x is set
uint32_t get_bit(uint32_t x, uint32_t i) {
    uint32_t one_set = 1 << i;
    // 0000000000100000000000
    return x & one_set;
}

uint32_t set_14_to_17(uint32_t x) {
    // construct a number that has 0s everywhere except for bits 14-17
    uint32_t four_bits = 0b1111;
    /* uint32_t four_bits = 15; */
    /* uint32_t four_bits = 0xF; */
    uint32_t four_bits_in_14_to_17 = four_bits << 14;
    // 0b0000  1  1  1  1  00000000
    //        17 16 15 14
    return x | four_bits_in_14_to_17;
}

uint32_t get_bits_14_to_17(uint32_t x) {
    uint32_t four_bits = 0b1111;
    uint32_t mask = four_bits << 14;
    return x & mask;
}

#define READING 0x01
#define WRITING 0x02
#define AS_BYTES 0x04
#define AS_BLOCKS 0x08
#define LOCKED 0x10

int main(void) {
    uint8_t device = 0;
    // make it be locked
    device |= LOCKED; // device = device | LOCKED;

    // is device locked?
    if (device & LOCKED) {
        printf("Device is locked\n");
    }
    return 0;
}
