#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int substr( char dst[], char src[], int start, int len );

int main(void)
{
    char src[] = "FPSRussia";
    char dst[12];

    int len = substr(dst, src, 3, -1);

    printf("%s\n", dst);
    printf("Chars copied: %d\n", len);
}

/*
It should copy the string that begins start characters past the beginning of the
string in src into the array dst. At most len non-NUL characters should be copied
from src. After copying, dst must be NUL-terminated. The function should return
the length of the string stored in dst.
If start specifies a position beyond the end of the string in src, or either start
or len are negative, then dsc should be given the empty string.
*/
int substr( char dst[], char src[], int start, int len )
{
    int src_len = strlen(src);

    if ( start < 0 || len < 0 || start >= src_len ) {
        dst = "";
        return 0;
    }

    int i, j;

    for (i = 0, j = start; j < start + len; i++, j++) {
        if (src[j] == 0)
            break;

        dst[i] = src[j];
    }

    return i;
}

