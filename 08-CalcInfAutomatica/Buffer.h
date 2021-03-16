#include "Constants.h"

char buffer[BUFFER_SIZE];

void CleanBuffer(void);
void AddStringToBuffer(char *s);
int BufferValue(void);
static void PrintBuffer(void);
static bool IsBufferAlpha(void);