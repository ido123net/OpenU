#define SET_SIZE 128
#define BIT_SIZE 8
#define SIZE (BIT_SIZE * sizeof(unsigned short int))

enum
{
    UNION,
    INTERSECT,
    SUB,
    SYMDIFF
};

typedef struct arr *Set;

typedef struct arr
{
    unsigned short int arr[SET_SIZE / SIZE];
}arr;

void add_to_set(Set *set, unsigned short int num);

void print_set(Set set);

Set apply_set_func(Set setA, Set setB, int type);

Set init_set();
