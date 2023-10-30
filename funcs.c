#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool checkInput(int argc) {
    if (argc < 2) {
        return false;
    } else {
        return true;
    }
}

FILE* openFile(char* filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror(filename);
        exit(-1);
    }
    return file;
}