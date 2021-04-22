#include "myText.h"

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

int add_c_list(ptr head, char c)
{
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

int print_node(ptr p)
{
    if (!p)
    {
        return 1;
    }
    putchar('\n');
    puts((p->line));
    return 0;
}

int print_list(ptr head)
{
    ptr p = head;
    while (print_node(p) == 0)
    {
        p = p->next;
    }
    return 0;
}

int free_list(ptr head)
{
    ptr tmp;
    if (head != NULL)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
    return 0;
}