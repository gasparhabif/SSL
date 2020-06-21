// String.c
// Implementation of the following functions: GetLength, IsEmpty, Power, Substring
// Gaspar Habif
// 20200620

#include "String.h"

size_t GetLength(const char *characterString)
{
    size_t i = 0;
    while (characterString[i] != '\0')
        i++;

    return i;
}

bool IsEmpty(const char *characterString)
{
    return GetLength(characterString) == 0;
}

char *Power(const char *characterString, unsigned int power)
{
    size_t length = GetLength(characterString);
    size_t returnLength = length * power;

    char *returnString = (char *)malloc((returnLength + 1) * sizeof(char));

    for (size_t i = 0; i < returnLength; ++i)
    {
        returnString[i] = characterString[i % length];
    }

    returnString[returnLength] = '\0';

    return returnString;
}

char *Substring(const char *characterString, unsigned int start, unsigned int end)
{
    size_t returnLength = start - end;
    char *returnString = (char *)malloc((returnLength + 1) * sizeof(char));

    for (size_t i = 0; i < end - start; ++i)
    {
        returnString[i] = characterString[start + i];
    }

    returnString[returnLength] = '\0';

    return returnString;
}
