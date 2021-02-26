#include "Scanner.h"

Token GetNextToken()
{
    char newChar = getchar();
    Token t = INITIAL;

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

    PrintToken(t);

    if (t == NUMBER || t == IDENTIFICATOR)
        AddCharToBuffer(newChar);

    // If its not a valid token the value won't be overwritten,
    // it's value will still be INITIAL and Lexical Exception will be shown.
    if (t == INITIAL)
        ThrowLexicalException();

    return t;
}

void PrintToken(Token t)
{
    if (t != END && t != INITIAL)
    {
        char *tokenValue = TokenToString(t);
        printf("%s(Scanner)%s Token encontrado: %s%s \n", MAGENTA_BOLD, WHITE, WHITE_BOLD, tokenValue);
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
        return "Apertura de Paréntesis '('";
    case CL_PARENTHESIS:
        return "Cierre de Paréntesis ')'";
    case END:
        return "Enter (EOF)";
    case ASSIGNATION:
        return "Asignación [=]";
    case INITIAL:
        return "Inicial";
    default:
        return "[Token no Detectado]";
    }
}

static bool IsIncluded(char *grammar, char c)
{
    return strstr(grammar, (char[2]){(char)c, '\0'}) != NULL;
}