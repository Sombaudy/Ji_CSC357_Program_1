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
        char prev_input[100] = "";
        printf("No file provided, enter input (ctrl d to exit): ");

        fgets(input, sizeof(input), stdin);
        printf("%s", input);
        strcpy(prev_input, input);
        
        while(fgets(input, sizeof(input), stdin) != NULL) {
            //printf("enter input: ");
            if (strcmp(input, prev_input) != 0) {
            printf("%s", input);
            }
            strcpy(prev_input, input);

        }
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
            if (read > 0 && line[read - 1] == '\n') {
                line[read - 1] = '\0';
            }
            if (prev_line == NULL) {
                printf("%s\n", line);
            } else if (strcmp(line, prev_line) != 0){
                printf("%s\n", line);
            }
            //printf("prev: %s", prev_line);
            //printf("line: %s", line);
            strcpy(prev_line, line);
        }
        free(line);
        //printf("\n");

        fclose(file);
    }

    return 0;
}