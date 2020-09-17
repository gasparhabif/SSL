#include <stdio.h>
#include <stdbool.h>
#include <string.h>

enum Tokens
{
    INITIAL = 0,
    IDENTIFICATOR,
    NUMBER,
    ADDITION,
    PRODUCT,
    OP_PARENTHESIS,
    CL_PARENTHESIS,
    END
};

typedef enum Tokens Token;

static Token CurrentToken = INITIAL;

void Run_Scan(void);
Token GetNextToken(void);
bool IsIncluded(char *grammar, char c);
void PrintToken(Token t);
char *TokenToString(Token t);
Token ThrowLexicalError();