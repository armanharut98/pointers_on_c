#define SIZE 50
int x[SIZE];
int y[SIZE];
int i;

void try5()
{
    register int *p1, *p2;
    for ( p1 = x, p2 = y; p1 < &x[SIZE]; )
        *p1++ = *p2++;
} 
