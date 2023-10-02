/*
** This program reads lines from input and prints them to the output. The lines are preceeded by their line number.
** The length of the line does not matter, since the program reads the input character by character instead of line by line.
*/

#include <stdio.h>
#include <stdlib.h>

#define IN 1    /* inside a line */
#define OUT 0   /* outside a line */

int main()
{
    int line_num = 1;
    int status = OUT;
    int ch;

    while ((ch = getchar()) != EOF) {
        if (status == OUT) {
            printf("%d: ", line_num);
            status = IN;
        }
        if (ch == '\n') {
            line_num += 1;
            status = OUT;
        }

        printf("%c", ch);
    }
    
    return EXIT_SUCCESS;
}

