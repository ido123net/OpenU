#include <stdlib.h>
#include <stdio.h>
#define size 60

typedef enum
{
    BUFFER,
    LINKEDLIST
} data_struct;

typedef struct node *ptr;

typedef struct node
{
    int len;
    char line[size + 1];
    ptr next;
    ptr prev;
} node;

typedef struct LinkedList
{
    ptr head;
    ptr tail;
}LinkedList;


typedef struct
{
    char *text;
    int len;
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