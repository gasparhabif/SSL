#include "Scanner.h"

void RunProgram(void);
static bool Program();
static bool CheckSentnece(void);
static bool CheckExpresion(void);
static bool isConstant(Token);
static bool ThrowSintacticalError(char *, char *);