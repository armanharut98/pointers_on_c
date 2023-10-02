#include <stdio.h>

int gcd(int m, int n);

int main(void)
{
    int m;
    int n;

    printf("first argument = ");
    scanf("%d", &m);

    printf("first argument = ");
    scanf("%d", &n);

    printf("%d\n", gcd(m, n));

    return 0;
}

int gcd(int m, int n)
{
    if (m <= 0 || n <= 0) {
        return 0;
    } else if (m % n == 0) {
        return n;
    } else {
        return gcd(n, m % n);
    }
}
