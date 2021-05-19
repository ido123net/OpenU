#include "set.h"

Set SETA, SETB, SETC, SETD, SETE, SETF;

int run_line();

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
    init();
    int run = 1;
    while (run)
    {
        run = run_line();
    }
    return 0;
}