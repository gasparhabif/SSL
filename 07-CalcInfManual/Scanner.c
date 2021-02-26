#include "Scanner.h"
#include "ErrorHandler.h"

Token GetNextToken()
{
    char newChar = getchar();

    if (newChar == EOF || newChar == '\n')
        return END;

    // Its a Number
    if (IsIncluded(POSSIBLE_NUM, newChar))
    {
        AddCharToBuffer(newChar);
        return NUMBER;
    }

    // Its an Identificator
    if (IsIncluded(POSSIBLE_IDS, newChar))
    {
        AddCharToBuffer(newChar);
        return IDENTIFICATOR;
    }

    // Operators
    if (IsIncluded(ADDITION_OP, newChar))
        return ADDITION;

    if (IsIncluded(PRODUCT_OP, newChar))
        return PRODUCT;

    if (IsIncluded(ASSIGNATION_OP, newChar))
        return ASSIGNATION;
    // End Operators

    // Opening Parenthesis
    if (IsIncluded(PARENTHESIS_OP, newChar))
        return OP_PARENTHESIS;

    // Closing Parenthesis
    if (IsIncluded(PARENTHESIS_CL, newChar))
        return CL_PARENTHESIS;

    // If its not a valid token, Lexical error must be shown.
    ThrowLexicalException();
    return END;
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