static int w = 5;   // w: linkage - internal, scope - file, storage class - static
extern int x;       // x: linkage - external, scope - file, storage class -  static

static float func1( int a, int b, int c ) // func1: linkage - internal, scope - file, storage class - static | a, b, c: linkage - none, scope - block, storage class - automatic
{
    int d, e = 1;   // d, e: linkage - none, scope - block, storage class - automatic
    {
        int d,e,w;  // d, e, w: linkage - none, scope - block, storage class - automatic
        {
            int b, c, d;    // b, c, d: linkage - none, scope - block, storage class - automatic
            static int y = 2;   // y: linkage - none, scope - block, storage class - static
        }
    }
    {
        register int a, d, x;   // a, d, x: linkage - none, scope - block, storage class - register (similar to automatic)
        int y;
    }
}

static int y;   // y: linkage - internal, scope - file, storage class - static

float func2( int a )    // func2: linkage - external, scope - file, storage class - static | a: linkage - none, scope - block, storage class - automatic
{
    extern int y;   // y: linkage - external, scope - block, storage class - automatic
    static int z;   // z: linkage - none, scope - block, storage class - static
}

