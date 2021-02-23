#include "Constants.h"

struct MemoryBlock
{
    char id[100];
    int value;
};

struct MemoryBlock memory[MEMORY_SIZE];
static int overwritePos = -1;

void AddToMemory(char *id);
void SetMemoryValue(int i);
int GetMemoryValue(char *id);
bool CheckIdExistence(char *id);
void PrintMemory();
static void ThrowMemoryException(int e);
static int FindFreeSpace();
static int LastMemPos();
static int GetMemoryPos(char *id);