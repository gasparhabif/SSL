#include "Parser.h"

void RunProgram()
{
    printf("Ingrese la expresión a evaluar: \n");

    Program();
}

static void Program(void)
{
    EvaluateSentence();
    EvaluateSentenceList();
}

static void EvaluateSentenceList(void)
{
    RestartOnError();
    Token token = GetNextToken();
    IsTokenConstant(token) ? EvaluateSentence()
                           : EvaluateSentenceList();
}

static void EvaluateSentence(void)
{
    RestartOnError();
    Token token = GetNextToken();
    if (token == IDENTIFICATOR)
    {
        int result;
        if (IsNextToken(ASSIGNATION))
        {
            AddToMemory(buffer);
            result = EvaluateExpresion();
            SetMemoryValue(result);
        }
        else
        {
            result = EvaluateExpresion();
        }
        PrintResult(result);
    }
    else
    {
        int result = EvaluateExpresion();
        CheckNextToken(END);
        PrintResult(result);
    }
}

static int EvaluateExpresion(void)
{
    RestartOnError();
    int result = EvaluateTerm();
    return IsNextToken(ADDITION) ? result + EvaluateExpresion()
                                 : result;
}

static int EvaluateTerm(void)
{
    RestartOnError();
    int result = EvaluateFactor();
    return IsNextToken(PRODUCT) ? result * EvaluateTerm()
                                : result;
}

static int EvaluateFactor(void)
{
    RestartOnError();
    int result;
    Token token = GetNextToken();
    switch (token)
    {
    case END:
    case IDENTIFICATOR:
    case NUMBER:
        return BufferValue();
    case OP_PARENTHESIS:
        result = EvaluateExpresion();
        CheckNextToken(CL_PARENTHESIS);
        break;
    default:
        ThrowSintacticalException(TokenToString(token), "Número, Identificador o Paréntesis de Apertura '('");
        break;
    }
    return result;
}

static bool IsNextToken(Token expectedToken)
{
    return GetNextToken() == expectedToken;
}

static void CheckNextToken(Token expectedToken)
{
    Token currentToken = GetNextToken();
    if (currentToken != expectedToken)
        ThrowSintacticalException(TokenToString(currentToken), TokenToString(expectedToken));
}

static bool IsTokenConstant(Token t)
{
    return t == NUMBER || t == IDENTIFICATOR;
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
    printf("\n\e[0m");
    SetError(false);
}

static void RestartOnError(void)
{
    if (GetError())
    {
        CleanGlobalVariables();
        CleanBuffer();
        RunProgram();
    }
}