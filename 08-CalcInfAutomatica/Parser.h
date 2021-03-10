#include "Scanner.h"
#include "Memory.h"

static int pCounter;
static int result;
static bool openedAssignation = false;

void RunProgram();
static void Program(Token ct, Token lT, int lO);
static void CheckToken(Token cT, Token lT);
static bool IsTokenOperator(Token t);
static bool IsTokenConstant(Token t);
static int EvaluateExpresion(Token t, int i);
static void ResolveExpresion(Token t, int i);
static void PrintResult();
static void CleanGlobalVariables();