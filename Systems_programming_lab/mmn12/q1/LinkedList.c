#include "data.h"

ptr createNode()
{
    ptr new_node = (ptr)malloc(sizeof(node)); /* allocate memory using malloc() */
    if (new_node)
    {
        new_node->next = NULL; /* make next point to NULL */
        new_node->prev = NULL; /* make next point to NULL */
        new_node->len = 0;     /* init the length to 0 */
    }
    return new_node; /* return the new ptr */
}

LinkedList *initList()
{
    ptr p = createNode();
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    list->head = p;
    list->tail = p;
    return list;
}

int addNodeLast(LinkedList *list)
{
    ptr p = createNode();
    if (!p)
    {
        return -1;
    }
    list->tail->next = p;
    p->prev = list->tail;
    list->tail = p;
    return 0;
}

int add_c_list(LinkedList *list, char c)
{
    if (list->tail->len >= size)
    {
        list->tail->line[size] = '\0';
        if(addNodeLast(list) != 0)
        {
            return -1;
        }
    }
    list->tail->line[(list->tail->len)++] = c;
    return 0;
}

int print_node(ptr p)
{
    if (!p)
    {
        return 1;
    }
    printf("%s\n", p->line);
    return 0;
}

int print_list(LinkedList *list)
{
    ptr p = list->head;
    while (print_node(p) == 0)
    {
        p = p->next;
    }
    return 0;
}

int free_list(LinkedList *list)
{
    list->tail = NULL;
    ptr tmp;
    while (list->head != NULL)
    {
        tmp = list->head;
        list->head = list->head->next;
        free(tmp);
    }
    return 0;
}