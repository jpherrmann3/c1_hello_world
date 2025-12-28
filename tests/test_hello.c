#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "hello/hello.h"

void test_sing_name() {
    const char *names[] = {"James"};

    char *result = say_group_hello(names, 1);
    assert(result != NULL);
    assert(strcmp(result, "Hello, James!\n") == 0);

    free(result);
}

void test_multiple_names() {
    const char *names[] = {"James", "Ana", "Rori"};

    char *result = say_group_hello(names, 3);
    assert(result != NULL);

    assert(strcmp(result, "Hello, James, Ana, Rori!\n") == 0);

    free(result);
}

void test_empty_names() {
    char *result = say_group_hello(NULL, 0);
    assert(result == NULL);
}

int main(void) {
    test_sing_name();
    test_multiple_names();
    test_empty_names();

    printf("All tests passed!\n");
    return 0;
}