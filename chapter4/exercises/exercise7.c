#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

void deblank( char string[] );

int main()
{
    char str[] = "\t    \n    \t";
    deblank(str);
    printf("%s\n", str);
}

void deblank( char string[] )
{
    int i, j;

    int blank_added = FALSE;

    for (i = 0, j = 0; string[i] != 0; i++) {
        if (string[i] == ' ' || string[i] == '\t' || string[i] == '\n') {
            if ( !(blank_added) ) {
                string[j] = ' ';
                blank_added = TRUE;
                j++;
            }
        } else {
            string[j] = string[i];
            blank_added = FALSE;
            j++;
        }
    }

    string[j] = '\0';
}

