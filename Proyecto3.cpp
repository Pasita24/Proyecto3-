#include <iostream>
#include <vector>
#include <cstdlib>    // Para rand()
#include <ctime>      // Para time()
#include <algorithm>  // Para sort()

using namespace std;

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;
    do {
        swapped = false;
        for (int i = 1; i < n; ++i) {
            if (arr[i - 1] > arr[i]) {
                swap(arr[i - 1], arr[i]);
                swapped = true;
            }
        }
        --n;
    } while (swapped);
}

int main() {
    srand(time(0)); // Inicializar la semilla para números aleatorios

    int tamanoArreglo = rand() % 10001 + 100000; // Generar un tamaño aleatorio entre 100,000 y 110,000
    vector<int> arregloAleatorio;

    // Llenar el arreglo con números aleatorios sin repetición
    for (int i = 0; i < tamanoArreglo; ++i) {
        int numAleatorio = rand(); // Generar un número aleatorio
        arregloAleatorio.push_back(numAleatorio);
    }

    vector<int> arregloCopia = arregloAleatorio; // Crear una copia del arreglo aleatorio para usar con Bubble Sort

    // Medir el tiempo antes de ordenar con Selection Sort
    clock_t startSelection = clock();

    // Ordenar el arreglo usando Selection Sort
    selectionSort(arregloAleatorio);

    // Medir el tiempo después de ordenar con Selection Sort
    clock_t endSelection = clock();
    double tiempoSelection = double(endSelection - startSelection) / CLOCKS_PER_SEC;

    // Medir el tiempo antes de ordenar con Bubble Sort
    clock_t startBubble = clock();

    // Ordenar el arreglo copiado usando Bubble Sort
    bubbleSort(arregloCopia);

    // Medir el tiempo después de ordenar con Bubble Sort
    clock_t endBubble = clock();
    double tiempoBubble = double(endBubble - startBubble) / CLOCKS_PER_SEC;

    // Mostrar los tiempos de ejecución
    cout << "Ordenamiento de forma aleatoria sin repeticiones:" << endl;
    cout << "Selection Sort: " << tiempoSelection << " segundos" << endl;
    cout << "Bubble Sort: " << tiempoBubble << " segundos" << endl;

    return 0;
}
