#include <stdio.h>

unsigned int reverse_bits(unsigned int value);

int main(void)
{
    unsigned int n = 25;
    printf("%u\n", reverse_bits(n));
    return 0;
}

/*
 *  This function returns the number constructed by reversing the order of the bits in
 *  value from left to right. For example, on a 32-bit machine the number 25 contains
 *  these bits:
 *      00000000000000000000000000011001
 *  The function should return 2,550,136,832, which is composed of these bits:
 *      10011000000000000000000000000000
 *  Try to write your function so that it does not depend on the integer size of your
 *  machine.
*/
unsigned int reverse_bits(unsigned int value)
{
    unsigned int result = 0;
    unsigned int int_size = 8 * sizeof(int);

    for (int i = 0; i < int_size; i++) {
        if (value & 1 << i)
            result |= 1 << (int_size - i - 1);
    }

    return result;
}

/*
** Reverse the order of the bits in an unsigned integer value. (Book Answer)
*/
unsigned int reverse_bits_v2( unsigned int value )
{
    unsigned int answer;
    unsigned int i;
    answer = 0;
    /*
    ** Keep going as long as i is nonzero. This makes the loop
    ** independent of the machine's word size, hence portable.
    */
    for( i = 1; i != 0; i <<= 1 ){
        /*
        ** Shift the old answer to make room for the next
        ** bit; then OR in a 1 if the value's last bit is
        ** set; then shift the value to its next bit.
        */
        answer <<= 1;
        if( value & 1 )
            answer |= 1;
        value >>= 1;
    }
    return answer;
}

