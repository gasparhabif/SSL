
## Diseño a Nivel Léxico

El diseño a nivel léxico está dado por una máquina de estado junto a una gramática léxica que identifica los tokens y lexemas válidos.

### Tokens Válidos

| TOKEN          | REPRESENTA | UTILIZACIÓN                                                                         |
| -------------- | ---------- | ----------------------------------------------------------------------------------- |
| INITIAL        |            | Indica el comienzo del programa.                                                    |
| IDENTIFICATOR  | [A-Za-z]   | Utilizado para representar un carácter de los identificadores de variables.         |
| NUMBER         | [0-9]      | Utilizado para representar un número natural con representación literal en base 10. |
| ADDITION       | +          | Utilizado para representar la adición.                                              |
| PRODUCT        | *          | Utilizado para representar la multiplicación.                                       |
| OP_PARENTHESIS | (          | Utilizado para representar el paréntesis de apertura.                               |
| CL_PARENTHESIS | )          | Utilizado para representar el paréntesis de cierre.                                 |
| ASSIGNATION    | =          | Utilizado para representar la asignación de un valor a su correspondiente variable. |
| END            | EOF        | Utilizado para representar el fin de la expresión actual.                           |

  

## Implementación a Nivel Léxico
  
La implementación a nivel léxica se compone por un `Scanner` que esta desarrollado con la herramienta `lex/flex` pero manteniendo la interfaz establecida en la iteración anterior para `Scanner.h`.

Dada una expresión regular se identifica un lexema para luego asociarlo al token que represente a través de la función `GetNextToken()` la cual a su vez invoca a la función propia de flex `yylex()`.

Para mantener el funcionamiento del Buffer y de la Memoria se procede a copiar el valor de la variable *yytext* dentro del Buffer, quien luego distingue dentro del Parser si debe almacenar en memoria el valor.

>  **Error Léxico:** Al detectarse un carácter que no sea válido para ningún
> lexema del lenguaje, el `ErrorHandler` se ocupa de informar la
> excepción correspondiente, sin romper la ejecución del programa.

  

  

## Diseño a Nivel Sintáctico

En esta iteración se desarrolla el `Parser` utilizando la herramienta **Bison** pero manteniendo la interfaz previa y su llamado desde Calc. 

Las expresiones válidas a nivel sintáctico serán aquellas que respondan a la **gramática libre de contexto (CFG)** previamente generada.

Por otra parte para poder analizar sintácticamente las expresiones de manera correcta se usa el análisis de tipo **Descendente Recursivo** donde se van reduciendo las expresiones para poder obtener el valor final. Esta recursión es a izquierda ya que de lo contrario YACC utilizaria demasiada memoria para mantener todos los comandos/tokens ingresados en el stack.

  

### CFG

    programa 	: INITIAL sentenceList END
    
    sentenceList	: sentence { sentence }
    
    sentence	: IDENTIFICATOR ASSIGNATION expresion
    		| expresion
				    
    expresion	: term
    		| expresion ADITION term
				    
    term		: factor
    		| term PRODUCT factor

	factor		: IDENTIFICATOR
			| NUMBER
			| OP_PARENTHESIS expresion CL_PARENTHESIS

## Implementación a Nivel Sintáctico

Internamente la función `RunProgram` llama a la función propia de **Bison** `yyparse()`, quien a su vez lee la secuencia de tokens con la función `yylex()` del `Scanner`.  

>  **Error Sintactico:** Al detectarse la presencia de un Token seguido
> de otro de manera que la secuencia no forma parte de la gramática del
> programa, el `ErrorHandler` se ocupa de informar la excepción
> correspondiente, sin romper la ejecución del programa.

  

## Funciones del Buffer

En esta iteración el Buffer fue removido ya que no es necesario almacenar valores de forma temporal. **Bison** se ocupa directamente de esto.

## Funciones de la Memoria

Compuesta por un arreglo de *structs*, con un soporte máximo de 100 identificadores. Se encargada de almacenar los valores que están asociados a un identificador en la primera posición libre de la memoria. Dichos *structs* están compuestos de la siguiente manera:

```C
struct MemoryBlock
{
	char id[100];
	int value;
};
```

Al agregarse un nuevo bloque de memoria se comprueba que no exista previamente un bloque con el mismo identificador. En caso de existir sobreescribe el valor de dicho bloque y lo informa mediante el `ErrorHandler`.

  

Para definir dónde debe agregarse el nuevo bloque se recorre el arreglo hasta encontrar una posición donde su ID sea EOF. En caso de no encontrarse ninguna posición libre, se informa mediante una excepción.

  

A la hora de utilizar un identificador en una expresión se busca en base al ID dentro del arreglo de structs hasta dar con su correspondiente valor. En caso de no encontrar el ID solicitado, nuevamente el `ErrorHandler` acude a nuestro rescate.

  

>  **Error de Memoria:** El `ErrorHandler` logra informar la excepción
> de los siguientes tipos de errores de memoria, sin romper la ejecución del programa:
>  1. No hay más espacios disponibles en memoria.
>  2. El identificador ingresado ya existe, en cuyo caso será sobreescrito con el nuevo valor.
>  3. El identificador solicitado no existe en memoria.