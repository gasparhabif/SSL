#include "Scanner.h"

Token GetNextToken()
{
    char newChar = getchar();

    if (newChar == EOF || newChar == '\n')
        return END;

    // Its a Number
    if (IsIncluded(POSSIBLE_NUM, newChar))
    {
        return AddCharToBuffer(newChar) ? NUMBER : ThrowException(true);
    }

    // Its an Identificator
    if (IsIncluded(POSSIBLE_IDS, newChar))
        return AddCharToBuffer(newChar) ? IDENTIFICATOR : ThrowException(true);

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
    return ThrowException(false);
}

bool IsIncluded(char *grammar, char c)
{
    return strstr(grammar, (char[2]){(char)c, '\0'}) != NULL;
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
    default:
        return "";
    }
}

static Token ThrowException(bool isBufferError)
{
    if (isBufferError)
    {
        printf("%s(Buffer)%s El lexema supera la cantidad de caracteres validos para el Buffer ", YELLOW_BOLD, RED);
    }
    else
    {
        printf("%s(Scanner)%s Error Léxico. Token invalido\n", MAGENTA_BOLD, RED);
    }

    CleanBuffer();
    fseek(stdin, 0, SEEK_END);
    return LEXICAL_ERROR;
}

void CleanBuffer()
{
    while (bufferPos >= 0)
    {
        buffer[bufferPos] = '\0';
        bufferPos--;
    }
    bufferPos = 0;
    printf("%s(Buffer)%s Limpiado\n", YELLOW_BOLD, WHITE);
}

static bool AddCharToBuffer(char c)
{

    if (bufferPos < (BUFFER_SIZE - 1))
    {
        buffer[bufferPos++] = c;
        PrintBuffer();
        return true;
    }
    else
    {
        return false;
    }
}

static void PrintBuffer()
{
    printf("%s(Buffer)%s Actualmente almacenado en Buffer: ", YELLOW_BOLD, WHITE);

    for (int i = 0; i <= bufferPos; i++)
        printf("%c", buffer[i]);
    printf("\n");
}