/*
** Copute the 1995 U.S. federal income tax for a single taxpayer.
*/

#include <stdio.h>
#include <float.h>

double single_tax(double income);

int main(void)
{
    printf("%f\n", single_tax(257000));
    printf("%f\n", single_tax(150000));
    printf("%f\n", single_tax(75000));
    printf("%f\n", single_tax(40000));
    printf("%f\n", single_tax(15000));

    return 0;
}

double single_tax(double income)
{
    static double income_limits[] = { 0, 23350, 56550, 117950, 256500, DBL_MAX };
    static double base_tax[] = { 0, 3502.50, 12798.50, 31832.50, 81710.50 };
    static double percentage[] = { 0.15, 0.28, 0.31, 0.36, 0.398 };

    int i;
    for (i = 0; income >= income_limits[i]; i++)
        ;
    i--;

    return base_tax[i] + percentage[i] * (income - income_limits[i]);
}

