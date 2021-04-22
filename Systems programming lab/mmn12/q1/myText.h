#define size 60

typedef struct node *ptr;

typedef struct node
{
    int len;
    char line[size];
    ptr next;
} node;

int add_c(ptr head, char c);