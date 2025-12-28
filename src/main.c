#include <stdio.h>
#include <stdlib.h>
#include "hello/hello.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <name>\n", argv[0]);
        return 1;
    }

    const char **names = (const char **)(argv + 1);
    char *greeting = say_group_hello(names, (size_t)(argc - 1));

    if (!greeting) {
        fprintf(stderr, "Failed to create greeting message\n");
        return 1;
    }

    printf("%s", greeting);

    free(greeting);

    return 0;
}