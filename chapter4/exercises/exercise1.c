#include <stdio.h>

int main()
{
    int n;
    double prev;
    double curr = 1;

    printf("Enter a value: ");
    scanf("%d", &n);
    
    printf("Approximations: %f", curr);

    while (prev != curr) {
        prev = curr;
        curr = (prev + n / prev) / 2;
        printf(" %f", curr);
    }

    printf("\nSquare root = %f\n", curr);
}
