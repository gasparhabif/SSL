#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

enum Tokens
{
    IDENTIFICATOR,
    NUMBER,
    ADDITION,
    PRODUCT,
    ASSIGNATION,
    END
};

typedef enum Tokens Token;

Token GetNextToken(void);
char *TokenToString(Token);
static bool IsIncluded(char *, char);
static void PrintToken(Token);
static void ThrowLexicalError(void);