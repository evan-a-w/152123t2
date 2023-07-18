#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_occurrences(FILE *in, char *word_to_search) {
    int line_number = 0;
    char buffer[1000];
    while (fgets(buffer, 1000, in) != NULL) {
        line_number++;
        // buffer is a line
        // print out buffer if word_to_search is inside buffer
        if (strstr(buffer, word_to_search) != NULL) {
            printf("%d %s", line_number, buffer);
        }
    }
}

int main(int argc, char **argv) {
    if (argc == 1) {
        fprintf(stderr, "Please supply a word to search for\n");
        exit(1);
        /* return 1; */
    }

    char *word_to_search = argv[1];

    if (argc == 2) {
        print_occurrences(stdin, word_to_search);
    } else {
        for (int i = 2; i < argc; i++) {
            char *file_to_search = argv[i];
            FILE *file = fopen(file_to_search, "r");
            if (file == NULL) {
                /* fprintf(stderr, "Error: Could not open %s\n",
                 * file_to_search); */
                perror(file_to_search);
                exit(1);
            }
            print_occurrences(file, word_to_search);
            printf("\n");
            fclose(file);
        }
    }
}
