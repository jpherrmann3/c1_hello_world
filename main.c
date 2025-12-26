#include <stdio.h>
#include "hello.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <name>\n", argv[0]);
        return 1;
    }

    say_hello(argv[1]);
    return 0;
}