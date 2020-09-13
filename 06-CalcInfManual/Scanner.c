#include <stdio.h>
#include "Scanner.h"
#include <string.h>

const char *POSSIBLE_IDS = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char *POSSIBLE_NUM = "0123456789";

const char ADDITION_OP = '+';
const char PRODUCT_OP = '*';

Token GetNextToken()
{
    char newChar = EOF;

    while ((newChar = getchar()) != EOF)
    {
        // Its an Identificator
        if (strstr(newChar, POSSIBLE_IDS) != NULL)
            return IDENTIFICATOR;

        // Its a Number
        if (strstr(newChar, POSSIBLE_NUM) != NULL)
            return NUMBER;

        // Its an Adition
        if (strstr(newChar, ADDITION_OP) != NULL)
            return ADDITION;

        // Its a Product
        if (strstr(newChar, PRODUCT_OP) != NULL)
            return PRODUCT;

        // If its not a valid token, Lexical error must be shown.
        return ThrowLexicalError();
    }
}

Token ThrowLexicalError()
{
    printf("\nLexical Error");
    return END;
}