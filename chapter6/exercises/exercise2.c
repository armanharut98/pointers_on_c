#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int del_substr( char *str, char const *substr );

int main(void)
{
    char str[30] = "ABCDEFG";
    char substr[4] = "CDE";

    printf("%d: %s\n", del_substr(str, substr), str);

    return 0;
}

int del_substr( char *str, char const *substr )
{
    char *sub = substr;
    char *beg = str;
    while (*beg != '\0') {
        if (*beg == *sub) {
            char *end = beg;
            int substr_present = TRUE;

            while (*sub != '\0')
                if (*sub++ != *end++)
                    substr_present = FALSE;

            if (!substr_present)
                continue;

            while ((*beg++ = *end++) != '\0')
                ;
            
            return 1;
        }
        beg++;
    }
    return 0;
}

