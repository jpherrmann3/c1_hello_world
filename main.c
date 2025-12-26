#include <stdio.h>
#include "hello.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <name>\n", argv[0]);
        return 1;
    }

    for (size_t i = 1; i < (size_t)argc; i++)
    {
        say_hello(argv[i]);
    }

    if (argc > 2) {
        say_group_hello((const char **)&argv[1], (size_t)(argc - 1));
    }

    return 0;
}