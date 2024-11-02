#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>

// Function to trim whitespace from both ends of a string
void trimWhitespace(char *str);

// Function to convert a string to lowercase
void toLowerCase(char *str);

// Function to check if a string is a valid label
bool isValidLabel(const char *label);

// Function to read an entire file into a string buffer
char* readFileToString(const char *filename);

#endif // UTILS_H
