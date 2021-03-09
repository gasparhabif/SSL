#include "Buffer.h"
#include "Memory.h"

void CleanBuffer()
{
    while (bufferPos >= 0)
    {
        buffer[bufferPos] = '\0';
        bufferPos--;
    }
    bufferPos = 0;
    printf("%s(Buffer)%s Limpiado\n", YELLOW_BOLD, WHITE);
}

void AddStringToBuffer(char *str)
{
    if (bufferPos < (BUFFER_SIZE - 1))
    {
        strcpy(buffer, str);
        PrintBuffer();
    }
    else
    {
        ThrowBufferException();
    }
}

static void PrintBuffer()
{
    printf("%s(Buffer)%s Actualmente almacenado en Buffer: %s\n", YELLOW_BOLD, WHITE, buffer);
}

int BufferValue()
{
    return CheckIdExistence(buffer) ? GetMemoryValue(buffer) : atoi(buffer);
}