#include "Parser.h"

Token lastToken;
int pCounter;

static void ThrowSintacticalError();
bool CorrectToken(Token t);
static bool IsTokenOperator(Token t);
static bool IsTokenConstant(Token t);

void Run_Scan()
{
    lastToken = INITIAL;
    pCounter = 0;

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

    if (pCounter == 0)
    {
        printf("(Parser) La expresión es Válida");
    }
    else
    {
        ThrowSintacticalError();
    }
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
    if (lastToken == INITIAL)
    {
        if (t == OP_PARENTHESIS)
            pCounter++;

        return t != ADDITION && t != PRODUCT && t != CL_PARENTHESIS;
    }
    else
    {
        switch (t)
        {
        case END:
        case ADDITION:
        case PRODUCT:
            return IsTokenConstant(lastToken) || lastToken == CL_PARENTHESIS;
        case NUMBER:
            return IsTokenOperator(lastToken) || lastToken == NUMBER || lastToken == OP_PARENTHESIS;
        case IDENTIFICATOR:
            return IsTokenOperator(lastToken) || lastToken == IDENTIFICATOR || lastToken == OP_PARENTHESIS;
        case OP_PARENTHESIS:
        {
            bool valid = IsTokenOperator(lastToken) || lastToken == OP_PARENTHESIS;
            pCounter++;
            return valid;
        }
        case CL_PARENTHESIS:
        {
            bool valid = IsTokenConstant(lastToken) || lastToken == CL_PARENTHESIS;
            pCounter--;
            return valid && pCounter >= 0;
        }
        default:
            return false;
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