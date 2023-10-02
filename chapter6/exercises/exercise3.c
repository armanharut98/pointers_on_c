#include <stdio.h>

void reverse_string(char *string);

int main()
{
    char str1[40] = "Hello, this is FPSRussia again!";
    char str2[40] = "And as always, have a nice day!";

    printf("%s\n", str1);
    reverse_string(str1);
    printf("%s\n", str1);

    printf("%s\n", str2);
    reverse_string(str2);
    printf("%s\n", str2);
}

void reverse_string(char *string)
{
    char *end = string;
    while (*end != '\0')
        end++;
    end--;
    
    char *beg = string;
    while (beg != end) {
        char tmp = *beg;
        *beg++ = *end;
        *end-- = tmp;
    }
}
