#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0


int main()
{
    char prev[128];
    char curr[128];

    int line_printed;

    while (gets(curr)) {
        if ( strcmp(curr, prev) ) {
            strcpy(prev, curr);
            line_printed = FALSE;
        } else {
            if ( !(line_printed) ) {
                printf("%s\n", curr);
                line_printed = TRUE;
            }
        }
    }

    return EXIT_SUCCESS;
}
