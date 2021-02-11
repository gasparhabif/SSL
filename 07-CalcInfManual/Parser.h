#include "Scanner.h"

#define WHITE "\e[0;37m"
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define BLUE_BOLD "\e[1;34m"

Token lastToken;
int pCounter;

void Run_Scan();
static void ThrowSintacticalError(Token actual, char *expected);
void CheckToken(Token t);
static bool IsTokenOperator(Token t);
static bool IsTokenConstant(Token t);
static void CleanGlobalVariables();