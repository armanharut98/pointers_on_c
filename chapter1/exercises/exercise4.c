/*
** This program reads a file line by line. Determines the length of each line and prints the longest one.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

int main()
{
    int len;
    int max = 0;
    char line[MAX];
    char longest[MAX];
    
    while (gets(line) != NULL) {
        len = strlen(line);
        if (len > max) {
            max = len;
            strcpy(longest, line);
        }
    }

    printf("%s\n", longest);

    return EXIT_SUCCESS;
}
