#include "Scanner.h"
#include "Memory.h"

static int pCounter;
static int result;
static bool openedAssignation = false;

void RunProgram();
void CheckToken(Token cT, Token lT);
static bool IsTokenOperator(Token t);
static bool IsTokenConstant(Token t);
static void CleanGlobalVariables();
static void PrintResult();
static int EvaluateExpresion(Token t, int i);