// String.h
// Prototype of the following functions: GetLength, IsEmpty, Power, Substring
// Gaspar Habif
// 20200620

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// GetLength
// - Precondición y Argumentos: Consta de un unico argumento que sera una cadena que se espera,
//   finalice en caracter nulo ('\0').
// - Postcondición y Resultados: Retorna un entero positivo, incluyendo el cero, que representa la cantidad de
//   caracteres que componen la cadena de la precondición.
size_t GetLength(const char *characterString);

// IsEmpty
// - Precondición y Argumentos: Consta de un unico argumento que sera una cadena que se espera,
//   finalice en caracter nulo ('\0').
// - Postcondición y Resultados: Retorna un valor booleano, donde True representa que la cadena está vacía
//   y False que la cadena contiene algun caracter.
bool IsEmpty(const char *characterString);

// Power
// - Precondición y Argumentos: Consta de dos argumentos, por una parte characterString que sera
//   una cadena que se espera, finalice en caracter nulo ('\0'). Y por otra parte power que
//   representa la cantidad de veces que se repetira la cadena
// - Postcondición y Resultados: Retorna un puntero a una cadena que contiene
//   el resultado de potenciar la cadena.
char *Power(const char *characterString, unsigned int power);

// Substring
// - Precondición y Argumentos: Consta de tres argumentos;
//         1. characterString que sera una cadena que se espera, finalice en caracter nulo ('\0').
//         2. start que representa el indice inicial desde el que se buscar recortar
//         3. end que representa el indice final (exluyente) hasta el que se busca recortar
// - Postcondición y Resultados: Retorna un puntero a una cadena que contiene
//   el resultado de recortar la cadena con el indice y la longitud indicadas.
char *Substring(const char *characterString, unsigned int start, unsigned int end);