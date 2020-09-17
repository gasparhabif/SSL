#include "Parser.h"

Token lastToken;

static void ThrowSintacticalError();
bool CorrectToken(Token t);
static bool IsTokenOperator(Token t);
static bool IsTokenConstant(Token t);

void Run_Scan()
{
    lastToken = INITIAL;
    while (CurrentToken != END)
    {
        CurrentToken = GetNextToken();
        PrintToken(CurrentToken);

        if (!CorrectToken(CurrentToken))
        {
            ThrowSintacticalError();
        }
        lastToken = CurrentToken;
    }

    printf("(Parser) La expresión es Válida");
}

static void ThrowSintacticalError()
{
    printf("(Parser) Error Sintáctico\n");
    // printf("(Parser) Token actual: %u", actual);
    // printf("(Parser) Token esperado: %u", expected);
    exit(1);
}

bool CorrectToken(Token t)
{
    if (t == END)
        return true;
    else
    {
        switch (lastToken)
        {
        case INITIAL:
            return IsTokenConstant(t);
        case ADDITION:
        case PRODUCT:
            return IsTokenConstant(t);
        case NUMBER:
            return IsTokenOperator(t) || t == NUMBER;
        case IDENTIFICATOR:
            return IsTokenOperator(t) || t == IDENTIFICATOR;
        default:
            return false;
        }
    }
}

static bool IsTokenOperator(Token t)
{
    return t == IDENTIFICATOR || t == NUMBER;
}

static bool IsTokenConstant(Token t)
{
    return t == NUMBER || t == IDENTIFICATOR;
}