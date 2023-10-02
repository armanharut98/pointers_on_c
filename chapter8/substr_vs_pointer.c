#include <stdio.h>
#include <time.h>

void substr()
{
    int arr[1000000];
    for (int i = 0; i < 1000000; i += 1) {
        arr[i] = i;
    }
}

void ptr()
{
    int arr[1000000];
    int *a;
    int i = 0;
    for (a = arr; a < arr + 1000000; a++) {
        *a = i++;
    }
}

int main(void)
{
    clock_t substr_begin = clock();
    substr();
    clock_t substr_end = clock();
    double substr_time = (double) (substr_end - substr_begin) / CLOCKS_PER_SEC;

    clock_t ptr_begin = clock();
    ptr();
    clock_t ptr_end = clock();
    double ptr_time = (double) (ptr_end - ptr_begin) / CLOCKS_PER_SEC;

    printf("%f %f\n", substr_time, ptr_time);

    return 0;
}
