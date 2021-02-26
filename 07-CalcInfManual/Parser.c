#include "Parser.h"

void RunScan()
{
    printf("Ingrese la expresión a evaluar: \n");

    Token currentToken = INITIAL;
    Token lastToken = INITIAL;

    while (currentToken != END && !GetError())
    {
        currentToken = GetNextToken();
        // Lexical error detection
        if (!GetError())
        {
            PrintToken(currentToken);
            CheckToken(currentToken, lastToken);
            EvaluateExpresion(currentToken);
            lastToken = currentToken;
        }
    }

    PrintResult(currentToken);
    CleanGlobalVariables();
    RunScan();
}

static void EvaluateExpresion(Token currentToken)
{
    if (lastOperation != CL_PARENTHESIS)
    {
        switch (currentToken)
        {
        case ADDITION:
        {
            result += BufferValue();
            lastOperation = ADDITION;
            CleanBuffer();
        }
        break;
        case PRODUCT:
        {
            result = result == 0 ? BufferValue() : result * BufferValue();
            lastOperation = PRODUCT;
            CleanBuffer();
        }
        break;
        case ASSIGNATION:
        {
            AddToMemory(buffer);
            lastOperation = ASSIGNATION;
            CleanBuffer();
        }
        break;
        case CL_PARENTHESIS:
        {
            switch (lastOperation)
            {
            case ADDITION:
            {
                result += BufferValue();
                lastOperation = ADDITION;
                CleanBuffer();
            }
            break;
            case PRODUCT:
            {
                result = result == 0 ? BufferValue() : result * BufferValue();
                lastOperation = PRODUCT;
                CleanBuffer();
            }
            break;

                // TODO: Falta asignacion

            default:
                break;
            }
            lastOperation = CL_PARENTHESIS;
        }
        break;
        case END:
        {
            switch (lastOperation)
            {
            case ADDITION:
                result += BufferValue();
                break;
            case PRODUCT:
                result = result == 0 ? 1 : result * BufferValue();
                break;
            case ASSIGNATION:
                SetMemoryValue(BufferValue());
                break;

            default:
                break;
            }
        }
        break;

        default:
            break;
        }
    }
    else
    {
        lastOperation = currentToken;
    }
}

static void PrintResult(Token currentToken)
{
    if (!GetError())
    {
        CleanBuffer();
        PrintMemory();
        printf("%s(Parser)", BLUE_BOLD);
        if (pCounter == 0)
        {
            printf("%s La expresión es Válida\n", GREEN);
            printf("%s(Calc)%s El resultado de la expresión es: %s%i\n", CYAN_BOLD, WHITE_BOLD, CYAN_BOLD, result);
        }
        else
        {
            SetError(true);
            printf("%s Error Sintáctico\n", RED);
            printf("\t-> Paréntesis desbalanceados\n");
        }
    }
}

static void CleanGlobalVariables()
{
    // Reset console colors.
    printf("\n\e[0m");
    pCounter = 0;
    result = 0;
    lastOperation = INITIAL;
    SetError(false);
}

void CheckToken(Token currentToken, Token lastToken)
{
    if (lastToken == INITIAL)
    {
        if (currentToken == OP_PARENTHESIS)
            pCounter++;

        if (currentToken == ADDITION || currentToken == PRODUCT || currentToken == CL_PARENTHESIS)
        {
            ThrowSintacticalException(TokenToString(currentToken), "Número, Identificador o Paréntesis de Apertura '('");
            return;
        }
    }
    else
    {
        switch (currentToken)
        {
        case ASSIGNATION:
        {
            if (lastToken != IDENTIFICATOR)
                ThrowSintacticalException(TokenToString(currentToken), "Identificador");
        }
        break;
        case END:
        case ADDITION:
        case PRODUCT:
        {
            if (!(IsTokenConstant(lastToken) || lastToken == CL_PARENTHESIS))
                ThrowSintacticalException(TokenToString(currentToken), "Número, Identificador o Paréntesis de Cierre ')'");
        }
        break;
        case NUMBER:
        {
            if (!(IsTokenOperator(lastToken) || lastToken == NUMBER || lastToken == OP_PARENTHESIS))
                ThrowSintacticalException(TokenToString(currentToken), "Número, Operador o Paréntesis de Apertura '('");
        }
        break;
        case IDENTIFICATOR:
        {
            if (!(IsTokenOperator(lastToken) || lastToken == IDENTIFICATOR || lastToken == OP_PARENTHESIS))
                ThrowSintacticalException(TokenToString(currentToken), "Identificador, Operador o Paréntesis de Apertura '('");
        }
        break;
        case OP_PARENTHESIS:
        {
            pCounter++;
            if (!(IsTokenOperator(lastToken) || lastToken == OP_PARENTHESIS))
                ThrowSintacticalException(TokenToString(currentToken), "Operador o Paréntesis de Apertura '('");
        }
        break;
        case CL_PARENTHESIS:
        {
            pCounter--;
            if (!(IsTokenConstant(lastToken) || lastToken == CL_PARENTHESIS) && pCounter >= 0)
                ThrowSintacticalException(TokenToString(currentToken), "Número, Identificador o Paréntesis de Cierre ')'");
        }
        break;
        default:
            ThrowSintacticalException(TokenToString(currentToken), "[No detectado]");
        }
    }
}

static bool IsTokenOperator(Token t)
{
    return t == ADDITION || t == PRODUCT || t == ASSIGNATION;
}

static bool IsTokenConstant(Token t)
{
    return t == NUMBER || t == IDENTIFICATOR;
}

static int BufferValue()
{
    return CheckIdExistence(buffer) ? GetMemoryValue(buffer) : atoi(buffer);
}