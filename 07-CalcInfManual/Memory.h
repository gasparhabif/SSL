#include "Constants.h"

struct MemoryBlock
{
    char id[100];
    int value;
};

struct MemoryBlock memory[MEMORY_SIZE];

void AddToMemory(char *id);
void SetMemoryValue(int i);
void PrintMemory();
static struct MemoryBlock GetMemoryBlock(char *id);
static void ThrowMemoryException(int e);
static int FindFreeSpace();
static bool CheckIdExistence(char *id);