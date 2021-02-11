#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define WHITE "\e[0;37m"
#define RED "\e[0;31m"
#define WHITE_BOLD "\e[1;37m"
#define MAGENTA_BOLD "\e[1;35m"

#define POSSIBLE_IDS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define POSSIBLE_NUM "0123456789"

#define ADDITION_OP "+"
#define PRODUCT_OP "*"
#define ASSIGNMENT_OP "="

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
    ASSIGNMENT,
    ERROR,
    END
};

typedef enum Tokens Token;

static Token currentToken = INITIAL;

Token GetNextToken(void);
bool IsIncluded(char *grammar, char c);
void PrintToken(Token t);
char *TokenToString(Token t);
static void ThrowLexicalError();