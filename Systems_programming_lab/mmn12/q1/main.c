
#include "myText.h"

int welcome();
void init_data_struct(int type, void **p);
void free_data(int type, void *p);

int main()
{
    void *p = NULL;
    int type = welcome();
    init_data_struct(type, &p);
    readText(type, p);
    printf("\nYour text in %d char per line:\n", size);
    printText(type, p);
    free_data(type, p);

    return 0;
}

int welcome()
{
    int type;
    printf("select how you want to save your data:\n");
    printf("Buffer (%d)\n", buffer);
    printf("Linked list (%d)\n", linkedList);
    printf("Select an option (%d \\ %d): ", buffer, linkedList);
    scanf("%d", &type);
    if (type != linkedList && type != buffer)
    {
        printf("You must choose one of the two options %d or %d\n", buffer, linkedList);
        return welcome();
    }
    printf("Enter your text:\n");
    return type;
}

void init_data_struct(int type, void **p)
{
    switch (type)
    {
    case buffer:
        *p = (array *)initArray();
        break;

    case linkedList:
        *p = (ptr)createNode();
        break;

    default:
        break;
    }
}

void free_data(int type, void *p)
{
    switch (type)
    {
    case buffer:
        free_arr(p);
        break;

    case linkedList:
        free_list(p);
        break;

    default:
        break;
    }
}