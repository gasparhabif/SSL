#include "Scanner.h"

#define WHITE "\e[0;37m"
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define BLUE_BOLD "\e[1;34m"

Token lastToken;
int pCounter;
int result;
bool operationStarted;

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