#include <stdio.h>

#define SIZE 4

void print_bit_array(char bit_array[], unsigned int size);
void set_bit( char bit_array[], unsigned bit_number );
void clear_bit( char bit_array[], unsigned bit_number );
void assign_bit( char bit_array[], unsigned bit_number, int value );
int test_bit( char bit_array[], unsigned bit_numlber );

int main(void)
{
    char bit_array[SIZE];
    
    set_bit(bit_array, 3);
    set_bit(bit_array, 9);
    set_bit(bit_array, 24);
    print_bit_array(bit_array, SIZE);

    clear_bit(bit_array, 9);
    clear_bit(bit_array, 3);
    print_bit_array(bit_array, SIZE);

    assign_bit(bit_array, 3, 1);
    assign_bit(bit_array, 30, 1);
    assign_bit(bit_array, 24, 0);
    print_bit_array(bit_array, SIZE);
}


// Function prints char array bit by bit.
void print_bit_array(char bit_array[], unsigned int size)
{
    for (int i = 0; i < size * 8; i++) {
        if (i % 8 == 0)
            putchar('\n');
        test_bit(bit_array, i)
            ? putchar('1')
            : putchar('0');
    }
    printf("\n-------------\n");
}

// The function sets the specified bit to one.
void set_bit( char bit_array[], unsigned bit_number )
{
    bit_array[bit_number / 8] |= 1 << bit_number % 8;
}

// The function clears the specified bit.
void clear_bit( char bit_array[], unsigned bit_number )
{
    bit_array[bit_number / 8] &= ~ (1 << bit_number % 8);
}

// The function sets the bit to zero if the value is zero, otherwise it sets the bit to one.
void assign_bit( char bit_array[], unsigned bit_number, int value )
{
    value 
        ? (bit_array[bit_number / 8] |= 1 << bit_number % 8)
        : (bit_array[bit_number / 8] &= ~ (1 << bit_number % 8));
}

// The function returns true if the specified bit is nonzero, else false.
int test_bit( char bit_array[], unsigned bit_number )
{
    return bit_array[bit_number / 8] & 1 << (bit_number % 8);
}

