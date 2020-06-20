// String.c
// Implementation of the following functions: GetLength, IsEmpty, Power, Substring
// Gaspar Habif
// 20200620

#include "String.h"

size_t GetLength(const char *characterString) {
    size_t index = 0;
    while (characterString[index] != '\0')
        index++;

    return index;
}

bool IsEmpty(const char *characterString) {
    return GetLength(characterString) == 0;
}

char *Power(const char *characterString, unsigned int power) {
    return "";
}

char *Substring(const char *characterString, unsigned int start, unsigned int length);
{
    return "";
}
