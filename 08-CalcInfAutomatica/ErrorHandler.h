static void ThrowError(void);
bool GetError(void);
void SetError(bool b);
void ThrowLexicalException(void);
void ThrowSintacticalException(char *cT, char *eT);
void ThrowBufferException(void);
void ThrowMemoryException(int e);