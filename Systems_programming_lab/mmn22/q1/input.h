#define NUM_FUNC 7

char *func_names[NUM_FUNC] = {"read_set",
                              "print_set",
                              "union_set",
                              "intersect_set",
                              "sub_set",
                              "symdiff_set",
                              "stop"};
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