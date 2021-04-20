#include <stdlib.h>
#include "myText.h"

typedef struct node *ptr;

typedef struct node
{
    char line[size];
    ptr next;
} node;

ptr createNode()
{
    ptr new_node = (ptr)malloc(sizeof(node)); /* allocate memory using malloc() */
    if (new_node)
    {
        new_node->next = NULL; /* make next point to NULL */
    }
    return new_node; /* return the new ptr */
}

int push(ptr head, char value[size])
{
    ptr new_node;            /* declare two nodes temp and p */
    new_node = createNode(); /* createNode will return a new node with data = value and next pointing to NULL. */
    if (!new_node)
    {
        printf("Out of Memory Space\n");
        return -1;
    }
    srtcpy(new_node->line, value); /* add element's value to data part of node */
    if (!head)         /* linked list is empty */
    {
        head = new_node;
        return 0;
    }
    ptr tmp = head;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = new_node;
    return 0;
}