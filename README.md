# Proyecto3
# Carrera de Algoritmos de Ordenamiento
- Este programa simula una competencia en tiempo real entre diferentes algoritmos de ordenamiento para distintos conjuntos de datos. El usuario puede elegir entre tres opciones que representan diferentes escenarios de competencia:

## Algoritmos de ordenamiento implementados dentro del codigo:
- Selection Sort
- Bubble Sort
- Insertion Sort
- Shell Sort
- Merge Sort
- Quick Sort
- Heap Sort

## Funcionalidades 
- 
1. Cola de espera
2. Trazabilidad de objetos 
3. Eventos de cada escenario 

## Funcionamiento de los arreglos en el codigo 
- El programa utiliza arreglos de enteros para representar conjuntos de datos que los algoritmos de ordenamiento deben procesar y ordenar. Aquí se detalla el funcionamiento de los diferentes tipos de arreglos utilizados en las competencias de los algoritmos:
### Tipos de arreglos 
1. Números aleatorios sin repetición: Se generan arreglos aleatorios sin repeticiones. La generación de estos arreglos utiliza un rango de números que no se repiten y se mezclan aleatoriamente para representar conjuntos únicos de datos.
2. Números aleatorios con repetición: Similar al caso anterior, pero permite la repetición de números en el rango establecido, generando así conjuntos con elementos repetidos.
3. Ordenado: Se generan arreglos ya ordenados de manera ascendente para representar conjuntos que ya están en secuencias ordenadas.
4. Inversamente Ordenado: Al contrario del caso anterior, se generan arreglos ordenados en orden descendente, representando conjuntos que necesitan ser revertidos a una secuencia ascendente.

- Proceso de competencia
Para cada uno de estos tipos de arreglos, los algoritmos de ordenamiento compiten en tiempo real. Cada algoritmo realiza su proceso de ordenamiento sobre los diferentes tipos de arreglos, calculando el tiempo que le toma completar la tarea.

Una vez que todos los algoritmos han ordenado un tipo particular de arreglo, se determina un ganador basado en el algoritmo que completó la tarea en el menor tiempo posible.

- Variabilidad en el tamaño de los arreglos
El tamaño de los arreglos varía según el tipo de competencia. Se utilizan diferentes rangos para definir el tamaño de los arreglos en cada opción del menú, lo que permite evaluar el rendimiento de los algoritmos en diferentes conjuntos de datos y tamaños de arreglo.

### Opcion 1: Cola de espera
- Genera un conjunto de datos aleatorios de tamaño entre 100.000 y 110.000.Luego para simular cuatro modos de carrera , se generan arreglos aleatorios de este conjunto de datos :

1. Numeros aleatorio sin repeticion 
2. Numeros aleatorio con repeticion 
3. Ordenado
4. Inversamente Ordenado 

- Los Algoritmos compiten en tiempo real para ordenar estos arreglos y el algoritmo que logra ordenar en el menor tiempo posible gana en cada categoria.
### Opcion 2:
- Similar a la opción 1, pero con un set de datos diferente. Genera un conjunto aleatorio entre 1000 y 1500 y multiplica el número resultante por 15 para obtener el tamaño del conjunto. Luego, se procede a simular la carrera de ordenamiento con los mismos tipos de arreglos que en la opción 1.

1. Numeros aleatorio sin repeticion 
2. Numeros aleatorio con repeticion 
3. Ordenado
4. Inversamente Ordenado 


### Opcion 3: Eventos de cada escenario 
- Otra simulación de carrera similar a las opciones anteriores, pero con un set de datos diferente. Genera un arreglo de números aleatorios en el rango de 60,000 a 80,000 y los algoritmos compiten para ordenar estos conjuntos en tiempo real en los mismos cuatro modos de carrera.

1. Numeros aleatorio sin repeticion 
2. Numeros aleatorio con repeticion 
3. Ordenado
4. Inversamente Ordenado 






