#define SET_SIZE 128
#define BIT_SIZE 8
#define SIZE (BIT_SIZE * sizeof(unsigned short int))

typedef struct arr *Set;

typedef struct arr
{
    unsigned short int arr[SET_SIZE / SIZE];
}arr;

void add_to_set(Set set, unsigned short int num);

void print_set(Set set);

Set union_set(Set setA, Set setB);

Set intersect_set(Set setA, Set setB);

Set sub_set(Set setA, Set setB);

Set symdiff_set(Set setA, Set setB);

Set init_set();
