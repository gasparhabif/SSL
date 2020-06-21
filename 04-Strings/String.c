// String.c
// Implementation of the following functions: GetLength, IsEmpty, Power, Substring
// Gaspar Habif
// 20200620

#include "String.h"

unsigned int GetLength(const char *characterString)
{
    unsigned int i = 0;
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
    int length = GetLength(characterString);
    int returnLength = length * power;

    char *returnString = (char *)malloc((returnLength + 1) * sizeof(char));

    for (unsigned int i = 0; i < returnLength; ++i)
    {
        returnString[i] = characterString[i % length];
    }

    returnString[returnLength] = '\0';

    return returnString;
}

char *Substring(const char *characterString, unsigned int start, unsigned int end)
{
    unsigned int returnLength = start - end;
    char *returnString = (char *)malloc((returnLength + 1) * sizeof(char));

    for (unsigned int i = 0; i < end - start; ++i)
    {
        returnString[i] = characterString[start + i];
    }

    returnString[returnLength] = '\0';

    return returnString;
}
