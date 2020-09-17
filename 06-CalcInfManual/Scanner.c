#include "Scanner.h"

static char *POSSIBLE_IDS = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
static char *POSSIBLE_NUM = "0123456789";

static char *ADDITION_OP = "+";
static char *PRODUCT_OP = "*";

static char *PARENTHESIS_OP = "(";
static char *PARENTHESIS_CL = ")";

void Run_Scan()
{
    while (CurrentToken != END)
    {
        PrintToken(CurrentToken);
        CurrentToken = GetNextToken();
    }
}

Token GetNextToken()
{
    char newChar = getchar();

    if (newChar == EOF || newChar == '\n')
        return END;

    // Its an Identificator
    if (IsIncluded(POSSIBLE_IDS, newChar))
        return IDENTIFICATOR;

    // Its a Number
    if (IsIncluded(POSSIBLE_NUM, newChar))
        return NUMBER;

    if (IsIncluded(ADDITION_OP, newChar))
        return ADDITION;

    if (IsIncluded(PRODUCT_OP, newChar))
        return PRODUCT;

    // Opening Parenthesis
    if (IsIncluded(PARENTHESIS_OP, newChar))
        return OP_PARENTHESIS;

    // Closing Parenthesis
    if (IsIncluded(PARENTHESIS_CL, newChar))
        return CL_PARENTHESIS;

    // If its not a valid token, Lexical error must be shown.
    return ThrowLexicalError();
}

bool IsIncluded(char *grammar, char c)
{
    size_t length = strlen(grammar);

    for (int i = 0; i < length; i++)
    {
        if (grammar[i] == c)
            return true;
    }
    return false;
}

void PrintToken(Token t)
{
    if (t != END && t != INITIAL)
    {
        char *tokenValue = TokenToString(t);
        printf("(Scanner) Token encontrado: %s \n", tokenValue);
    }
}

char *TokenToString(Token t)
{
    switch (t)
    {
    case IDENTIFICATOR:
        return "Identificador";
    case NUMBER:
        return "Número";
    case ADDITION:
        return "Adición [+]";
    case PRODUCT:
        return "Producto [*]";
    case OP_PARENTHESIS:
        return "Apertura de Paréntesis [(]";
    case CL_PARENTHESIS:
        return "Cierre de Paréntesis [)]";
    default:
        return "";
    }
}

Token ThrowLexicalError()
{
    printf("(Scanner) Error Léxico\n");
    return END;
}