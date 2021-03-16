#include "Constants.h"
#include "Buffer.h"

enum Tokens
{
    INITIAL = 0,
    IDENTIFICATOR,
    NUMBER,
    ADDITION,
    PRODUCT,
    OP_PARENTHESIS,
    CL_PARENTHESIS,
    ASSIGNATION,
    END
};

typedef enum Tokens Token;
int currentToken;

Token GetNextToken(void);
void PrintToken(Token t);
char *TokenToString(Token t);