#include <stdio.h>
#include <ctype.h>
#define ACTIVE 1
#define INACTIVE -1

int quate = INACTIVE;
int sentence_start = ACTIVE;
int charManipuletion(int c);

/* A program that receives a text, and manipulates it according to the terms of the question. */
int main()
{
    printf("Enter a text to manipulate:\n");
    int c;
    while ((c = getchar()) != EOF)
    {
        if (isdigit(c))
        {
            continue;
        }
        c = charManipuletion(c);
        putchar(c);
    }

    return 0;
}

/* char manipulation according to the terms of the question. */
int charManipuletion(int c)
{
    /* Returns spaces as is. */
    if (isspace(c))
    {
        return c;
    }
    switch (c)
    {
    case '"': /* Beginning\Ending of quote. */
        quate *= -1; /* flips the state of apostrophes */
        break;
    case '.':
        sentence_start = (quate == INACTIVE)? ACTIVE : INACTIVE; /* flips the state of sentence to active if not in quote */
        return c;
    default:
        switch (quate)
        {
        case ACTIVE: /* Inside a quote */
            c = isalpha(c)? toupper(c) : c; /* All letters inside a quote are uppercase*/
            break;
        case INACTIVE:
            if (isalpha(c))
            {
                c = (sentence_start == ACTIVE)? toupper(c) : tolower(c);
            }
            sentence_start = INACTIVE;
            break;
        }
        break;
    }
    sentence_start = INACTIVE;
    return c;
}