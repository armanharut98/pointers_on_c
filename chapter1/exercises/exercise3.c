/*
** This program reads characters from the input and uses them to calculate a checksum, which then is printed along with the characters.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ch;
    signed char checksum = -1;

    while ((ch = getchar()) != EOF) {
        checksum += ch;
        printf("%c", ch);
    }

    printf("%d\n", checksum);

    return EXIT_SUCCESS;
}

