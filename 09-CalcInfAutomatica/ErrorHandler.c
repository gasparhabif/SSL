#include "Buffer.h"

// 0 (False) for No Error Detected
// 1 (True) for Detected Error
static bool error = false;

static void ThrowError()
{
    error = true;
    fseek(stdin, 0, SEEK_END);
    CleanBuffer();
}

void SetError(bool b)
{
    error = b;
}

bool GetError()
{
    return error;
}

void ThrowLexicalException()
{
    ThrowError();
    printf("%s(Scanner)%s Error Léxico. Token invalido\n", MAGENTA_BOLD, RED);
}

void ThrowSintacticalException(char const *ex)
{
    ThrowError();
    printf("%s(Parser) %sError Sintáctico: %s\n", BLUE_BOLD, RED, ex);
}

void ThrowBufferException()
{
    ThrowError();
    printf("%s(Buffer)%s El lexema supera la cantidad de caracteres validos para el Buffer ", YELLOW_BOLD, RED);
}

void ThrowMemoryException(int e)
{
    ThrowError();
    printf("%s(Memory)%s ", RED_BOLD, WHITE);
    switch (e)
    {
    case 1:
        printf("No hay más espacios disponibles en memoria.\n");
        break;
    case 2:
        printf("El identificador ingresado ya existe, será sobreescrito con el nuevo valor.\n");
        break;
    case 3:
        printf("El identificador solicitado no existe en memoria.\n");
        break;
    default:
        break;
    }
}