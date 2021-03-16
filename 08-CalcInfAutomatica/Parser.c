#include "Parser.h"

void RunProgram()
{
    printf("Ingrese la expresión a evaluar: \n");
    Program();
}

static void Program(void)
{
    EvaluateSentence();
}

static void EvaluateSentence(void)
{
    int result;
    currentToken = GetNextToken();
    RestartOnError();
    if (IsExpectedToken(IDENTIFICATOR))
    {
        RestartOnError();
        char tempID[BUFFER_SIZE];
        strcpy(tempID, buffer);
        CleanBuffer();

        if (IsExpectedToken(ASSIGNATION))
        {
            result = EvaluateExpresion();
            AddMemoryBlock(tempID, result);
        }
        else
        {
            strcpy(buffer, tempID);
            result = EvaluateExpresion();
        }
        PrintResult(result);
    }
    else
    {
        RestartOnError();
        result = EvaluateExpresion();
        PrintResult(result);
    }
}

static int EvaluateExpresion()
{
    int result = EvaluateTerm();
    return IsExpectedToken(ADDITION) ? result + EvaluateExpresion()
                                     : result;
}

static int EvaluateTerm()
{
    int result = EvaluateFactor();
    return IsExpectedToken(PRODUCT) ? result * EvaluateTerm()
                                    : result;
}

static int EvaluateFactor()
{
    int result;
    RestartOnError();
    switch (currentToken)
    {
    case IDENTIFICATOR:
    case NUMBER:
        result = BufferValue();
        RestartOnError();
        CleanBuffer();
        break;
    case OP_PARENTHESIS:
        currentToken = GetNextToken();
        result = EvaluateExpresion();
        if (!(IsExpectedToken(CL_PARENTHESIS)))
            ThrowSintacticalException(TokenToString(currentToken), "Paréntesis de Cierre ')'");
        else
            return result;
        break;
    case ADDITION:
    case PRODUCT:
        if (strlen(buffer))
        {
            result = BufferValue();
            RestartOnError();
            CleanBuffer();
            return result;
        }
        else
        {
            ThrowSintacticalException(TokenToString(currentToken), "Número, Identificador o Paréntesis de Apertura '('");
            CleanGlobalVariables();
            RunProgram();
        }
        break;
    default:
        ThrowSintacticalException(TokenToString(currentToken), "Número, Identificador o Paréntesis de Apertura '('");
        CleanGlobalVariables();
        RunProgram();
        break;
    }
    currentToken = GetNextToken();
    return result;
}

static bool IsExpectedToken(Token expectedToken)
{
    RestartOnError();
    bool res = expectedToken == currentToken;
    if (res)
        currentToken = GetNextToken();
    return res;
}

static void PrintResult(int result)
{
    if (!GetError())
    {
        PrintMemory();
        printf("%s(Parser) ", BLUE_BOLD);
        printf("%sLa expresión es Válida\n", GREEN);
        printf("%s(Calc)%s El resultado de la expresión es: %s%i\n", CYAN_BOLD, WHITE_BOLD, CYAN_BOLD, result);
    }
    CleanGlobalVariables();
    RunProgram();
}

static void CleanGlobalVariables(void)
{
    // Reset console colors.
    currentToken = -1;
    printf("\n\e[0m");
    SetError(false);
}

static void RestartOnError(void)
{
    if (GetError())
    {
        CleanYylex();
        CleanBuffer();
        CleanGlobalVariables();
        RunProgram();
    }
}