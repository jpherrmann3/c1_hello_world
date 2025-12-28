#ifndef HELLO_H
#define HELLO_H

/**
 * Builds a greeting string for one or more names.
 *
 * The return string has the form:
 * "Hello, name1, name2, ..., nameN!\n"
 * Memory for the string is dynamically allocated using malloc.
 *
 * @param names
 *     An array of pointers to null-terminated strings representing names.
 *     Each string must remain valid for the duration of the call
 *
 * @param count
 *     The number of elements in the names array.
 *     Must be greater than zero.
 *
 * @return
 *     On success, returns a pointer to the newly allocated, null-terminated
 *     string containing the greeting.
 *
 *     On failure (e.g., memory allocation failure), returns NULL.
 *
 * @ownership
 *     The caller owns the returned pointer and is responsible for calling
 *     free() on it when it is no longer needed.
 */
char *say_group_hello(const char **names, size_t count);

#endif