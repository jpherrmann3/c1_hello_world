#include <stdio.h>
#include "hello.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <name>\n", argv[0]);
        return 1;
    }

    if (argc == 2) {
        say_hello(argv[1]);
    } else {
        const char **names = (const char **)(argv + 1);
        say_group_hello(names, (size_t)(argc - 1));
    }

    return 0;
}