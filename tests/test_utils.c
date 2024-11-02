#include <stdio.h>
#include "utils.h"

void testTrimWhitespace() {
    char str[] = "   Hello, World!   ";
    trimWhitespace(str);
    printf("Trimmed String: '%s'\n", str);
}

void testToLowerCase() {
    char str[] = "Hello, World!";
    toLowerCase(str);
    printf("Lowercase String: '%s'\n", str);
}

void testIsValidLabel() {
    const char *label = "valid_label";
    if (isValidLabel(label)) {
        printf("'%s' is a valid label.\n", label);
    } else {
        printf("'%s' is not a valid label.\n", label);
    }
}

int main() {
    testTrimWhitespace();
    testToLowerCase();
    testIsValidLabel();
    return 0;
}
