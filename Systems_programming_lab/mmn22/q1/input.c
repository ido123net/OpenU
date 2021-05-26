#include "input.h"

extern Set SETA, SETB, SETC, SETD, SETE, SETF; /* defined in main program */

static char *func_names[NUM_FUNC] = {"read_set",
                                     "print_set",
                                     "union_set",
                                     "intersect_set",
                                     "sub_set",
                                     "symdiff_set",
                                     "stop"};

static char *set_names[NUM_SET] = {"SETA",
                                   "SETB",
                                   "SETC",
                                   "SETD",
                                   "SETE",
                                   "SETF"};

/* welcome message */
void welcome()
{
    printf("The software performs basic operations on sets in the range 0-127.\n");
    printf("You can use the following sets:\n");
    size_t i;
    for (i = 0; i < NUM_SET; i++)
    {
        printf("%s", set_names[i]);
        if (i < (NUM_SET - 1))
            putchar('\t');
        else
            putchar('\n');
    }
    printf("For inserting numbers into a set:\n");
    printf("Note, it is mandatory to end the list of numbers with the terminator number = %d\n", TERMINATOR);
    printf("\t%s <SET>, <List of values ​​separated by commas in range [0, 127]> , %d\n", func_names[READ_SET], TERMINATOR);
    printf("For set printing:\n");
    printf("\t%s <SET>\n", func_names[PRINT_SET]);
    printf("For running functions on sets:\n");
    printf("\t<func> <SETA>,<SETB>,<SETC>\n");
    printf("When func is one of the following functions:\n");
    printf("%s  %s  %s  %s\n", func_names[UNION_SET], func_names[INTERSECT_SET], func_names[SUB_SET], func_names[SYMDIFF_SET]);
    printf("The function will be performed between SETA and SETB and the result will be stored in SETC\n");
    printf("To stop the program:\n");
    printf("\t%s <SET>\n", func_names[STOP]);
}

/* returning a pointer to the set with the same name NULL if there is no such set */
static Set *
which_set(char *set)
{
    if (!strcmp(set, "SETA"))
        return &SETA;
    if (!strcmp(set, "SETB"))
        return &SETB;
    if (!strcmp(set, "SETC"))
        return &SETC;
    if (!strcmp(set, "SETD"))
        return &SETD;
    if (!strcmp(set, "SETE"))
        return &SETE;
    if (!strcmp(set, "SETF"))
        return &SETF;

    return NULL;
}

/**
 * returning a pointer to the set with the same name NULL if there is no such set.
 * prints errors.
 */
Set *get_set(char **set)
{
    while (isspace(**set)) /* skip spaces in start of string */
        (*set)++;
    if (!**set) /* if we reach the end of string then there is a missing parameter */
    {
        printf("Missing parameter\n");
        return NULL;
    }
    int i;
    for (i = 0; i < NUM_SET; i++)
    {
        if (strncmp(*set, set_names[i], strlen(set_names[i])) == 0)
        {
            *set += strlen(set_names[i]); /* move pointer to the char after set */
            while (isspace(**set))        /* skip spaces in end of string */
                (*set)++;
            return which_set(set_names[i]);
        }
    }
    printf("Undefined set name\n");
    return NULL;
}

/* returning int that represents the func number in array (func_names). */
int get_func(char **token)
{
    int i;
    for (i = 0; i < NUM_FUNC; i++)
    {
        if (strncmp(*token, func_names[i], strlen(func_names[i])) == 0)
        {
            *token += strlen(func_names[i]); /* move pointer to the char after function */
            while (isspace(**token))         /* skip spaces in end of string */
                (*token)++;
            if (!**token) /* if there isn't text after the function */
                return i;
            else
                printf("Illegal char - %c after command\n", **token);
            return -1;
        }
    }
    printf("Undefined command name\n"); /* command not found */
    return -1;
}

/**
 * return number in range [0, 127] from string.
 * if string is not an integer then returns NAI.
 * if number out of range then returns OOR.
 * if string is "-1" returns the TERMINATOR.
 */
int get_num(char **ptr)
{
    int num = atoi(*ptr);
    while (isspace(**ptr)) /* skip spaces in start of string */
        (*ptr)++;
    if (**ptr == '-') /* can be minus number */
        (*ptr)++;
    while (isdigit(**ptr)) /* skip numbers */
        (*ptr)++;
    while (isspace(**ptr)) /* skip spaces in end of string */
        (*ptr)++;
    if (**ptr) /* if there is more chars in string then is not a number */
        return NAI;
    if ((num < 0 || num >= SET_SIZE) && num != TERMINATOR) /* number out of renge and not the TERMINATOR */
        return OOR;
    return num;
}

/* read the line after the read_set command */
int read(char **token)
{
    char *set = strsep(token, ",");
    if (!*token)
    {
        printf("Missing comma\n");
        return -1;
    }
    Set *setA = get_set(&set); /* get the set to read to */
    if (!setA)                 /* if the string not represent a valid set */
        return -1;

    Set tmp_set = init_set();           /* generates temporary set to read the numbers to */
    char *nums = strsep(token, "\n\0"); /* string with the numbers to read */
    char *snum = strsep(&nums, ",");    /* first number */
    int terminated = FALSE;
    while (*snum && !terminated) /* if there is number to read and not terminated yet */
    {
        int num;
        num = get_num(&snum); /* the number in the string */

        switch (num)
        {
        case TERMINATOR:
            terminated = TRUE;
            break;
        case NAI:
            printf("Invalid set member – not an integer\n");
            return -1;

        case OOR:
            printf("Invalid set member – value out of range\n");
            return -1;

        default:
            add_to_set(&tmp_set, num);
            snum = strsep(&nums, ",\0");
            break;
        }
    }
    if (!terminated) /* not terminated correctly */
    {
        printf("List of set members is not terminated correctly\n");
        return -1;
    }
    if (nums)
    {
        while (isspace(*nums))
            nums++;
        if (*nums)
        {
            printf("Extraneous text after end of terminated integer\n");
            return -1;
        }
    }
    read_set(setA, tmp_set);
    return 0;
}

/* read the line after the print_set command */
int print(char **token)
{
    char *set = strsep(token, "\n\0");
    Set *setA = get_set(&set); /* get the set to print */
    if (!setA)                 /* if the string not represent a valid set */
        return -1;
    while (isspace(*set)) /* skip spaces in end of string */
        set++;
    if (*set)
    {
        printf("Extraneous text after end of command\n");
        return -1;
    }
    print_set(setA);
    return 0;
}

/* read the line after the <func_set> command */
int function(char **token, int func)
{
    char *set = strsep(token, ",\n\0");
    if (!*token)
    {
        printf("Missing comma\n");
        return -1;
    }
    Set *setA = get_set(&set); /* get the 1st set */
    if (!setA)                 /* if the string not represent a valid set */
        return -1;

    set = strsep(token, ",\n\0");
    if (!*token)
    {
        printf("Missing comma\n");
        return -1;
    }
    Set *setB = get_set(&set); /* get the 2nd set */
    if (!setB)                 /* if the string not represent a valid set */
        return -1;

    set = strsep(token, "\n\0");
    Set *setC = get_set(&set); /* get the 3rd set */
    if (!setC)                 /* if the string not represent a valid set */
        return -1;

    while (isspace(*set)) /* skip spaces in end of string */
        set++;
    if (*set)
    {
        printf("Extraneous text after end of command\n");
        return -1;
    }
    apply_set_func(setA, setB, setC, func);
    return 0;
}

int run_line()
{
    char *ptr = NULL;
    char *token = NULL;
    char *line = NULL;
    size_t len = 0;

    getline(&line, &len, stdin); /* gets the input line with '\n' char at the end */
    if (!strchr(line, '\n'))     /* if there is no '\n' char we put it for aesthetic reasons */
        putchar('\n');
    printf("==> %s", line);
    if (!strchr(line, '\n')) /* if there is no '\n' char we put it for aesthetic reasons */
        putchar('\n');
    ptr = strdup(line);                   /* copy the line to another pointer */
    while (isspace(*ptr) && *ptr != '\n') /* skip spaces in start of string */
        ptr++;
    if (*ptr == '\n')
    {
        printf("blank line\n");
        return -1;
    }
    token = strsep(&ptr, " \t\n\0"); /* the command text */
    int func = get_func(&token);   /* int of command */
    if (func == -1)                /* not a valid command */
    {
        return -1;
    }

    switch (func)
    {
    case READ_SET:
        token = strsep(&ptr, "\0"); /* text after command */
        if (!*token)
        {
            printf("Missing parameter\n");
            return -1;
        }
        read(&token);
        break;

    case PRINT_SET:
        token = strsep(&ptr, "\0"); /* text after command */
        if (!*token)
        {
            printf("Missing parameter\n");
            return -1;
        }
        print(&token);
        break;

    case UNION_SET:
    case INTERSECT_SET:
    case SUB_SET:
    case SYMDIFF_SET:
        token = strsep(&ptr, "\0"); /* text after command */
        if (!*token)
        {
            printf("Missing parameter\n");
            return -1;
        }
        function(&token, func);
        break;

    case STOP:
        if (ptr)
            while (isspace(*ptr))
                ptr++;
        if (*ptr) /* invalid text after command */
        {
            printf("Extraneous text after end of command\n");
            return -1;
        }
        return STOP;

    default:
        break;
    }

    free(line);
    if (!token) /* token need to be empty string here if not then we reaced the EOF */
    {
        printf("reached end of file symbol\n");
        return STOP;
    }

    return 1;
}
