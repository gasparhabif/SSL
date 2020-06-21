#include <assert.h>
#include "String.h"

// Test GetLength()
void testGetLength()
{
    // Test cadena estática con constante de longitud 8
    char wordWithLength[8 + 1] = "Sintaxis";
    assert(GetLength(wordWithLength) == 5);

    // Test cadena estática con constante de longitud 0
    char wordWithNoLength[8 + 1] = "";
    assert(GetLength(wordWithNoLength) == 0);

    // Test cadena constante con longitud 3
    size_t length3 = GetLength("SSL");
    assert(length3 == 3);

    // Test cadena constante con longitud 0
    size_t length0 = GetLength("");
    assert(length0 == 0);
}

// Test IsEmpty()
void testIsEmpty()
{

    // Test cadena estática con constante no vacía
    char notEmptyWord[8 + 1] = "Sintaxis";
    assert(!IsEmpty(notEmptyWord));

    // Test cadena estática con constante vacía
    char emptyWord[8 + 1] = "";
    assert(IsEmpty(emptyWord));

    // Test cadena constante no vacía
    bool notEmpty = IsEmpty("SSL");
    assert(!notEmpty);

    // Test cadena constante vacía
    bool empty = IsEmpty("");
    assert(empty);
}

// Test Power
void testPower()
{
    // Test cadena estática constante no vacía con potenciador de 3
    int power = 3;
    char initialWord[3 + 1] = "SSL";
    char expectedWord[9 + 1] = "SSLSSLSSL";

    assert(Power(initialWord, power) == expectedWord);

    // Test cadena constante con longitud esperada de 9
    char *resultWord = Power("SSL", power);
    assert(GetLength(resultWord) == 9);
}

// Test Substring
void testPower()
{
    // Test cadena estática constante
    char initialWord[37 + 1] = "Sintaxis y Semantica de los Lenguajes";
    char expectedWord[8 + 1] = "Sintaxis";

    assert(Substring(initialWord, 0, 9) == expectedWord);
}