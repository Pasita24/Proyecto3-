#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <cstdlib>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <random>
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

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void merge(vector<int>& arr, int start, int middle, int end, vector<int>& temp) {
    int i = start;
    int j = middle;
    int k = start;

    for (int l = start; l < end; ++l) {
        temp[l] = arr[l];
    }

    while (i < middle && j < end) {
        if (temp[i] <= temp[j]) {
            arr[k] = temp[i];
            ++i;
        } else {
            arr[k] = temp[j];
            ++j;
        }
        ++k;
    }

    while (i < middle) {
        arr[k] = temp[i];
        ++i;
        ++k;
    }
}

void mergeSort(vector<int>& arr, int start, int end, vector<int>& temp) {
    if (end - start <= 1) return;

    int middle = start + (end - start) / 2;
    mergeSort(arr, start, middle, temp);
    mergeSort(arr, middle, end, temp);
    merge(arr, start, middle, end, temp);
}

void partition(vector<int>& D, int low, int high) {
    if (high <= low) return;

    int i = low;
    int j = high;
    int s = D[low];

    while (high > low) {
        while (high > low && D[high] >= s) {
            high--;
        }
        if (high > low) {
            D[low] = D[high];
            low++;
        }
        while (high > low && D[low] <= s) {
            low++;
        }
        if (high > low) {
            D[high] = D[low];
            high--;
        }
    }
    D[low] = s;
    partition(D, i, low - 1);
    partition(D, low + 1, j);
}

void quicksort(vector<int>& D) {
    partition(D, 0, D.size() - 1);
}

int main() {
    srand(time(0));

    int tamanoArreglo = 20000; // Definir tamaño del arreglo

    set<int> elementosAleatorios; // Usar un conjunto para evitar duplicados
    vector<int> arregloAleatorio;
    vector<int> arregloCopia;
    vector<int> temp(tamanoArreglo);

    while (elementosAleatorios.size() < tamanoArreglo) {
        int numAleatorio = rand();
        elementosAleatorios.insert(numAleatorio);
    }

    for (const auto& num : elementosAleatorios) {
        arregloAleatorio.push_back(num);
        arregloCopia.push_back(num);
    }

    clock_t startSelection = clock();
    selectionSort(arregloAleatorio);
    clock_t endSelection = clock();
    double tiempoSelection = double(endSelection - startSelection) / CLOCKS_PER_SEC;

    clock_t startBubble = clock();
    bubbleSort(arregloAleatorio);
    clock_t endBubble = clock();
    double tiempoBubble = double(endBubble - startBubble) / CLOCKS_PER_SEC;

    clock_t startInsertion = clock();
    insertionSort(arregloAleatorio);
    clock_t endInsertion = clock();
    double tiempoInsertion = double(endInsertion - startInsertion) / CLOCKS_PER_SEC;

    clock_t startMerge = clock();
    mergeSort(arregloAleatorio, 0, arregloAleatorio.size(), temp);
    clock_t endMerge = clock();
    double tiempoMerge = double(endMerge - startMerge) / CLOCKS_PER_SEC;

    clock_t startQuick = clock();
    quicksort(arregloAleatorio);
    clock_t endQuick = clock();
    double tiempoQuick = double(endQuick - startQuick) / CLOCKS_PER_SEC;

    cout << "Ordenamiento de forma aleatoria sin repeticiones:" << endl;
    cout << "Selection Sort: " << tiempoSelection << " segundos" << endl;
    cout << "Bubble Sort: " << tiempoBubble << " segundos" << endl;
    cout << "Insertion Sort: " << tiempoInsertion << " segundos" << endl;
    cout << "Merge Sort: " << tiempoMerge << " segundos" << endl;
    cout << "Quick Sort: " << tiempoQuick << " segundos" << endl;

    return 0;
}
