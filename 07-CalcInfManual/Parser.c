#include "Parser.h"

void Run_Scan()
{
    CleanGlobalVariables();
    printf("Ingrese la expresión a evaluar: \n");

    while (currentToken != END && !AnyKindError(currentToken))
    {
        currentToken = GetNextToken();
        // Lexical error detection
        if (currentToken != LEXICAL_ERROR)
        {
            PrintToken(currentToken);
            CheckToken(currentToken);
            lastToken = currentToken;
        }
    }

    if (!AnyKindError(currentToken))
    {
        printf("%s(Parser)", BLUE_BOLD);
        if (pCounter == 0)
        {
            printf("%s La expresión es Válida\n", GREEN);
        }
        else
        {
            printf("%s Error Sintáctico\n", RED);
            printf("\t-> Paréntesis desbalanceados\n");
        }
    }

    Run_Scan();
}

static void CleanGlobalVariables()
{
    // Reset console colors.
    printf("\n\e[0m");
    lastToken = INITIAL;
    currentToken = INITIAL;
    pCounter = 0;
    CleanBuffer();
}

static void ThrowSintacticalError(Token actual, char *expected)
{
    printf("%s(Parser) %sError Sintáctico\n", BLUE_BOLD, RED);
    printf("\t-> Token actual: %s", TokenToString(actual));
    printf("\n\t-> Tokens esperados: %s\n", expected);
    currentToken = SINTACTICAL_ERROR;
}

void CheckToken(Token t)
{
    if (lastToken == INITIAL)
    {
        if (t == OP_PARENTHESIS)
            pCounter++;

        if (t == ADDITION || t == PRODUCT || t == CL_PARENTHESIS)
        {
            ThrowSintacticalError(t, "Número, Identificador o Paréntesis de Apertura '('");
            currentToken = SINTACTICAL_ERROR;
            return;
        }
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

static bool AnyKindError(Token t)
{
    return t == LEXICAL_ERROR || t == SINTACTICAL_ERROR;
}