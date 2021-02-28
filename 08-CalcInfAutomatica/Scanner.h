#include "Constants.h"
#include "Buffer.h"

// Possible Constants
#define POSSIBLE_IDS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define POSSIBLE_NUM "0123456789"

// Possible Operators
#define ADDITION_OP "+"
#define PRODUCT_OP "*"
#define ASSIGNATION_OP "="

#define PARENTHESIS_OP "("
#define PARENTHESIS_CL ")"

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

Token GetNextToken(void);
void PrintToken(Token t);
char *TokenToString(Token t);