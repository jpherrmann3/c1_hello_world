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

void say_group_hello(const char **names, size_t count) {
    // 1. Compute total length
    // each name + ", " or "!\n" for the last one + "Hello, " + '\0'
    size_t total_length = strlen("Hello, ") + strlen("!\n") + 1; // for "Hello, "!\n" and null terminator
    for (size_t i = 0; i < count; i++) {
        total_length += strlen(names[i]);
        if (i < count - 1) {
            total_length += 2; // for ", "
        }
    }
    // 2. Allocate memory
    char *greeting = malloc(total_length);
    if (greeting == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    // 3. Build the string
    strcpy(greeting, "Hello, ");
    for (size_t i = 0; i < count; i++) {
        strcat(greeting, names[i]);
        if (i < count - 1) {
            strcat(greeting, ", ");
        }
    }
    strcat(greeting, "!\n");
    // 4. Print the greeting
    printf("%s", greeting);
    // 5. Free the allocated memory
    free(greeting);
}