# Especificación Matematica

## GetLength
** GetLength(): Epsilon* -> N **
- Conjunto de Salida: _Epsilon_ (Clausra de Kleene del Alfabeto)
- Conjunto de Llegada: _N_ (Números naturales incluyendo el 0)
- Ejemplos:
  - GetLength() => 0
  - GetLength("SSL") => 3
  

## IsEmpty
** IsEmpty(): Epsilon* -> {0,1} **
- Conjunto de Salida: _Epsilon_ (Clausra de Kleene del Alfabeto)
- Conjunto de Llegada: _{0,1}_ (Valores booleanos, donde el 0 representa False, es decir que la cadena NO es vacía y True o 1 si la cadena es Vacía)
- Ejemplos:
  - IsEmpty() => 1
  - IsEmpty("SSL") => 0
  
## Power
** Power(): Epsilon* x N -> Epsilon* **
- Conjunto de Salida: (Producto Cartesiano entre)
  - _Epsilon_ (Clausra de Kleene del Alfabeto)
  - _N_ (Números naturales incluyendo el 0)
- Conjunto de Llegada: _Epsilon_ (Clausra de Kleene del Alfabeto)
- Ejemplos:
  - Power("SSL",2) => "SSLSSL"
  - Power("SSL",1) => "SSL"


## Substring
** Substring(): Epsilon* x N x N -> Epsilon* **
- Conjunto de Salida: 
  - _Epsilon_ (Clausra de Kleene del Alfabeto)
  - _N_ (Números naturales incluyendo el 0)
  - _N_ (Números naturales incluyendo el 0)
- Conjunto de Llegada: _Epsilon_ (Clausra de Kleene del Alfabeto)
- Ejemplos:
  - Substring("Sintaxis y Semantica",0,8) => "Sintaxis"