CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Werror -O0 -g
BUILD = build

APP = hello_world
TEST = test_hello

APP_SRCS = src/main.c src/hello/hello.c
TEST_SRCS = tests/test_hello.c src/hello/hello.c

all: $(APP)

$(APP): $(APP_SRCS)
	$(CC) $(CFLAGS) $^ -o $@

$(TEST): $(TEST_SRCS)
	$(CC) $(CFLAGS) $^ -o $@

test: $(TEST)
	./$(TEST)

clean:
	rm -f $(APP) $(TEST)
