#include "Scanner.h"
#include "Memory.h"

Token lastToken;
int pCounter;
int result;
Token lastOperation;

void RunScan();
static void ThrowSintacticalError(Token actual, char *expected);
void CheckToken(Token t);
static bool IsTokenOperator(Token t);
static bool IsTokenConstant(Token t);
static bool AnyKindError(Token t);
static void CleanGlobalVariables();
static void PrintResult();
static int BufferValue();
static void EvaluateExpresion();