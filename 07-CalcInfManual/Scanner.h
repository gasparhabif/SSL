#include "Constants.h"

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
    LEXICAL_ERROR,
    SINTACTICAL_ERROR,
    END
};

typedef enum Tokens Token;

static Token currentToken = INITIAL;

static char buffer[BUFFER_SIZE];
static int bufferPos;

Token GetNextToken(void);
bool IsIncluded(char *grammar, char c);
void PrintToken(Token t);
char *TokenToString(Token t);
void CleanBuffer();
static Token ThrowError(bool b);
static bool AddCharToBuffer(char c);
static void PrintBuffer();