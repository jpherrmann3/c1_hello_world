CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Werror -O0 -g

hello_world: main.o hello.o
	$(CC) $(CFLAGS) main.o hello.o -o hello_world

main.o: main.c hello.h
	$(CC) $(CFLAGS) -c main.c

hello.o: hello.c hello.h
	$(CC) $(CFLAGS) -c hello.c

clean:
	rm -f *.o hello_world test_hello

test: test_hello

test_hello: test_hello.c hello.c hello.h
	$(CC) $(CFLAGS) test_hello.c hello.c -o test_hello
