#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "utils.h"

// Function to trim whitespace from both ends of a string
void trimWhitespace(char *str) {
    char *end;

    // Trim leading space
    while (isspace((unsigned char)*str)) str++;

    // All spaces?
    if (*str == 0) return;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;

    // Null-terminate the string
    *(end + 1) = '\0';
}

// Function to convert a string to lowercase
void toLowerCase(char *str) {
    for (char *p = str; *p; p++) {
        *p = (char)tolower((unsigned char)*p);
    }
}

// Function to check if a string is a valid label
bool isValidLabel(const char *label) {
    if (!label || !*label) return false; // Empty string is not a valid label

    // Check first character
    if (!isalpha((unsigned char)label[0]) && label[0] != '_') return false;

    // Check remaining characters
    for (size_t i = 1; i < strlen(label); i++) {
        if (!isalnum((unsigned char)label[i]) && label[i] != '_') return false;
    }
    return true;
}

// Function to read an entire file into a string buffer
char* readFileToString(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Failed to open file");
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *buffer = malloc(length + 1);
    if (!buffer) {
        perror("Failed to allocate memory");
        fclose(file);
        return NULL;
    }

    fread(buffer, 1, length, file);
    buffer[length] = '\0'; // Null-terminate the string
    fclose(file);
    return buffer;
}
