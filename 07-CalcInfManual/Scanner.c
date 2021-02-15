#include "Scanner.h"

Token GetNextToken()
{
    char newChar = getchar();

    if (newChar == EOF || newChar == '\n')
        return END;

    // Its a Number
    if (IsIncluded(POSSIBLE_NUM, newChar))
    {
        return AddCharToBuffer(newChar) ? NUMBER : ERROR;
    }
    else
    {
        ResetBuffer();
    }
    // Its an Identificator
    if (IsIncluded(POSSIBLE_IDS, newChar))
        return IDENTIFICATOR;

    // Operators
    if (IsIncluded(ADDITION_OP, newChar))
        return ADDITION;

    if (IsIncluded(PRODUCT_OP, newChar))
        return PRODUCT;

    if (IsIncluded(ASSIGNMENT_OP, newChar))
        return ASSIGNMENT;
    // End Operators

    // Opening Parenthesis
    if (IsIncluded(PARENTHESIS_OP, newChar))
        return OP_PARENTHESIS;

    // Closing Parenthesis
    if (IsIncluded(PARENTHESIS_CL, newChar))
        return CL_PARENTHESIS;

    // If its not a valid token, Lexical error must be shown.
    ThrowLexicalError();
    return ERROR;
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
    if (t != END && t != INITIAL && t != ERROR)
    {
        char *tokenValue = TokenToString(t);
        printf("%s(Scanner)%s Token encontrado: %s %s \n", MAGENTA_BOLD, WHITE, WHITE_BOLD, tokenValue);
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
    case ERROR:
        return "Error";
    default:
        return "";
    }
}

static void ThrowLexicalError()
{
    printf("%s(Scanner)%s Error Léxico", MAGENTA_BOLD, RED);
}

static void ResetBuffer()
{
    while (bufferPos >= 0)
    {
        buffer[bufferPos] = '\0';
        bufferPos--;
    }
    bufferPos = 0;
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
        ThrowBufferError();
        return false;
    }
}

static void PrintBuffer()
{
    printf("%s(Buffer)%s Actualmente almacenado en Buffer: ", "\e[0;33m", WHITE);

    for (int i = 0; i <= bufferPos; i++)
        printf("%c", buffer[i]);
    printf("\n");
}

static void ThrowBufferError()
{
    printf("%s(Buffer)%s El lexema supera la cantidad de caracteres validos para el Buffer ", "\e[0;33m", RED);
}