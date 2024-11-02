#include <stdio.h>
#include "error_handling.h"

// Function to handle errors and print messages
void handleError(const char *message, const char *context) {
    fprintf(stderr, "Error: %s - %s\n", message, context);
}
