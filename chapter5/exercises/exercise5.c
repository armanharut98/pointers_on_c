#include <stdio.h>

int store_bit_field( int original_value, int value_to_store, unsigned starting_bit, unsigned ending_bit );
void print_bits( int value );

int main(void)
{
    printf("%d\n", store_bit_field(65535, 291, 13, 9));
}

void print_bits(int value)
{
    unsigned int maxPow = 1 << (sizeof(int) * 8) - 1;
    while (maxPow) {
        printf("%d", value & maxPow ? 1 : 0);
        maxPow >>= 1;
    }
    printf("\n");
}

/*
 *  The function that will store a given value into specified bit positions of an integer.
 *  Assume that the bits in an integer are numbered from right to left. Thus, the
 *  starting bit position may not be less than the ending bit position.
*/
int store_bit_field( int original_value, int value_to_store, unsigned starting_bit, unsigned ending_bit )
{
    unsigned int mask = ~0;

    int i;
    for (i = sizeof(int) * 4; i >= 0; i--) {
        if (i <= starting_bit && i >= ending_bit) {
            mask &= ~(1 << i);
        }
    }

    mask |= (value_to_store << ending_bit);
    mask &= original_value;

    return mask;
}

