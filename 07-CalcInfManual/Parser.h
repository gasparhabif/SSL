#include "Scanner.h"
#include "Memory.h"

static int pCounter;
static int result;
static bool openedAssignation = false;

void RunScan();
void CheckToken(Token cT, Token lT);
static bool IsTokenOperator(Token t);
static bool IsTokenConstant(Token t);
static void CleanGlobalVariables();
static void PrintResult(Token t);
static int EvaluateExpresion(Token t, int i);