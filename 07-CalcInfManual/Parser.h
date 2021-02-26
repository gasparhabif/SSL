#include "Scanner.h"
#include "Memory.h"

int pCounter;
int result;
Token lastOperation;

void RunScan();
void CheckToken(Token cT, Token lT);
static bool IsTokenOperator(Token t);
static bool IsTokenConstant(Token t);
static void CleanGlobalVariables();
static void PrintResult(Token t);
static int BufferValue();
static void EvaluateExpresion(Token t);