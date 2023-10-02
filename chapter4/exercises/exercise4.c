#include <stdio.h>
#include <string.h>

void copy_n( char dst[], char src[], int n );

int main()
{
    char *src = "FPSRussia";
    char dst[12];
    copy_n(dst, src, 3);

    printf("%s\n", dst);
}

void copy_n( char dst[], char src[], int n )
{
    int src_len = strlen(src);

    for (int i = 0; i < n; i++) {
        if (i < src_len) {
            dst[i] = src[i];
        } else {
            dst[i] = '\0';
        }
    }
}
