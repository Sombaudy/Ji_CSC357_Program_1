#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("please provide a file\n");
        exit(-1);
    }

    char *filename = argv[1];
    //printf("%s\n", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror(filename);
        exit(-1);
    }

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
    return 0;
}