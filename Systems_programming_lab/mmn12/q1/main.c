/*
* name: Ido Frenkel
* Id: 205419559
* The Program gets input from standard input,
* storing it in selected Data Structure,
* then prints the text stored in memory to standard output.
*/

#include "data.h"

int welcome();
void init_data_struct(int type, void **p);
void free_data(int type, void *p);

int main()
{
    void *p = NULL;
    int type = welcome();

    init_data_struct(type, &p); /* pointer for the Data Structure */
    readText(type, p);          /* reads the text provided */

    printf("Your text in %d char per line:\n", size);

    printText(type, p); /* prints the text provided */

    free_data(type, p); /* freeing the Data Structure */

    return 0;
}

int welcome() /* welcome instructions */
{
    int type; /* type of Data Structure */
    printf("select how you want to save your data:\n");
    printf("Buffer (%d)\n", BUFFER);
    printf("Linked list (%d)\n", LINKEDLIST);
    printf("Select an option (%d \\ %d): ", BUFFER, LINKEDLIST);
    scanf("%d", &type);
    if (type != LINKEDLIST && type != BUFFER) /* If the selected type is not supported */
    {
        printf("\nYou must choose one of the two options %d or %d\n", BUFFER, LINKEDLIST);
        return welcome();
    }
    printf("Enter your text:\n");
    return type;
}

void init_data_struct(int type, void **p) /* initialize the pointer for the Data Structure */
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

void free_data(int type, void *p) /* freeing the data */
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