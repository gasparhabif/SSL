#include "Constants.h"

#define MEMORY_SIZE 100
struct MemoryBlock
{
    char id[100];
    int value;
};

struct MemoryBlock memory[MEMORY_SIZE];

void AddMemoryBlock(char *id, int v);
int GetMemoryValue(char *id);
void PrintMemory();
bool CheckIdExistence(char *id);
static void SetMemoryBlock(char *id, int v, int p);
static int FindFreeSpace();
static int LastMemPos();
static int GetMemoryPos(char *id);