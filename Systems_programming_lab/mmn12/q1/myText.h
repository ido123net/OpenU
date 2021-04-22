#include <stdlib.h>
#include <stdio.h>
#define size 60
typedef enum
{
    buffer,
    linkedList
} data_struct;

typedef struct node *ptr;

typedef struct node
{
    int len;
    char line[size + 1];
    ptr next;
} node;

typedef struct
{
    char *text;
    int len;
} array;

ptr createNode();
array *initArray();
int readText(data_struct type, void *p);
int printText(data_struct type, void *p);
int add_c_list(ptr head, char c);
int add_c_arr(array *arr, char c);
int print_list(ptr head);
int print_arr(array *arr);