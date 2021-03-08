# 14. Calculadora Infija: Construcción Manual — Iteración #1

### 14.1. Objetivos
-   Experimentar el diseño de la especificación de lenguajes a nivel léxico y sintáctico.
-   Experimentar la implementación manual del nivel léxico y sintáctico de lenguajes.


### 14.2. Temas
-   Especificación del nivel Léxico y Sintáctico.
-   Implementación del nivel Léxico y Sintáctico.
-   Implementación de Scanner
-   Implementación de Parser.

### 14.3. Problema
Análisis de expresiones aritméticas infijas simples que incluya:
-   Números naturales con representación literal en base 10.
-   Identificadores de variables.
-   Adición.
-   Multiplicación.

Ejemplos de expresiones incorrectas:

    A+2*3
    2*A+3
    A
    2

Ejemplos de expresiones incorrectas:

    +
    42+ 
    +A
### 14.4. Solución
Especificar e implementar los niveles léxicos y sintácticos del lenguaje.
### 14.5. Restricciones
• El scanner y el parser deben estar lógicamente separados.  
• El parser se comunica con el scanner con la operación `GetNextToken`, el scanner toma los caracteres de `stdin` con `getchar`.

##### Crédito Extra: Estructurar la solución con separación física entre scanner y parser.

### 14.6. Tareas

- [X] 1. Diseñar el nivel léxico del lenguaje.  
- [X] 2. Diseñar el nivel sintáctico del lenguaje. 
- [X] 3. Implementar el scanner.  
- [X] 4. Implementar el parser.  
- [X] 5. Probar.

### 14.7. Productos

     DD-CalcInfManual 
	    |-- Calc.md
	    |-- Makefile
	    |-- Scanner.h	// Opcional
	    |-- Parser.h	// Opcional
	    |-- Parser.c	// Opcional
	    |-- Scanner.c	// Opcional
	    |-- Calc.c 