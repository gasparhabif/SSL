#include "Buffer.h"
#include "Memory.h"

void CleanBuffer(void)
{
    memset(buffer, 0, sizeof buffer);
    bufferPos = 0;
    printf("%s(Buffer)%s Limpiado\n", YELLOW_BOLD, WHITE);
}

void AddCharToBuffer(char c)
{

    if (bufferPos < (BUFFER_SIZE - 1))
    {
        buffer[bufferPos++] = c;
        PrintBuffer();
    }
    else
    {
        ThrowBufferException();
    }
}

static void PrintBuffer(void)
{
    printf("%s(Buffer)%s Actualmente almacenado en Buffer: %s\n", YELLOW_BOLD, WHITE, buffer);
}

int BufferValue(void)
{
    return IsBufferAlpha() ? GetMemoryValue(buffer) : atoi(buffer);
}

static bool IsBufferAlpha(void)
{
    for (int i = 0; i < bufferPos; i++)
    {
        if (strchr(POSSIBLE_NUM, buffer[i]) != NULL)
            return false;
    }
    return true;
}