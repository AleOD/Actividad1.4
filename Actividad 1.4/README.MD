En la carpeta se encuentran 2 archivos, uno con la presentación de los resultados y otro con el nombre de multihilo.c que corresponde al código del siguiente problema:

Código de integral definida por método del trapecio (paralelizado) que define el número de threads óptimo para tres modelos de computadoras distintos usando 1x108 puntos en el intervalo de [0,1] de la función 4/(1+x^2) . Se muestra en tres diferentes gráficas la forma en que cada uno de los threads solicitados atiende el llamado de servicio en cada computadora.

Compilación:

gcc -fopenmp multihilo.c -o multihilo
./multihilo
Ejecución del Código: El programa pide al usuario ingresar el número de threads que utilizará el programa. En cada ejecución de ciclo, se imprimirá en la consola el tiempo de ejecución de programa.

Una vez terminada la ejecución de los ciclos, se imprimirá en la consola la palabra Fin.

 Add a custom footer
