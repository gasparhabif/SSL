# Diseño a nivel Léxico del Lenguaje

El diseño a nivel léxico se vera separado en cuatro categorías, donde cada categoría tendrá un Lenguaje Regular. 
Dichas categorías serán las siguientes: 

 1. Operadores: { +, * }
 2. Números: [0-9]
 3. Identificadores: [A-Za-z]
 4. Parentesis: [(, )]


# Diseño a nivel Sintáctico del Lenguaje

Las expresiones válidas a nivel sintáctico serán las compuestas por los elementos gramaticales correspondientes a las categorías previamente definidas de forma tal que: 

 - Expresión -> Elemento
 - Expresión -> Elemento Operador Elemento
 - Expresión -> ParentesisApertura Elemento Operador Elemento ParentesisCierre
 - Expresión -> ParentesisApertura Elemento Operador ParentesisCierre Expresion

Donde:  
 - Elemento: Número | Identificador
 - Operador: + | *

  