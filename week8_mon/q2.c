#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Write a C program, fgrep.c, which is given 1+ command-line arguments which is
 * a string to search for. */
/* If there is only 1 command-line argument it should read lines from stdin and
 * print them to stdout iff they contain the string specified as the first
 * command line argument. */

/* If there are 2 or more command line arguments, it should treat arguments
 * after the first as filenames and print any lines they contain which contain
 * the string specified as the first command line arguments. */

/* When printing lines your program should prefix them with a line number. */

/* It should print suitable error messages if given an incorrect number of
 * arguments or if there is an error opening a file. */

void print_occurrences_in_file(char *word, FILE *file) {
    int line_number = 0;
    char line[1000];
    while (fgets(line, 1000, file) != NULL) {
        line_number++;
        // read a line into buffer
        // print the line if it contains word
        if (strstr(line, word) != NULL) {
            // found word in buffer
            printf("%d %s", line_number, line);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        fprintf(stderr, "Please provide at least one arguments\n");
        exit(1); // exits the program with the given code, same as returning 1
                 // in main
        return 1;
    }

    char *word = argv[1];
    if (argc == 2) {
        print_occurrences_in_file(word, stdin);
    } else {
        for (int i = 2; i < argc; i++) {
            char *current_file = argv[i];
            FILE *file_to_search = fopen(current_file, "r");
            if (file_to_search == NULL) {
                // print error and return
                // perror - prints based on the value of errno to stderr
                // use perror if the fucntion that failed sets it on failure
                // (man pages tell us)
                perror(current_file);
                exit(1);
            }
            printf("Searching in %s\n", current_file);
            print_occurrences_in_file(word, file_to_search);
            printf("\n");
        }
    }
}
