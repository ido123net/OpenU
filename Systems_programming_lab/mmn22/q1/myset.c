#include <stdio.h>
#include "set.h"

int main(int argc, char const *argv[])
{
    Set SETA = init_set();
    Set SETB = init_set();
    Set SETC = init_set();
    add_to_set(SETA, 0);
    add_to_set(SETA, 1);
    add_to_set(SETA, 2);
    add_to_set(SETB, 2);
    add_to_set(SETB, 3);
    add_to_set(SETB, 4);
    add_to_set(SETC, 6);
    print_set(SETA);
    print_set(SETB);
    print_set(SETC);
    SETC = union_set(SETA, SETB);
    print_set(SETC);
    SETC = intersect_set(SETA, SETB);
    print_set(SETC);
    SETC = sub_set(SETA, SETB);
    print_set(SETC);
    SETC = symdiff_set(SETA, SETB);
    print_set(SETC);
    return 0;
}
