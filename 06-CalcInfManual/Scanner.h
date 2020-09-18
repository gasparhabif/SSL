#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

enum Tokens
{
    INITIAL = 0,
    IDENTIFICATOR,
    NUMBER,
    ADDITION,
    PRODUCT,
    OP_PARENTHESIS,
    CL_PARENTHESIS,
    ERROR,
    END
};

typedef enum Tokens Token;

static Token CurrentToken = INITIAL;

Token GetNextToken(void);
bool IsIncluded(char *grammar, char c);
void PrintToken(Token t);
char *TokenToString(Token t);
static void ThrowLexicalError();