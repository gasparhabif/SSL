#include "Scanner.h"
#include "Memory.h"

void RunProgram(void);
static void Program(void);
static void EvaluateSentence(void);
static int EvaluateExpresion(void);
static int EvaluateTerm(void);
static int EvaluateFactor(void);
static bool IsExpectedToken(Token);
static void CheckNextToken(Token);
static void PrintResult(int);
static void CleanGlobalVariables(void);
static void RestartOnError(void);