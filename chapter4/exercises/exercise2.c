#include <stdio.h>

#define TRUE 1
#define FALSE 0

int main()
{
    for (int i = 2; i <= 200; i++) {
        int isPrime = TRUE;

        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                isPrime = FALSE;
                break;
            }
        }

        if (isPrime)
            printf("%d ", i);
    }
    printf("\n");
}
