#include <stdio.h>
#include <stdint.h>

uint64_t hash(char *);

int main(void) {
    char buf[256] = {0};
    fread(buf, 1, 256, stdin);
    uint64_t hash_ = hash(buf);
}
