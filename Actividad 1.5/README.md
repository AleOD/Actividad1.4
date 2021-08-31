La carpeta cuenta con 3 archivos principales:
  1. act_integral.c donde se encuentra el código del program
  2. 100_threads.xlsx que cuenta con los 100 threads que se evaluaron
  3. Resultados.pttx donde se encuentan los resultados obtenidos
En este código se realizó la paralelización de un programa que resuelve de forma numérica la integral con límites de 1 a 2 de la función dx/x.
Compilación del código:
1. gcc -fopenmp act_integral.c -o x
2. .\x
3. Ingresar el número de threads a utilizar

Resultados:
Al ingresar un valor de 100 threads y graficar los resultados (los cuales se podrán encontrar en el archivo "100Threads.xlsx") se llegó a la conclusión de que el número de threads óptimo fue de 52.

