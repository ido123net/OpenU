#include "myText.h"

int main()
{
    void *p;
    int type;
    printf("select how you want to save your data:\n");
    printf("Buffer (%d)\n", buffer);
    printf("Linked list (%d)\n", linkedList);
    printf("Select an option (%d \\ %d): ", buffer, linkedList);
    scanf("%d", &type);
    switch (type)
    {
    case buffer:
        p = (array *)initArray();
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
