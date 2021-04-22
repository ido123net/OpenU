#include <stdio.h>
#include "myText.h"

int main(int argc, char const *argv[])
{
    ptr head;
    int c;
    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
        {
            continue;
        }
        add_c(head, c);
    }

    return 0;
}
