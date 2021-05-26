#define SET_SIZE 128
#define BIT_SIZE 8
#define SIZE (BIT_SIZE * sizeof(unsigned short int))

enum
{
    READ_SET,
    PRINT_SET,
    UNION_SET,
    INTERSECT_SET,
    SUB_SET,
    SYMDIFF_SET,
    STOP
};

typedef struct arr *Set;

typedef struct arr
{
    unsigned short int arr[SET_SIZE / SIZE];
}arr;

void add_to_set(Set *set, unsigned short int num);

void read_set(Set *setA, Set setB);

int print_set(Set *set);

void apply_set_func(Set *setA, Set *setB, Set *setC, int type);

Set init_set();
