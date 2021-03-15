#include "Constants.h"

char buffer[BUFFER_SIZE];
static int bufferPos;

void CleanBuffer(void);
void AddCharToBuffer(char c);
int BufferValue(void);
static void PrintBuffer(void);
static bool IsBufferAlpha(void);