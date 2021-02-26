#include "Memory.h"
#include "ErrorHandler.h"

void AddToMemory(char *id)
{
    if (!CheckIdExistence(id))
    {
        int pos = FindFreeSpace();
        if (pos != -1)
        {
            struct MemoryBlock memBlock;
            strcpy(memBlock.id, id);
            memBlock.value = 0;
            memory[pos] = memBlock;
        }
    }
    else
    {
        overwritePos = GetMemoryPos(id);
        ThrowMemoryException(2);
    }
}

static int GetMemoryPos(char *id)
{
    for (int i = 0; i <= LastMemPos(); i++)
    {
        struct MemoryBlock mem = memory[i];
        if (!strcmp(mem.id, id))
            return i;
    }
    ThrowMemoryException(3);
    return -1;
}

bool CheckIdExistence(char *id)
{
    for (int i = 0; i < FindFreeSpace(); i++)
    {
        if (!strcmp(id, memory[i].id))
            return true;
    }
    return false;
}

void SetMemoryValue(int value)
{
    overwritePos = overwritePos == -1 ? LastMemPos() : overwritePos;
    memory[overwritePos].value = value;
    overwritePos = -1;
}

int GetMemoryValue(char *id)
{
    for (int i = 0; i <= LastMemPos(); i++)
    {
        struct MemoryBlock mem = memory[i];
        if (!strcmp(mem.id, id))
            return mem.value;
    }
    ThrowMemoryException(3);
    return -1;
}

static int LastMemPos()
{
    return FindFreeSpace() - 1;
}

int FindFreeSpace()
{
    int pos = 0;
    while (memory[pos].id[0] != '\0')
    {
        pos++;
        if (pos >= MEMORY_SIZE)
        {
            ThrowMemoryException(1);
            return -1;
        }
    }
    return pos;
}

void PrintMemory()
{
    for (int i = 0; i < FindFreeSpace(); i++)
    {
        printf("%s(Memory)%s Encontrado el identificador: %s ", RED_BOLD, WHITE, memory[i].id);
        printf("con el valor: %i ", memory[i].value);
        printf("[En la posición de memoria %i]\n", i);
    }
}