#include "Memory.h"

static void AddToMemory(char *id, int value)
{
}

static struct MemoryBlock GetFromMemory(char *id)
{
    return memory[0];
}

// static int FindFreeSpace()
// {
//     int pos = 0;
//     while (memory[pos].id != NULL)
//     {
//         pos++;
//         if (pos >= MEMORY_SIZE)
//         {
//             ThrowOutOfMemoryError();
//             break;
//         }
//     }
//     return pos;
// }

static void ThrowOutOfMemoryError()
{
    printf("%s(Memory)%s No hay más espacios disponibles en memoria.\n", RED_BOLD, WHITE);
}