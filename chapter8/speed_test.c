#include <stdio.h>
#include <time.h>

#define SIZE 50000

void try1();
void try5();

int main(void)
{
    double t1[20];
    double t5[20];

    for (int i = 0; i < 20; i++) {
        clock_t t1_start = clock();
        try1();
        clock_t t1_end = clock();
        t1[i] = (double) (t1_end - t1_start) / CLOCKS_PER_SEC;
    }
    
    for (int i = 0; i < 20; i++) {
        clock_t t5_start = clock();
        try5();
        clock_t t5_end = clock();
        t5[i] = (double) (t5_end - t5_start) / CLOCKS_PER_SEC;
    }

    double t1_sum;
    printf("try1: ");
    for (int i = 0; i < 20; i++) {
        printf("%f ", t1[i]);
        t1_sum += t1[i];
    }
    printf("\nAverage: %f\n", t1_sum / 20);
    
    double t5_sum;
    printf("try5: ");
    for (int i = 0; i < 20; i++) {
        printf("%f ", t5[i]);
        t5_sum += t5[i];
    }
    printf("\nAverage: %f\n", t5_sum / 20);

    return 0;
}

void try1()
{
    int x[SIZE];
    int y[SIZE];
    int i;

    for( i = 0; i < SIZE; i++ )
        x[i] = y[i];
} 

void try5()
{
    int x[SIZE];
    int y[SIZE];
    int *p1, *p2; 
    //register int *p1, *p2;

    for ( p1 = x, p2 = y; p1 < &x[SIZE]; )
        *p1++ = *p2++;
} 
