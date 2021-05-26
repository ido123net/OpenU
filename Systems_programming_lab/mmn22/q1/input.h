#define NUM_FUNC 7
#define NUM_SET 6
#define TERMINATOR -1
#define NAI -2 /* not an Integer */
#define OOR -3 /* out of range */
#define FALSE 0
#define TRUE 1
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "set.h"

void welcome();

int run_line();