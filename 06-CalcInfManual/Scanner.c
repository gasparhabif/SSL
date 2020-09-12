#include <stdio.h>
#include "Scanner.h"
#include <regex.h>

regex_t regex;

Token GetNextToken()
{
    char newChar = EOF;

    while ((newChar = getchar()) != EOF)
    {
        if (regcomp(&regex, "^[a-zA-Z]+$", 0))
        {
            // Element identificator
        }
    }
}