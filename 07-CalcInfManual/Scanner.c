#include "Scanner.h"

Token GetNextToken(void)
{
    char newChar = getchar();
    Token t = -1;

    if (newChar == EOF || newChar == '\n')
        t = END;

    // Its a Number
    if (IsIncluded(POSSIBLE_NUM, newChar))
        t = NUMBER;

    // Its an Identificator
    if (IsIncluded(POSSIBLE_IDS, newChar))
        t = IDENTIFICATOR;

    // Operators
    if (IsIncluded(ADDITION_OP, newChar))
        t = ADDITION;

    if (IsIncluded(PRODUCT_OP, newChar))
        t = PRODUCT;

    if (IsIncluded(ASSIGNATION_OP, newChar))
        t = ASSIGNATION;
    // End Operators

    // Opening Parenthesis
    if (IsIncluded(PARENTHESIS_OP, newChar))
        t = OP_PARENTHESIS;

    // Closing Parenthesis
    if (IsIncluded(PARENTHESIS_CL, newChar))
        t = CL_PARENTHESIS;

    if (t == NUMBER || t == IDENTIFICATOR)
        AddCharToBuffer(newChar);

    // If its not a valid token the value won't be overwritten,
    // it's value will still be -1 and Lexical Exception will be shown.
    if (t == -1)
        ThrowLexicalException();
    else
        PrintToken(t, newChar);

    return t;
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
        return "Apertura de Paréntesis '('";
    case CL_PARENTHESIS:
        return "Cierre de Paréntesis ')'";
    case END:
        return "Enter (EOF)";
    case ASSIGNATION:
        return "Asignación [=]";
    default:
        return "[Token no Detectado]";
    }
}

static void PrintToken(Token t, char c)
{
    if (t != END)
    {
        char *tokenValue = TokenToString(t);
        printf("%s(Scanner)%s Token encontrado: %s%s", MAGENTA_BOLD, WHITE, WHITE_BOLD, tokenValue);
        if (t == NUMBER || t == IDENTIFICATOR)
            printf(" [%c]", c);
        printf("\n");
    }
}

static bool IsIncluded(char *grammar, char c)
{
    return strchr(grammar, c) != NULL;
}