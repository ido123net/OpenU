/**
 * AUTHOR: Ido Frenkel
 * ID: 205419559
 * The Program gets input from standard input,
 * storing it in selected Data Structure,
 * then prints the text stored in memory to standard output.
 * * implement the Linked List as doubly for, better time complexity
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

    printf("Enter your text:\n");

    readText(type, p); /* reads the text provided */

    printf("Your text in %d char per line:\n", size);

    printText(type, p); /* prints the text provided */

    free_data(type, p); /* freeing the Data Structure */

    return 0;
}

int welcome() /* welcome instructions */
{
    int type; /* type of Data Structure */
    int tmp;
    printf("select how you want to save your data:\n");
    printf("For Buffer => (%d)", BUFFER);
    printf("\tFor Linked list => (%d)\n", LINKEDLIST);
    printf("Select an option (%d \\ %d): ", BUFFER, LINKEDLIST);
    if (scanf("%d", &type) != 1 || (type != BUFFER && type != LINKEDLIST))
    {
        while ((tmp = getchar()) != EOF && tmp != '\n') /* clear the buffer for input */
            ;
        if (tmp == EOF)
        {
            printf("\nFATAL: you can't enter the \"EOF\" as input!");
            exit(EXIT_FAILURE);
        }
        printf("\nERROR: You must choose one of the two options (%d or %d)\n\n", BUFFER, LINKEDLIST);
        return welcome();
    }
    return type;
}

void init_data_struct(int type, void **p) /* initialize the pointer for the Data Structure */
{
    switch (type)
    {
    case BUFFER:
        printf("INFO: Initializing \"buffer\" data structure\n");
        *p = (Buffer *)initBuffer();
        break;

    case LINKEDLIST:
        printf("INFO: Initializing \"linkedList\" data structure\n");
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