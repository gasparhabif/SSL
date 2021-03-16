#include "Constants.h"
#include "Buffer.h"

enum Tokens
{
    IDENTIFICATOR,
    NUMBER,
    ADDITION,
    PRODUCT,
    ASSIGNATION,
    OP_PARENTHESIS,
    CL_PARENTHESIS,
    END
};

typedef enum Tokens Token;
int currentToken;

Token GetNextToken(void);
char *TokenToString(Token);
void CleanYylex(void);
static void PrintToken(Token, char *);