int main(void) {
        char bytes[32];
        char *x = &bytes[1];
        *x = 'a';
        // stores the byte 'a' into where the address x points to
        int *y = (int *)x;
        // y has the same address as x
        *y = 42;
        // stores the 4 bytes of 42 into the address of y
}
