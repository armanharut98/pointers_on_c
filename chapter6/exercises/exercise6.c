#include <stdio.h>
#include "bit_array_functions.h"

#define lo 1000000
#define hi 1001000
#define size hi

#define true 1
#define false 0

int main(void)
{
    int bit_array_size = (size / 8) + 1;
    char bit_array[bit_array_size];

    for (int i = 0; i < bit_array_size * 8; i++) {
        if (i == 0 || i == 1) {
            clear_bit(bit_array, i);
        } else {
            set_bit(bit_array, i);
        }
    }

    for (int i = 2, step = 2; i < bit_array_size * 8; i++, step++) {
        for (int j = i + step; j < bit_array_size * 8; j += step) {
            clear_bit(bit_array, j);
        }
    }

    int counter = 0;
    for (int i = lo; i < hi; i++) {
        if (test_bit(bit_array, i)) {
            printf("%d ", i);
            counter++;
        }
    }

    printf("\nOverall there are %d prime numbers.\n", counter);

    return 0;
}
