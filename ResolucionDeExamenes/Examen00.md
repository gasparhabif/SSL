
<h3>1. Parte I</h3>
1. La tarea más representativa para la que un Ingeniero en Sistemas de Información está capacitado es la resolución de problemas. Para resolver dichos problemas construye artefactos o mecanismos utilizando técnicas y herramientas basadas en las ciencias básicas.
2. La información es un concepto objetivo con carga significativa o importancia. Son datos procesados.
3. Algoritmos y Estructuras de Datos, Matemática Discreta, Sintaxis y Semántica de los Lenguajes, Paradigmas de Programación, Gestión de Datos. 
4. Sistemas y Organizaciones, Análisis de Sistemas, Diseño de Sistemas.
5. El paradigma de programación aplicado en primer año de la carrera
6. La abstracción es el concepto de separación, que se basa en dejar de lado los detalles insignificantes para enfocarse en lo más importante.

<h3>2. Parte II</h3>
1. Mientras que un conjunto puede ser una agrupación de elementos sin relación, las secuencias siempre siguen un patrón que relaciona los elementos. 
2. Una secuencia matemática es una serie de elementos que se suceden unos a otros y guardan una relación matemática entre si.
3. Una función matemática es el vinculo entre elementos de dos conjuntos, de forma que un hecho depende de del otro. Es decir que para todo elemento de salida existe un único elemento de llegada.
4. Un grafo es un conjunto de puntos o nodos unidos por arcos o aristas.
5. La partición de un conjunto es aquella que es diferente del vacío, su intersección con otra partición del mismo conjunto es diferente del vacío para todos los elementos que sean diferentes entre si, y todos los elementos del conjunto pertenecen a una única partición.
6. Siendo X={a, b}: P(X) = {{a},{b}}
7. Un Lenguaje Formal es un subconjunto de un Alfabeto formado por palabras de longitud variable que están formadas con letras de dicho Alfabeto
8. Un autómata finito es aquel que reconoce los lenguajes regulares

<h3>3. Parte III</h3>
1. Secuencia de pasos o instrucciones, a realizar sobre un autómata para alcanzar un resultado deseado. 
2. La programación estructurada es aquella solo permite la utilización de tres estructuras.
3. Las tres estructuras de control de flujo de ejecución existentes en la programación estructurada son Asignación, selección y repetición. 
4. Un parámetro es una "exigencia" que tiene la función para poder ser llamada. Al declarar la función se definen los parámetros. En cambio, un argumento es el valor literal que se le pasa mediante los parámetros a una función, donde ejecutara el código con los valores del argumento. 
5. Existen dos formas de transferir un argumento, por VALOR donde se le pasa únicamente el valor de una variable, o el valor implícito, a una función, donde dicho valor vivirá solo hasta que finalice esa función. Y por REFERENCIA donde el dato transferido es la dirección de memoria a la que apunta la variable transferida, por lo que al alterar el valor de esta variable se altera en todo el flujo del programa, y al finalizar la función, esa variable continúa existiendo con el valor modificado a lo largo de la función. 
6. Los parámetros de entrada son aquellos que la función exige para poder ejecutar sus operaciones, el parámetro de salida es aquel que la función devuelve luego de operar. Y por ultimo los parámetros de entrada/salida son aquellos que toma para comenzar a operar, y modifica durante la ejecución, para devolver el mismo parámetro, pero modificado.
7. Un tipo de dato abstracto es aquel que "oculta" los detalles de uno o muchos datos, bajo una misma definición. Por ejemplo, si yo definiera el tipo de dato "Auto", no es necesario que detalle que al ser un auto tendrá motor, ruedas, etc.
8. La principal diferencia entre las pilas y las colas radica en la forma en que los elementos "entran y salen". Mientras que en las pilas el ultimo elemento que entra, es el primero que sale, en las colas el primer elemento que entra es el primero en salir.
9. Un archivo es uno o mas datos, almacenados bajo ciertas normas y codificaciones. 
10. 
    	float promedioDeArrays(int[] a, int n){
            int sumatoria = 0;
            for (int i = 0; i<n; i++) {
                sumatoria += a[i];
            }
            return sumatoria/n;
        }