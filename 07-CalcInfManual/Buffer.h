#include "Constants.h"

#define BUFFER_SIZE 100

char buffer[BUFFER_SIZE];
static int bufferPos;

void CleanBuffer();
void AddCharToBuffer(char c);
static void PrintBuffer();