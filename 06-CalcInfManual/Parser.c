#include "Parser.h"

Token lastToken;
int pCounter;

static void ThrowSintacticalError(Token actual, char *expected);
void CheckToken(Token t);
static bool IsTokenOperator(Token t);
static bool IsTokenConstant(Token t);

void Run_Scan()
{
    lastToken = INITIAL;
    pCounter = 0;

    while (CurrentToken != END && CurrentToken != ERROR)
    {
        CurrentToken = GetNextToken();
        PrintToken(CurrentToken);
        CheckToken(CurrentToken);

        lastToken = CurrentToken;
    }

    if (CurrentToken != ERROR)
    {
        if (pCounter == 0)
        {
            printf("(Parser) La expresión es Válida");
        }
        else
        {
            printf("(Parser) Error Sintáctico\n");
            printf("\t-> Paréntesis desbalanceados");
            exit(1);
        }
    }
    else
    {
        exit(1);
    }
}

static void ThrowSintacticalError(Token actual, char *expected)
{
    printf("(Parser) Error Sintáctico\n");
    printf("\t-> Token actual: %s", TokenToString(actual));
    printf("\n\t-> Tokens esperados: %s", expected);
    CurrentToken = ERROR;
}

void CheckToken(Token t)
{
    if (lastToken == INITIAL)
    {
        if (t == OP_PARENTHESIS)
            pCounter++;

        if (t == ADDITION || t == PRODUCT || t == CL_PARENTHESIS)
        {
            CurrentToken = ERROR;
            ThrowSintacticalError(t, "Número, Identificador o Paréntesis de Apertura '('");
            return;
        }
        else
            return;
    }
    else
    {
        switch (t)
        {
        case END:
        case ADDITION:
        case PRODUCT:
        {
            if (!(IsTokenConstant(lastToken) || lastToken == CL_PARENTHESIS))
                ThrowSintacticalError(t, "Número, Identificador o Paréntesis de Cierre ')'");
        }
        break;
        case NUMBER:
        {
            if (!(IsTokenOperator(lastToken) || lastToken == NUMBER || lastToken == OP_PARENTHESIS))
                ThrowSintacticalError(t, "Número, Operador o Paréntesis de Apertura '('");
        }
        break;
        case IDENTIFICATOR:
        {
            if (!(IsTokenOperator(lastToken) || lastToken == IDENTIFICATOR || lastToken == OP_PARENTHESIS))
                ThrowSintacticalError(t, "Identificador, Operador o Paréntesis de Apertura '('");
        }
        break;
        case OP_PARENTHESIS:
        {
            pCounter++;
            if (!(IsTokenOperator(lastToken) || lastToken == OP_PARENTHESIS))
                ThrowSintacticalError(t, "Operador o Paréntesis de Apertura '('");
        }
        break;
        case CL_PARENTHESIS:
        {
            pCounter--;
            if (!(IsTokenConstant(lastToken) || lastToken == CL_PARENTHESIS) && pCounter >= 0)
                ThrowSintacticalError(t, "Número, Identificador o Paréntesis de Cierre ')'");
        }
        break;
        default:
            ThrowSintacticalError(t, "[No detectado]");
        }
    }
}

static bool IsTokenOperator(Token t)
{
    return t == ADDITION || t == PRODUCT;
}

static bool IsTokenConstant(Token t)
{
    return t == NUMBER || t == IDENTIFICATOR;
}