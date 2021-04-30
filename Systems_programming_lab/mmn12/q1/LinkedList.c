#include "data.h"

ptr createNode()
{
    ptr new_node = (ptr)malloc(sizeof(node)); /* pointer to memory for the new node */
    if (new_node)                             /* if new node created successfully update its values */
    {
        new_node->next = NULL; /* make next pointer to NULL */
        new_node->prev = NULL; /* make prev pointer to NULL */
        new_node->len = 0;     /* init the length to 0 */
    }
    return new_node; /* return the new ptr or NULL if there is no memory */
}

LinkedList *initList() /* initialize LinkedList */
{
    ptr p = createNode();                                        /* initialize node */
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList)); /* pointer to memory for the Linked List */
    list->head = p;                                              /* head points to the first node */
    list->tail = p;                                              /* tail points to the last node */
    return list;                                                 /* the pointer for the Linked List */
}

int addNodeLast(LinkedList *list) /* add new node to the end of the Linked List */
{
    ptr p = createNode(); /* create new node */
    if (!p)               /* no memory for new node */
    {
        return -1;
    }
    list->tail->next = p; /* add new node after tail */
    p->prev = list->tail; /* update the prev of the new node */
    list->tail = p;       /* update the new tail of the list */
    return 0;
}

int add_c_list(LinkedList *list, char c) /* adds char to Linked List */
{
    if (list->tail->len >= size) /* Last node is full */
    {
        list->tail->line[list->tail->len] = '\0'; /* adds the end of string char to the end of line */
        if (addNodeLast(list) != 0)    /* failed to create new node */
        {
            return -1;
        }
    }
    list->tail->line[(list->tail->len)++] = c; /* Add a character to the last node with space for it */
    return 0;
}

int print_node(ptr p) /* printing one node */
{
    if (!p) /* if p is NULL */
    {
        return 1;
    }
    printf("%s\n", p->line); /* print line */
    return 0;                /* printed successfully */
}

int print_list(LinkedList *list) /* printing the entire List */
{
    ptr p = list->head;        /* start of the list */
    while (print_node(p) == 0) /* print node after node until NULL */
    {
        p = p->next; /* gets the next node */
    }
    return 0;
}

int free_list(LinkedList *list) /* free the memory */
{
    ptr tmp;                   /* temporary pointer for the node to free */
    while (list->head != NULL) /* while there is more node to free */
    {
        tmp = list->head;              /* point to the start of the list */
        list->head = list->head->next; /* update the list to start at next node */
        free(tmp);                     /* free the start of the list recursively */
    }
    free(list); /* free the memory saved for data structure */
    return 0;
}