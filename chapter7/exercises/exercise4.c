#include <stdio.h>
#include <stdarg.h>

int max_list(int count, ...);

int main(void)
{
    printf("%d\n", max_list(7, 3, 5, 1, 2, 3, 7, -1));
    printf("%d\n", max_list(8, 2, 3, 5, 10, 2, 3, 7, -1));
    printf("%d\n", max_list(6, 69, 1, 2, 3, 7, -1));

    return 0;
}

int max_list(int n_count, ...)
{
    va_list args;
    va_start(args, n_count);

    int max = va_arg(args, int);
    int i;
    while (( i = va_arg(args, int)) >= 0) {
        if (i > max) {
            max = i;
        }
    }

    va_end(args);

    return max;
}

