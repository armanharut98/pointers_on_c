#include <stdio.h>

void written_amount( unsigned int amount, char *buffer ); 

int main(void)
{
    char *buffer[100];
    int n = 16312;

    written_amount(n, buffer);

    printf("%s\n", buffer);

    return 0;
}

void written_amount( unsigned int amount, char *buffer )
{

}

// 16,312,334
// find the number of digits
// select the last 'group' (16,312,334 -> 16)
// print SIXTEEN then count how many digits are left (312,334 -> 6)
// use a static variable to print THOUSAND if 3 digits left, MILLION if 6 digits left, BILLION if 9 digits left etc...
