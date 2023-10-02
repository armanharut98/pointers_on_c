#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c;

    printf("Enter the side lengths: ");
    scanf("%d %d %d", &a, &b, &c);

    if (a <= 0 || b <= 0 || c <= 0) {
        printf("Triangle side can't have length that's less than or equal to zero.\n");
        exit(EXIT_FAILURE);
    }

    if (a == b && b == c)
        printf("equilateral\n");
    else if (a == b || a == c || b == c)
        printf("isosceles\n");
    else
        printf("scalene\n");

    return EXIT_SUCCESS;
}

