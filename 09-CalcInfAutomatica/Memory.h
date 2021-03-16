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
void PrintMemory(void);
static bool CheckIdExistence(char *id);
static void SetMemoryBlock(char *id, int v, int p);
static int FindFreeSpace(void);
static int LastMemPos(void);
static int GetMemoryPos(char *id);