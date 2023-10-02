/*
** This program reads C source code from standard input and ensures that the braces are paired correctly.
*/

#include <stdio.h>
#include <stdlib.h>

#define IN 1    /* inside a comment, string literal, or character constant */
#define OUT 0   /* outside a comment, string literal, or character constant */

int main(void)
{
    int ch;

    int brace_tracker = 0;
    int comment_tracker = 0;
    int char_tracker = 0;
    int str_tracker= 0;


    while ((ch = getchar()) != EOF) {
        if (ch == '\"') {
            if (str_tracker == 0)
                str_tracker += 1;
            else
                str_tracker -= 1;
        }

        if (ch == '\'') {
            if (char_tracker == 0)
                char_tracker += 1;
            else
                char_tracker -= 1;
        }

        // TODO: handle comments

        if (char_tracker == 0 && str_tracker == 0) {
            if (ch == '{')
                brace_tracker += 1;
            if (ch == '}') {
                if (brace_tracker != 0)
                    brace_tracker -= 1;
            }
        }
    }

    if (brace_tracker == 0)
        puts("No errors found!");
    else
        puts("Braces are not paired correctly.");

    return EXIT_SUCCESS;
}

