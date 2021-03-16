#include "Constants.h"
#include "Parser.h"

// 0 (False) for No Error Detected
// 1 (True) for Detected Error
static bool error = false;

static void ThrowError(void)
{
    error = true;
    CleanYylex();
    RunProgram();
}

void SetError(bool b)
{
    error = b;
}

bool GetError(void)
{
    return error;
}

void ThrowLexicalException(void)
{
    printf("%s(Scanner)%s Error Léxico. Token invalido\n", MAGENTA_BOLD, RED);
    ThrowError();
}

void ThrowSintacticalException(char const *ex)
{
    printf("%s(Parser) %sError Sintáctico: %s\n", BLUE_BOLD, RED, ex);
    ThrowError();
}

void ThrowMemoryException(int e)
{
    printf("%s(Memory)%s Error: ", RED_BOLD, RED);
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
    ThrowError();
}