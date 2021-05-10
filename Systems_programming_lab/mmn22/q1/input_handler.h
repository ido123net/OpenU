#define  _GNU_SOURCE
#define BUFFER_SIZE 128
#include <stdio.h>
#include <string.h>

int handle_input();
char *strtok_single(char *str, char const *delims);