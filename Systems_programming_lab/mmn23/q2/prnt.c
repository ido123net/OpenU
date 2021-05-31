#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    FILE *fp;
    void filecopy(FILE *, FILE *);
    char filename[100];

    strcpy(filename, argv[0]);
    strcat(filename, ".c");
    
    if (argc == 1) /* no args; copy standart input */
        if ((fp = fopen(filename, "r")) == NULL)
        {
            printf("program: can't open %s\n", *argv);
            return 1;
        }
        else
        {
            filecopy(fp, stdout);
            fclose(fp);
        }
    else /* if args; acts like Cat command in Linux */
        while (--argc > 0)
            if ((fp = fopen(*++argv, "r")) == NULL)
            {
                printf("program: can't open %s\n", *argv);
                return 1;
            }
            else
            {
                filecopy(fp, stdout);
                fclose(fp);
            }
    return 0;
}

/* filecopy: copy file ifp to file ofp from page 162 in "THE C PROGRAMMING LANGUAGE" book */
void filecopy(FILE *ifp, FILE *ofp)
{
    int c;

    while ((c = getc(ifp)) != EOF)
        putc(c, ofp);
}