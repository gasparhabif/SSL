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

Token GetNextToken(void);
char *TokenToString(Token);
static Token CheckConstant(Token);
static Token DetectToken(char);
static void PrintToken(Token, char *);
static bool IsIncluded(char *, char);