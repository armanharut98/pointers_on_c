#include <stdio.h>
#include <stdarg.h>

void printff(char *format, ...);
void print_integer(int i);
void print_float(float f);

int main(void)
{
    int n = 2;
    char *name1 = "Kyle";
    char *name2 = "Woody";
    float amount = 2.5;
    char letter_grade = 'A';

    printf("I have %d friends. Their names are %s and %s. They both owe me %f$. They get straight %cs because they are very good students.\n", n, name1, name2, amount, letter_grade);
    printff("I have %d friends. Their names are %s and %s. They both owe me %f$. They get straight %cs because they are very good students.\n", n, name1, name2, amount, letter_grade);
    return 0;
}

void print_integer(int i)
{
    printf("%d", i);
}

void print_float(float f)
{
    printf("%f", f);
}

void printff(char *format, ...)
{
    va_list args;
    va_start(args, format);

    while (*format != '\0') {
        if (*format != '%') {
            putchar(*format++);
        } else {
            format++;
            if (*format == 'd') {
                print_integer(va_arg(args, int));
            } else if (*format == 'f') {
                print_float(va_arg(args, double));
            } else if (*format == 'c') {
                putchar(va_arg(args, int));
            } else if (*format == 's') {
                char *str = va_arg(args, char *);
                while (*str != '\0') {
                    putchar(*str++);
                }
            }
            format++;
        }
    }
    
    va_end(args);
}

