#include <stdio.h>

#define TRUE 1
#define FALSE 0

int isPolindrome(char *word, int size);

int main(void)
{
    /*
    1.  Given the declarations and data shown below, evaluate each of the expressions and
        state its value. Evaluate each expression with the original data shown (that is, the
        results of one expression do not affect the following ones). Assume that the ints
        array begins at location 100 and that integers and pointers both occupy four bytes.
    */
    int ints[20] = {
        10, 20, 30, 40, 50, 60, 70, 80, 90, 100,
        110, 120, 130, 140, 150, 160, 170, 180, 190, 200
    }; 

    int *ip = ints + 3;

    // Expressions
    ints;   // 100
    ints[4];    // 50
    ints + 4;   // 116
    *ints + 4;  //14
    *(ints + 4);    // 50;
    ints[-2];   // illegal
    &ints;  // Taking the address of an array name gives a pointer to the first element in the array, not a pointer to some substituted pointer constant value. Therefore the answer is 100
    &ints[4];   // 116
    &ints + 4;  // Taking the address of an array name gives a pointer to the first element in the array, not a pointer to some substituted pointer constant value. Therefore the answer is 116
    &ints[-2];  // illegal
    ip; // 112
    ip[4];  // 80
    ip + 4; // 128
    *ip + 4;    // 44
    *(ip + 4);   // 80
    ip[-2];     // 20
    &ip;    // can't tell
    &ip[4]; // 128
    &ip + 4;    // can't tell
    &ip[-2];    // 104

    /*
    2.  Are the expressions array[ i + j ] and i + j[ array ] equivalent?
    */

    int array[10];
    int i = 3, j = 4;

    // Answer: No, these two expressions are not equal
    *(array + (i + j));
    i + *(j + (array));

    /*
    3.  The following declarations are an attempt to access the array data using subscripts
        that start at one. Will it work?
    */
    int actual_data[ 20 ] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int *data = actual_data - 1; 
    
    printf("%d\n", data[1]);
    printf("%d\n", data[21]);
    printf("%d\n", data[5]);
    printf("%d\n", data[20]);
    printf("%d\n", data[10]);
    printf("%d\n", data[19]);
    printf("%d\n", data[0]);

    // Answer: Yes, it will work

    /*
    4.  Rewrite the following loop, which tests whether a string is a palindrome, to use
        pointer variables instead of subscripts.

        char buffer[SIZE];
        int front, rear;
        front = 0;
        rear = strlen( buffer ) - 1;
        while( front < rear ){
            if( buffer[front] != buffer[rear] )
                break;
            front += 1;
            rear -= 1;
        }
        if( front >= rear ){
            printf( "It is a palindrome!\n" );
        } 
    */

    // Answer: implemented in the isPolindrome function.
    printf("%d\n", isPolindrome("aaabbaaa", 8));
    printf("%d\n", isPolindrome("aaabaa", 6));
    printf("%d\n", isPolindrome("a", 1));
    printf("%d\n", isPolindrome("crystal", 7));
    printf("%d\n", isPolindrome("madam", 5));

    /*
    5.  The potential efficiency of pointers over subscripts is a motivation to use them.
        When is it reasonable to use subscripts despite the possible loss of runtime speed?

    Answer: It is often true that 80% of a programȇs run time is spent executing 20% of its
            code. The efficiency of statements in the other 80% of the code is not significant,
            so the use of pointers is not justified by the gain in efficiency.
    */

    /*
    6.  Compile the functions try1 through try5 on your machine, and analyze the
        resulting assembly code. What is your conclusion?

    Answer: Assembly code can be found in the same directory this file is.
    */

    /*
    7.  Test your conclusion for the previous question by running each of the functions
        and timing their execution. Making the arrays several thousand elements long
        increases the accuracy of the experiment because the copying takes far more time
        than the irrelevant parts of the program. Also, call the functions from within a loop
        that iterates enough times so that you can accurately time the entire execution.ȱȱ
        Compile the programs twice for this experiment—once without any optimization
        at all, and once with optimization. If your compiler offers a choice, select
        optimization for best speed.

    Answer:
        try1: 0.000157 0.000059 0.000033 0.000033 0.000032 0.000032 0.000034 0.000031 0.000031 0.000031 0.000033 0.000032 0.000032 0.000032 0.000030 0.000031 0.000033 0.000031 0.000031 0.000032 
        Average: 0.000040
        try5: 0.000034 0.000034 0.000035 0.000034 0.000035 0.000034 0.000034 0.000034 0.000034 0.000034 0.000035 0.000034 0.000035 0.000034 0.000035 0.000034 0.000035 0.000034 0.000033 0.000033 
        Average: 0.000034
    */

    /*
    8.  The following declarations were found in one source file:
            int a[10];
            int *b = a;

        But in a different source file, this code was found:
            extern int *a;
            extern int b[];
            int x, y;
            x = a[3];
            y = b[3];

        Explain what happens when the two assignment statements are executed. (Assume
        that integers and pointers both occupy four bytes).
    
    Answer: In the first assignment, the compiler thinks a is a pointer variable, so it will get
            the pointer value stored there, add 12 (3 scaled by the size of an integer), and
            then apply indirection to the result. But a is actually where the array of
            characters begins, so the value obtained as theȱ ȈpointerȈȱ will be the
            concatenated values of the first four characters in the array. The value 12 is
            added to it, and the indirection interprets the result as an address. It either
            fetches the contents of some random location in memory, or it causes the
            program to abort with some sort of addressing fault.
            In the second assignment, the compiler thinks b is the name of an array,
            so it adds 12 (the scaled result of 3) to the address where b is stored, and the
            indirection obtains the value found there. In fact, b is a pointer variable, so the
            value fetched from three words further in memory is from some other, random
            variable. This question illustrates that pointers and arrays, while related, are
            definitely not the same.
    */

   /*
    9.  Write a declaration that will initialize an array of integers called coin_values to the
        values of current U.S. coins.
   */

    double coin_values[] = { 0.01, 0.05, 0.1, 0.25 };
}

int isPolindrome(char *word, int size)
{
    char *begin = word;
    char *end = word + (size - 1);

    while (begin < end) {
        if (*begin++ != *end--) {
            return FALSE;
        }
    }

    return TRUE;
}
