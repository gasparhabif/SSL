#include "Constants.h"

struct MemoryBlock
{
    char *id;
    int value;
};

struct MemoryBlock memory[MEMORY_SIZE];

static void AddToMemory(char *id, int v);
static struct MemoryBlock GetFromMemory(char *id);
static void ThrowOutOfMemoryError();
// static int FindFreeSpace();