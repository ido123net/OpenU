/**
 * AUTHOR: Ido Frenkel.
 * ID: 205419559.
 * PROGRAM: The software performs basic operations on sets in the range 0-127.
 */
#include "input.h"

Set SETA, SETB, SETC, SETD, SETE, SETF;

/* initializing sets */
void init()
{
    SETA = init_set();
    SETB = init_set();
    SETC = init_set();
    SETD = init_set();
    SETE = init_set();
    SETF = init_set();
}

int main(int argc, char const *argv[])
{
    int run;
    welcome(); /* prints welcome message */
    init();
    do
    {
        run = run_line(); /* read one line from user */
    } while (run != STOP); /* continue until stop occurs */
    return 0;
}