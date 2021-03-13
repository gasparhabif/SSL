#include "Parser.h"

void RunProgram(void)
{
    printf("Inserte la expresión a evaluar: \n");

    bool result = Program();
    if (result)
        printf("(Parser) La expresión es Válida\n\n");

    RunProgram();
}

static bool Program(void)
{
    return CheckExpresion();
}

static bool CheckSentnece(void)
{
    Token t = GetNextToken();
    if (t == END)
        return true;
    else
        return isConstant(t) ? CheckSentnece() : CheckExpresion();
}

static bool CheckExpresion(void)
{
    Token nextToken = GetNextToken();
    return isConstant(nextToken) ? CheckSentnece()
                                 : ThrowSintacticalError(nextToken, "Identificador/Constante");
}

static bool isConstant(Token t)
{
    return t == NUMBER || t == IDENTIFICATOR;
}

static bool ThrowSintacticalError(Token currentToken, char *expected)
{
    if (currentToken != -1)
    {
        printf("(Parser) Error Sintáctico\n");
        printf("\t-> Token actual: %s", TokenToString(currentToken));
        printf("\n\t-> Token esperado: %s\n\n", expected);
    }
    fseek(stdin, 0, SEEK_END);
    return false;
}