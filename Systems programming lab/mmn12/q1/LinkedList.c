#include <stdlib.h>
#include "myText.h"

typedef struct node *ptr;

typedef struct node
{
    int len;
    char line[size];
    ptr next;
} node;

ptr createNode()
{
    ptr new_node = (ptr)malloc(sizeof(node)); /* allocate memory using malloc() */
    if (new_node)
    {
        new_node->next = NULL; /* make next point to NULL */
        new_node->len = 0;     /* init the length to 0 */
    }
    return new_node; /* return the new ptr */
}

int add_c(ptr head, char c)
{
    // ptr new_node;            /* declare two nodes temp and p */
    // new_node = createNode(); /* createNode will return a new node with data = value and next pointing to NULL. */
    // if (!new_node)
    // {
    //     printf("Out of Memory Space\n");
    //     return -1;
    // }
    // srtcpy(new_node->line, value); /* add element's value to data part of node */
    ptr tmp = head;
    while (tmp->len >= size && tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    if (tmp->len < size)
    {
        tmp->line[(tmp->len)++] = c;
    }
    else
    {
        ptr new_node = createNode();
        if (!new_node)
        {
            return -1;
        }
        tmp->next = new_node;
        new_node->line[(new_node->len)++] = c;
    }
    return 0;
}