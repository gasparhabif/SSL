#include "Memory.h"

void AddMemoryBlock(char *id, int value)
{
    int pos;
    if (CheckIdExistence(id))
        pos = GetMemoryPos(id);
    else
        pos = FindFreeSpace();

    SetMemoryBlock(id, value, pos);
}

static void SetMemoryBlock(char *id, int value, int pos)
{
    struct MemoryBlock memBlock;
    strcpy(memBlock.id, id);
    memBlock.value = value;
    memory[pos] = memBlock;
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

int GetMemoryValue(char *id)
{
    for (int i = 0; i <= LastMemPos(); i++)
    {
        struct MemoryBlock mem = memory[i];
        if (!strcmp(mem.id, id))
        {
            printf("%s(Memory)%s Identificador reconocido: %s junto a su valor: %i\n", RED_BOLD, WHITE, id, mem.value);
            return mem.value;
        }
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