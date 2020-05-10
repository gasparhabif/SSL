#hello2.c
1. Comando Ejecutado: gcc -E hello2.c > hello2.i
2. Resultado/Error Obtenido: El resultado obtenido no incluye errores ya que durante la fase de preprocesado unicamente se traducen/procesan directivas que dentro del archivo hello2.c son correctas.

#hello3.c
3. Comando Ejecutado: gcc -E hello3.c > hello3.i
Resultado/Error Obtenido: Al igual que en el punto 1, se obtiene el archivo de hello3.c pero preprocesado.
4. Sera una funcion que recibira N parametros de tipo Char constantes y enviados por puntero, generando un valor de retorno de tipo Int.
5. Las diferencias entre el archivo hello3.c y hello3.i estan dadas por la cabecera, en la que el archivo hello3.i incluye las definiciones.
6. Comando Ejecutado: gcc -S hello3.c
   Error Obtenido: 
   `hello3.c: In function 'main':
    hello3.c:5:5: warning: implicit declaration of function 'prontf' [-Wimplicit-function-declaration]
        prontf("La respuesta es %d\n");
        ^~~~~~
    hello3.c:5:5: error: expected declaration or statement at end of input`

#hello4.c
7. Comando Ejecutado: gcc -S hello4.c
   Resultado/Error Obtenido: Archivo hello4.s generado
9. Comando Ejecutado: as -o hello4.o hello4.s
   Resultado/Error Obtenido: Archivo hello4.o generado
10. Comando Ejecutado: gcc -o hello4 hello4.o
    Resultado Obtenido: Al ejecutarse el programa no se generan errores pero tampoco se imprime la cadena esperada.

#hello5.c
11. Comando Ejecutado: gcc -o hello5 hello5.c
12. Resultado Obtenido: Se imprime correctamente la cadena de caracteres esperada.

#hello6.c
13. Comando Ejecutado: gcc -o hello6 hello6.c
    Resultado Obtenido: Se imprime correctamente la cadena de caracteres esperada.

#hello7.c
14. Archivo hello7.c generado
15. Funciona debido a que el simbolo % dentro de las cadenas de caracteres es una palabra reservada para la sustitucion en tiempo de ejecucion. 
