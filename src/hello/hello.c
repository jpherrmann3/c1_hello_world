#include <stdio.h>
#include <stdlib.h>    // malloc, free
#include <string.h>    // strlen, strcpy, strcat
#include "hello/hello.h"


char *say_group_hello(const char **names, size_t count) {
    if (count == 0) {
        return NULL;
    }

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

    if (!greeting) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }

    // 3. Build string using a cursor pointer
    char *p = greeting; // cursor pointer

    const char *prefix = "Hello, ";
    while ((*p++ = *prefix++) != '\0');
    p--; // step back to overwrite null terminator
    for (size_t i = 0; i < count; i++) {
        const char *name = names[i];
        while ((*p++ = *name++) != '\0'); // copy name
        p--; // step back to overwrite null terminator
        if (i < count - 1) {
            *p++ = ',';
            *p++ = ' ';
        }
    }
    *p++ = '!';
    *p++ = '\n';
    *p = '\0'; // null terminator

    return greeting;
}