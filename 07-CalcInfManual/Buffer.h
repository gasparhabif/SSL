#include "Constants.h"

char buffer[BUFFER_SIZE];
static int bufferPos;

void CleanBuffer();
void AddCharToBuffer(char c);
int BufferValue();
static void PrintBuffer();