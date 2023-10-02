#include <stdio.h>
#include <string.h>

int lookup_keyword( char const * const desired_word, char const *keyword_table[], int const size );

int main()
{
    char const *keywords[] = {
        "do",
        "for",
        "if",
        "register",
        "return",
        "switch",
        "while" 
    };

    #define N_KEYWORD (sizeof(keywords) / sizeof(keywords[0]))

    printf("%d\n", lookup_keyword("yellow", keywords, 7));
    printf("%d\n", lookup_keyword("switch", keywords, 7));

    return 0;
}

int lookup_keyword( char const * const desired_word, char const *keyword_table[], int const size ) 
{
    char const **it;

    for (it = keyword_table; it < keyword_table + size; it++) {
        if (strcmp(*it, desired_word) == 0) {
            return it - keyword_table;
        }
    }

    return -1;
}
