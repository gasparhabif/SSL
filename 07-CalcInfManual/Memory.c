#include "Memory.h"

void AddToMemory(char *id)
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

void SetMemoryValue(int value)
{
    int lastPos = FindFreeSpace() - 1;
    memory[lastPos].value = value;
}

int FindFreeSpace()
{
    int pos = 0;
    while (memory[pos].id[0] != '\0')
    {
        pos++;
        if (pos >= MEMORY_SIZE)
        {
            ThrowOutOfMemoryException();
            return -1;
        }
    }
    return pos;
}

static void ThrowOutOfMemoryException()
{
    printf("%s(Memory)%s No hay más espacios disponibles en memoria.\n", RED_BOLD, WHITE);
}

void PrintMemory()
{
    int lastPos = FindFreeSpace();
    for (int i = 0; i < lastPos; i++)
    {
        printf("%s(Memory)%s Encontrado el identificador: %s ", RED_BOLD, WHITE, memory[i].id);
        printf("con el valor: %i ", memory[i].value);
        printf("[En la posición de memoria %i]\n", i);
    }
}