# Análisis Comparativo C vs Java
## a. ¿El tipo es parte del lenguaje en algún nivel?
- ### C
  El tipo de dato String no esta incluido por defecto como uno de los tipos de datos posibles de C. De hecho si se quiere realizar operaciones sobre este tipo de datos, se requiere la inclusión de una biblioteca externa que contiene dichos operadores. 
  Sin embargo, el compilador procesa las cadenas literales como arreglos de chars. Es decir, aquellas cadenas encerradas entre comillas dobles (") son reconocidas por el compilador a nivel léxico y sintáctico, y luego a nivel semántico tratadas como un arreglo de chars (`"ssl" = ['s','s','l']`)

- ### Java
  En Java, el tipo de dato String no es un tipo de dato de los llamados primitivos, si no que es un tipo de dato estructurado, llamados en este lenguaje objetos o clases. Las cadenas de caracteres en Java, son un objeto de la clase String y para declararlo se delimita entre comillas dobles. A diferencia de otros objetos de Java, no es necesario explicitar que se quiere crear un nuevo objeto del tipo String ya que lo infiere automáticamente el compilador.

## b. ¿El tipo es parte de la biblioteca?
- ### C
  El tipo de dato String no pertenece a la biblioteca standard de C, este tipo de dato debe ser incluido mediante la biblioteca string.h. Aun así, el compilador transforma las cadenas de caracteres entre comillas dobles (") en un arreglo de chars, que pueden ser manipulados por las operaciones incluidas en la biblioteca anteriormente mencionada. 
- ### Java
  Si bien no es necesario incluir una biblioteca para implementar el tipo de dato String, como se explico anteriormente, el mismo es una clase, no es un tipo de dato primitivo.

## c. ¿Qué alfabeto usa?
- ### C
  El alfabeto utilizado por defecto en C para un caracter es UTF-8, aunque también existe la posibilidad de definir otros.

- ### Java
  El alfabeto utilizado en Java es el estándar Unicode que establece hasta 65.535 signos de todas las
  lenguas principales, siendo los códigos del 0 al 255 los correspondientes a la codificación ASCII.

## d. ¿Cómo se resuelve la alocación de memoria?
- ### C
  Existen dos formas de alocar memoria en C, en primer lugar de forma dinámica, donde la memoria es reservada en tiempo de ejecución. Y por otra parte la estática que se crea al declarar variables de tipo de dato primitivo o derivados.  
- ### Java
  Java por su parte, al funcionar sobre una Virtual Machine funciona un poco diferente. Por una parte esta el Stack que es una sección de memoria que contiene métodos, variables locales y variables de referencia. La memoria de pila siempre se referencia en el orden de último en entrar primero en salir. Las variables locales se crean en la pila. Y por otro lado existe el Heap, que es una sección de memoria que contiene objetos y también puede contener variables de referencia. Las variables de instancia se crean en el montón
  
## e. ¿El tipo tiene mutabilidad o es inmutable?
- ### C
  Depende de la forma en que sean declarados, los Strings en C puede ser o no mutables. Si se declaran como constantes o se crea un puntero a memoria, serán tipos inmutables. Mientras que si se crean como arreglos de chars (`char variable[]`) y se la inicializa con un valor encerrado entre comillas dobles ("), este tipo sería mutable
- ### Java
  En Java los Strings son siempre Inmutables, no existen asignaciones de tipo String que sean mutables.

## f. ¿El tipo es un first class citizen?
- ### C
  Si consideramos al tipo de dato String incluido en la biblioteca externa antes mencionada, si es un tipo de dato First Class Citizen, ya que puede ser enviado como parámetro de una función, puede ser devuelto como resultado, puede ser sujeto de una sentencia de asignacion y puede ser comparado mediante metodos propiamente incluidos en la biblioteca.
- ### Java
  Al igual que en C, los Strings siempre son considerados First Class Citizen ya que cumplen con todas las caracterisiticas mencionadas. 

## g. ¿Cuál es la mecánica para ese tipo cuando se lo pasa como argumentos?
- ### C
  Si se utiliza en su formato de arreglo de chars, debe ser enviodo a una funcion mediante un puntero que señala el comienzo de la cadena, y tiene que finalizar con el caracter '\0' o también conocido como caracter nulo. En caso de utilizarse la definicion incorporada por la biblioteca, esto no es necesario.
- ### Java
  Para Java, no es necesario tomar ningun recaudo adicional a la hora de pasar un String como argumento. Simplemente se establece de forma directa que sera un tipo de dato String.

## h. ¿Y cuando son retornados por una función?
- ### C
  Generalmente, el tipo String sera retornado como el resultado de una función mediante un puntero que señale el comienzo del espacio de memoria que almacenara al resultado
- ### Java
  Nuevamente, pueden ser retornados sin ninguna necesidad extra.     