#include "Scanner.h"
#include "Memory.h"

void RunProgram(void);
static void CleanGlobalVariables(void);
static void PrintResult(int result);
void CleanYylex(void);