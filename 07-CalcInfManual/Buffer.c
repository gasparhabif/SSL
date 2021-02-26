#include "Buffer.h"

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

bool AddCharToBuffer(char c)
{

    if (bufferPos < (BUFFER_SIZE - 1))
    {
        buffer[bufferPos++] = c;
        PrintBuffer();
        return true;
    }
    else
    {
        return false;
    }
}

static void PrintBuffer()
{
    printf("%s(Buffer)%s Actualmente almacenado en Buffer: ", YELLOW_BOLD, WHITE);

    for (int i = 0; i <= bufferPos; i++)
        printf("%c", buffer[i]);
    printf("\n");
}