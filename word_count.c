#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "funcs.h"

int main(int argc, char *argv[]) {
    char *filename;
    char input[1000];
    bool file_present = checkInput(argc);
    //printf("%s\n", filename);

    bool prev_whitespace = true;
    int line_count = 1;
    int word_count = 0;
    int char_count = 0;

    if (!file_present) { 
        line_count = 0;
        printf("No file provided, enter input (exit with ctrl d): ");
        while (fgets(input, sizeof(input), stdin) != NULL) {
            //printf("input: %s", input);
            for (int i = 0; i < strlen(input); i++) {
                if (isspace(input[i]) != 0) {
                    prev_whitespace = true;
                } else {
                    if (prev_whitespace) {
                        word_count = word_count + 1;
                    }
                    prev_whitespace = false;
                }
                char_count = char_count + 1;
            }
            line_count = line_count + 1;
        }

    }

    if (file_present){
        filename = argv[1];
        FILE *file = openFile(filename);

        char c;

        for (c = getc(file); c != EOF; c = getc(file)) {
            if (isspace(c) != 0) {
                prev_whitespace = true;
            } else {
                if (prev_whitespace) {
                    word_count = word_count + 1;
                }
                prev_whitespace = false;
            }
            char_count = char_count + 1;

            if (c == '\n')
                line_count = line_count + 1;
        }

        fclose(file);
    }

    printf("\nlines: %d\nwords: %d\nchars: %d\n", line_count, word_count, char_count);

    return 0;
}
