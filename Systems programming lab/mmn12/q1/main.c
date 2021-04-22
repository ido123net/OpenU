#include "myText.h"

int main()
{
    void *p;
    data_struct type = 0;
    switch (type)
    {
    case buffer:
        p = (array*)initArray();
        break;

    case linkedList:
        p = (ptr)createNode();
        break;
    
    default:
        break;
    }
    readText(type, p);
    printText(type, p);
    

    return 0;
}
