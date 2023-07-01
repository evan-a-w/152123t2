#include <stdio.h>

char *s1 = "abc";

int main(void) {
    char *s2 = "def";

    // this succeeds (you can change global variables)
    // (we can change the pointer itself)
    s1 = "ced";
    // string literals stored in read only data

    // this fails because you cant change string literals
    *s = 'd'; // FAILS
    // ...
}

#include <stdio.h>

int *get_num_ptr(void);

int main(void) {
    int *num = get_num_ptr();

    printf("%d\n", *num);
}

int *get_num_ptr(void) {
    // stack allocated
    int x = 42;
    return &x;
    // freed afterwards automatically

    // heap allocated
    int *x = malloc(sizeof(int));
    *x = 42;
    return x;
}

#include <stdio.h>

//           null terminator
//              |
//              v
// {'H', 'i', '\0'};
int main(void) {
    char str[10] = "Hi";
    str[0] = 'H';
    str[1] = 'i';
    strcpy(str, "Hi");
    /* str[2] = '\0'; */
    // Hi
    printf("%s", str);
    return 0;
}

#include <stdio.h>

// ./print_arguments I love MIPS
// argc = 4 (it includes the program name)
// argv[0] is the name of the program ("./print_arguments")

// argc is int, argv is array of strings
// argc is the number of arguments passed in
// argv is the array of those arguments
int main(int argc, char *argv[]) {
    printf("argc=%d\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("argv[%d]=%s\n", i, argv[i]);
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

/* Why do we need the function atoi in the following program? */
/* The program assumes that command-line arguments are integers. What if they
 * are not integer values? */
int main(int argc, char *argv[]) {
    int sum = 0;
    for (int i = 0; i < argc; i++) {
        // string to int
        sum += atoi(argv[i]);
    }
    printf("sum of command-line arguments = %d\n", sum);
    return 0;
}

int factorial(int n) {
    if (n == 1) {
        return 1;
    }

    return n * factorial(n - 1);
}

int recursion_loop(int n) {
    int res = 1;

    for (int i = 1; i <= n; i++) {
        res *= i;
    }

    return res;
}
