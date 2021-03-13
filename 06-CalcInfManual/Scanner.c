#include "Scanner.h"

static char *POSSIBLE_IDS = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
static char *POSSIBLE_NUM = "0123456789";

static char *ADDITION_OP = "+";
static char *PRODUCT_OP = "*";
static char *ASSIGNATION_OP = "=";

Token GetNextToken(void)
{
    char newChar = getchar();
    Token t = -1;

    if (newChar == EOF || newChar == '\n')
        t = END;

    // Its an Identificator
    if (IsIncluded(POSSIBLE_IDS, newChar))
        t = IDENTIFICATOR;

    // Its a Number
    if (IsIncluded(POSSIBLE_NUM, newChar))
        t = NUMBER;

    if (IsIncluded(ADDITION_OP, newChar))
        t = ADDITION;

    if (IsIncluded(PRODUCT_OP, newChar))
        t = PRODUCT;

    if (IsIncluded(ASSIGNATION_OP, newChar))
        t = ASSIGNATION;

    if (t != -1)
        PrintToken(t);
    else
        ThrowLexicalError();
    return t;
}

static bool IsIncluded(char *grammar, char c)
{
    return strchr(grammar, c) != NULL;
}

static void PrintToken(Token t)
{
    if (t != END)
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
    case ASSIGNATION:
        return "Asignacion [=]";
    case END:
        return "Enter (EOF)";
    default:
        return "[Token no Detectado]";
    }
}

static void ThrowLexicalError(void)
{
    printf("(Scanner) Error Léxico\n");
    fseek(stdin, 0, SEEK_END);
}