#include <stdlib.h>
#include <stdio.h>
#define size 60 /* one more for EOF */

typedef enum /* types of Data Structure */
{
    BUFFER = 1,
    LINKEDLIST = 2
} data_struct;

typedef struct node *ptr; /* pointer to node */

typedef struct node /* node in doubly Linked List */
{
    int len;
    char line[size + 1];
    ptr next;
    ptr prev;
} node;

typedef struct LinkedList /* "Linked List" Data Structure */
{
    ptr head; /* pointer to head of list */
    ptr tail; /* pointer to end of list */
} LinkedList;

typedef struct /* "Buffer" Data Structure */
{
    char *text; /* pointer to the text */
    int len;    /* length of text */
} Buffer;

LinkedList *initList();
Buffer *initBuffer();
int readText(int type, void *p);
int printText(int type, void *p);
int add_c_list(LinkedList *list, char c);
int add_c_buf(Buffer *arr, char c);
int print_list(LinkedList *list);
int print_arr(Buffer *arr);
int free_arr(Buffer *arr);
int free_list(LinkedList *list);