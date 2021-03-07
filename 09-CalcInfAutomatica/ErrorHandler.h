static void ThrowError();
bool GetError(void);
void SetError(bool b);
void ThrowLexicalException(void);
void ThrowSintacticalException(char const *ex);
void ThrowMemoryException(int e);