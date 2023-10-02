#include <stdio.h>
#include <string.h>

char *find_char(char const *source, char const *chars);

int main(void)
{
    char *source = "ABCDEFG";
    char *chars = "XRCQEF";
    printf("find_char result: %s\n", find_char(source, chars));
    printf("strpbrk result: %s\n", strpbrk(source, chars));
    return 0;
}

char *find_char(char const *source, char const *chars)
{
    if (source == NULL || chars == NULL)
    {
        return NULL;
    }

    char const *s = source;
    while (*s != '\0') {
        char const *c = chars;
        while (*c != '\0') {
            if (*s == *c)
                return s;
            else
                c++;
        }
        s++;
    }
    return NULL;
}

