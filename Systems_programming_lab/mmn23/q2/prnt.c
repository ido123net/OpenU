/**
 * AUTHOR: Ido Frenkel.
 * ID: 205419559.
 * PROGRAM: The program prints the file that generated the Execution file.
 *          The program assumes that the file name, is the same as the Execution file name.
 *          If arguments is given to the program, then the program acts like Cat command in linux.
 *          That means that the program prints the value of the files given as arguments.
 */

#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    FILE *fp;
    void filecopy(FILE *, FILE *);
    char filename[100];

    strcpy(filename, argv[0]); /* gets the name of Execution file */
    strcat(filename, ".c");    /* adds ".c" at the end for get the source file */

    if (argc == 1) /* no args; copy standart input */
        if ((fp = fopen(filename, "r")) == NULL)
        {
            printf("program: can't open %s\n", *argv); /* file not opened */
            return 1;
        }
        else
        {
            filecopy(fp, stdout);
            fclose(fp); /* close the file */
        }
    else /* if args; acts like Cat command in Linux */
        while (--argc > 0)
            if ((fp = fopen(*++argv, "r")) == NULL)
            {
                printf("program: can't open %s\n", *argv); /* file not opened */
                return 1;
            }
            else
            {
                filecopy(fp, stdout);
                fclose(fp); /* close the file */
            }
    return 0;
}

/* filecopy: copy file ifp to file ofp; taken from page 162 in "THE C PROGRAMMING LANGUAGE" book */
void filecopy(FILE *ifp, FILE *ofp)
{
    int c;

    while ((c = getc(ifp)) != EOF)
        putc(c, ofp);
}