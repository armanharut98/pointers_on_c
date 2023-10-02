#include <stdio.h>

#define size 1000

#define true 1
#define false 0

int main(void)
{
    int nums[size];
    for (int i = 0; i < size; i++) {
        if (i == 0 || i == 1) 
            nums[i] = false;
        else
            nums[i] = true;
    }

    for (int i = 2, step = 2; i < size; i++, step++) {
        for (int j = i + step; j < size; j += step) {
            nums[j] = false;
        }
    }

    int counter = 0;
    for (int i = 0; i < size; i++) {
        if (nums[i]) {
            printf("%d ", i);
            counter++;
        }
    }

    printf("\nOverall there are %d prime numbers.\n", counter);
    
    return 0;
}
