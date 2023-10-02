/* 
 *  The program that reads characters from the standard input and writes them to
 *  the standard output. All characters should be written exactly as they were read
 *  except for alphabetic characters, which are encrypted before being written. 
 *  The encryption process is straightforward: each letter is changed to whatever
 *  letter appears 13 places after (or before) it in the alphabet. For instance, an A is
 *  changed to an N, a B is changed to an O, a Z is changed to an M, and so forth. Note
 *  that both upper and lowercase letters must be converted. Hint: It may help to
 *  remember that a character is really just an integer with a small value.
*/

#include <stdio.h>

#define INCREMENT 13

int main(void)
{
    int c;

    while ((c = getchar()) != EOF) {
        if (c >= 'A' && c <= 'Z')
            c = ((c + INCREMENT) % 'A' % 26) + 'A';
        else if (c >= 'a' && c <= 'z')
            c = ((c + INCREMENT) % 'a' % 26) + 'a';
        putchar(c);
    }
}

