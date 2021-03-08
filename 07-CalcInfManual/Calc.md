## Diseño a Nivel Léxico

El diseño a nivel léxico está dado por una máquina de estado junto a una gramática léxica que identifica los tokens y lexemas válidos.

### Tokens Válidos 
| TOKEN          | REPRESENTA | UTILIZACIÓN                                                                         |
| -------------- | ---------- | ----------------------------------------------------------------------------------- |
| INITIAL        |            | Indica el comienzo del programa.                                                    |
| IDENTIFICATOR  | [A-Za-z]   | Utilizado para representar un carácter de los identificadores de variables.         |
| NUMBER         | [0-9]      | Utilizado para representar un número natural con representación literal en base 10. |
| ADDITION       | +          | Utilizado para representar la adición.                                              |
| PRODUCT        | *          | Utilizado para representar la multiplicación.                                       |
| OP_PARENTHESIS | (          | Utilizado para representar el paréntesis de apertura.                               |
| CL_PARENTHESIS | )          | Utilizado para representar el paréntesis de cierre.                                 |
| ASSIGNATION    | =          | Utilizado para representar la asignación de un valor a su correspondiente variable. |
| END            | EOF        | Utilizado para representar el fin de la expresión actual.                           |

## Implementación a Nivel Léxico

La implementación a nivel léxica se compone por un `Scanner` que se encarga de tomar los caracteres uno a uno del *stdin* mediante la función `getchar()`. Luego los identifica en base a la tabla de tokens válidos y devuelve el token que represente a dicho **char** a través de la función `GetNextToken()`.

>  **Error Léxico:** Al detectarse un carácter que no sea válido para ningún
> lexema del lenguaje, el `ErrorHandler` se ocupa de informar la
> excepción correspondiente, sin romper la ejecución del programa.

  

## Diseño a Nivel Sintáctico

Las expresiones válidas a nivel sintáctico serán aquellas que respondan a la **gramática independiente del contexto (GCI)** previamente generada. 
Por otra parte para poder analizar sintácticamente las expresiones de manera correcta se usa el análisis de tipo **Descendente Recursivo** donde se van reduciendo las expresiones para poder obtener el valor final. 

### GCI

    programa 		: INITIAL sentenceList END
    
    sentenceList 	: sentence { sentence }
    
    sentence		: IDENTIFICATOR ASSIGNATION expresion
				    | expresion
				    
    expresion		: term
				    | expresion ADITION term
				    
    term			: factor
					| term PRODUCT factor

	factor			: IDENTIFICATOR
					| NUMBER
					| OP_PARENTHESIS expresion CL_PARENTHESIS
 
## Implementación a Nivel Sintáctico

La implementación a nivel sintáctico esta a cargo del `Parser` compuesto de funciones donde se destacan las siguientes: 

- RunScan(): Da comienzo al programa y se encarga de la invocación de las rutinas recursivas.
- CheckToken(Token, Token): Valida que el token actual tenga sentido sintáctico en base al token anterior. 
- EvaluateExpresion(Token, int): Con el token actual y la última operación realizada  se encarga de operar, guardando el resultado en una variable global.


>  **Error Sintactico:** Al detectarse la presencia de un Token seguido
> de otro de manera que la secuencia no forma parte de la gramática del
> programa, el `ErrorHandler` se ocupa de informar la excepción
> correspondiente, sin romper la ejecución del programa.

## Funciones del Buffer
 
 El Buffer esta compuesto por un arreglo de **char** con un soporte máximo de 100 caracteres. 
 
 Se encarga de almacenar temporalmente los caracteres que son leídos por la función `getchar()` para el caso de Tokens de tipo **IDENTIFICATOR** o **NUMBER** que estén compuestos por mas de un carácter *(por ejemplo: el número **2020** o la variable **ssl**)*
 
 Se utiliza un índice cuyo valor inicial es 0 para determinar en qué posición debe ser agregado el carácter. 
 
 A la hora de utilizar su valor la función `BufferValue()` es quien determina si se trata de un identificador o del valor literal almacenado.
 
 Una vez finalizado su uso, y ante la aparición de otro tipo de Token que no sea constante, se procede a limpiar el buffer vaciando el arreglo e igualando la posición del indice nuevamente a 0. 
 

>  **Error de Buffer:** En el caso de que el lexema supere la cantidad de caracteres validos para el Buffer, el `ErrorHandler` se ocupa de informar la excepción correspondiente, sin romper la ejecución del programa.

## Funciones de la Memoria

Compuesta por un arreglo de *structs*, con un soporte máximo de 100 identificadores. Se encargada de almacenar los valores que están asociados a un identificador en la primera posición libre de la memoria. Dichos *structs* están compuestos de la siguiente manera:
```C
struct  MemoryBlock 
{
	char  id[100];
	int  value;
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