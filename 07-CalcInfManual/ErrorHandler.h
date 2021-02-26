#include "Constants.h"

static void ThrowError();
bool GetError(void);
void SetError(bool b);
void ThrowLexicalException(void);
void ThrowSintacticalException(char *cT, char *eT);
void ThrowBufferException();
void ThrowMemoryException(int e);