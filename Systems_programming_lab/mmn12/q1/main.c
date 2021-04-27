
#include "data.h"

int welcome();
void init_data_struct(int type, void **p);
void free_data(int type, void *p);

int main()
{
    void *p = NULL;
    int type = welcome();
    init_data_struct(type, &p);
    readText(type, p);
    printf("Your text in %d char per line:\n", size);
    printText(type, p);
    free_data(type, p);

    return 0;
}

int welcome()
{
    int type;
    printf("select how you want to save your data:\n");
    printf("Buffer (%d)\n", BUFFER);
    printf("Linked list (%d)\n", LINKEDLIST);
    printf("Select an option (%d \\ %d): ", BUFFER, LINKEDLIST);
    scanf("%d", &type);
    if (type != LINKEDLIST && type != BUFFER)
    {
        printf("You must choose one of the two options %d or %d\n", BUFFER, LINKEDLIST);
        return welcome();
    }
    printf("Enter your text:\n");
    return type;
}

void init_data_struct(int type, void **p)
{
    switch (type)
    {
    case BUFFER:
        printf("\tInitializing \"buffer\" data structure\n");
        *p = (Buffer *)initBuffer();
        break;

    case LINKEDLIST:
        printf("\tInitializing \"linkedList\" data structure\n");
        *p = (LinkedList *)initList();
        break;

    default:
        break;
    }
}

void free_data(int type, void *p)
{
    switch (type)
    {
    case BUFFER:
        free_arr(p);
        break;

    case LINKEDLIST:
        free_list(p);
        break;

    default:
        break;
    }
}