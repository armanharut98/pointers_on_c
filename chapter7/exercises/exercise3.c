#include <stdio.h>

int char_to_int(char c);
int ascii_to_integer( char *string );

int main(void)
{
    char c[4] = {'4', '0', '0'};
    printf("%d\n", ascii_to_integer(c));
}

int ascii_to_integer( char *string )
{
    int value = 0;

    while (*string >= '0' && *string <= '9') {
        value *= 10;
        value += *string++ - '0';
    }

    if (*string != '\0') {
        value = 0;
    }

    return value;
}

