#include <stdint.h>
#include <stdio.h>

// usually a C int
int32_t x = 0b101;
// usually an unsigned int
uint32_t y = 0777;

long int z = 0xFF;
long long int w = 123123;
long long unsigned int t = 0;

int64_t r = 0;

const uint32_t first_ = 0b100;
const uint32_t second = 0b101;

uint32_t third = first_ | second;
const uint32_t fourth = first_ ^ second;
const uint32_t fifth = ~first_;
// is fifth == 0b011?
// no, first is actually
// 0b00000000000000000000000000000100

// 0b00000000000000100000000000000000
// 0b00000000000000000000000000000001

// 0b11111111111111111111111111111011
// ~0 == all 1s == UINT_32_MAX

// 0b10000000000000000000000000000100 << 1
// "shift left" the number once
// 0b00000000000000000000000000001000
// "shift right" >>,

// 0b10 << 1 == 0b100
// shift left once is multiplying by two
// shift rigth once is dividing by two
// x << n == x * 2^n
// x >> n == x / 2^n

// 100
//^
// 101
// 001

// 001
//|
// 001
// 001

// x[15]
uint32_t get_15th_bit(uint32_t x) {
    uint32_t _one_in_15th_spot = 0b100000000000000;
    uint32_t one_in_15th_spot = 1 << 15;
    uint32_t masked = x & one_in_15th_spot;
    // removing all the zeros at the start
    uint32_t result = masked >> 15;
    return result;
}

// x[15] = 1
uint32_t set_15th_bit(uint32_t x) {
    uint32_t one_in_15th_spot = 1 << 15;
    return x | one_in_15th_spot;
}

uint32_t reset_15th_bit(uint32_t x) {
    // want a number that is all ones except 0 in the 15th spot
    // 1 << 15 == 2^15
    uint32_t one_in_15th_spot = 1 << 15;
    // 11111111111
    //-
    // 00000100000

    // 10
    // 01
    //-
    // 01

    // 00000100000
    // 11111011111
    uint32_t zero_in_15th_spot = ~one_in_15th_spot;
    uint32_t _zero_in_15th_spot = UINT32_MAX - one_in_15th_spot;
    return x & zero_in_15th_spot;
}

// get the 14th to 17th bits
// 0b00111100000000100100000000000001
uint32_t get_14th_to_17th_bits(uint32_t x) {
    /* uint32_t _one_in_14th_to_17th_spots = 0b00000000111100000000000000; */
    uint32_t one_in_14th_to_17th_spots = 0xf << 14;
    // 0b1111 == 15 == 0xF
    return (x & one_in_14th_to_17th_spots) >> 14;
    // the bits in 0-3 are the 14-17 bits in x, the rest is 0
    // gives us 0b1001
}

// x[15] = 0
// !x = ^
// 0 ^ 1 = 1
// 1 ^ 1 = 0

// 0 | 1 = 1
// 1 | 1 = 1

// 0 & 0 = 0
// 1 & 0 = 0
int main(void) {
    uint32_t x = 0b00000000000000100100000000000001;
    printf("%d\n", get_14th_to_17th_bits(x));
}
