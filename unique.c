#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "funcs.h"

int main(int argc, char *argv[]) {
    char *filename;
    char input[100];
    bool file_present = checkInput(argc);

    if (!file_present) { 
        printf("No file provided, enter input: ");
        fgets(input, sizeof(input), stdin);
        printf("%s", input);
    }


    if (file_present) {
        filename = argv[1];
        //printf("%s\n", filename);

        FILE *file = openFile(filename);

        char prev_line[100] = "";
        char *line = NULL;
        size_t len = 0;
        ssize_t read = 0;

        while ((read = getline(&line, &len, file)) != -1) {
            if (prev_line == NULL) {
                printf("%s", line);
            } else if (strcmp(line, prev_line) != 0){
                printf("%s", line);
            }
            //printf("prev: %s", prev_line);
            //printf("line: %s", line);
            strcpy(prev_line, line);
        }
        free(line);
        printf("\n");

        fclose(file);
    }

    return 0;
}