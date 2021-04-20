#include <stdio.h>
#include "myText.h"

typedef enum {buffer, linkedList} data_struct;

int readText(data_struct s, void *data)
{
    int c;
    char line[size];
    while ((c = getchar()) != EOF)
    {
        switch (s)
        {
        case /* constant-expression */:
            /* code */
            break;
        
        default:
            break;
        }
    }
    
}