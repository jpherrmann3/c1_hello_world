#include <stdio.h>
#include <stdlib.h>    // malloc, free
#include <string.h>    // strlen, strcpy, strcat
#include "hello.h"

void say_hello(const char *name) {
    // 1. Compute length: "Hello, " + name + "!\n" + '\0'
    size_t length = strlen("Hello, ") + strlen(name) + strlen("!\n") + 1;

    // 2. Allocate memory
    char *greeting = malloc(length);
    if (greeting == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    // 3. Build the string
    strcpy(greeting, "Hello, ");
    strcat(greeting, name);
    strcat(greeting, "!\n");

    // 4. Print the greeting
    printf("%s", greeting);

    // 5. Free the allocated memory
    free(greeting);
}