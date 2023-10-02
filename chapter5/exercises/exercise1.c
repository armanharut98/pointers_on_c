/*
 *  The program that reads characters from the standard input and writes them to
 *  the standard output. All characters should be written exactly as they were read
 *  except that uppercase letters should be converted to lowercase.
*/

#include <stdio.h>

int main(void)
{
    int c;

    while ((c = getchar()) != EOF) {
        if (c >= 'A' && c <= 'Z')
            c += 32;

        putchar(c);
    }

    return 0;
}
