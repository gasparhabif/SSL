#include "Memory.h"

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
        ThrowMemoryException(2);
    }
}

static bool CheckIdExistence(char *id)
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
            ThrowMemoryException(1);
            return -1;
        }
    }
    return pos;
}

static void ThrowMemoryException(int e)
{
    printf("%s(Memory)%s ", RED_BOLD, WHITE);
    switch (e)
    {
    case 1:
        printf("No hay más espacios disponibles en memoria.\n");
        break;
    case 2:
        printf("El identificador ingresado ya existe, será sobreescrito con el nuevo valor.\n");
        break;
    default:
        break;
    }
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