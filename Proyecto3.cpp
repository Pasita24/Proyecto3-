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

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}
void quicksort(vector<int>& D, int low, int high) {
    if (low < high) {
        int pi = partition(D, low, high);
        quicksort(D, low, pi - 1);
        quicksort(D, pi + 1, high);
    }
}

void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; --i) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

double calculateTime(vector<int>& arr, int option) {
    auto start = chrono::high_resolution_clock::now();

    switch (option) {
        case 1: {
            selectionSort(arr);
            break;
        }
        case 2: {
            bubbleSort(arr);
            break;
        }
        case 3: {
            insertionSort(arr);
            break;
        }
        case 4: {
            mergeSort(arr, 0, arr.size(), arr);
            break;
        }
        case 5: {
            quicksort(arr, 0, arr.size() - 1);
            break;
        }
        case 6: {
            heapSort(arr);
            break;
        }
        default: {
            cout << "Opción inválida" << endl;
            return 0.0;
        }
    }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed_seconds = end - start;

    return elapsed_seconds.count();
}

int main() {
    srand(time(0));

    int tamanoArreglo = 100000; // Definir tamaño del arreglo

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

    sort(arregloCopia.begin(), arregloCopia.end()); // Ordenar para tener duplicados

    vector<int> arrAscendente(tamanoArreglo); // Datos ordenados de forma ascendente
    iota(arrAscendente.begin(), arrAscendente.end(), 1);

    vector<int> arrDescendente = arrAscendente; // Datos ordenados de forma descendente
    reverse(arrDescendente.begin(), arrDescendente.end());

    vector<vector<int>> datasets = {
        arregloAleatorio, arregloCopia, arrAscendente, arrDescendente
    };

    vector<string> datasetNames = {
        "Aleatorio sin duplicados", "Aleatorio con duplicados", "Ascendente", "Descendente"
    };

    vector<string> algorithmNames = {
        "Selection Sort", "Bubble Sort", "Insertion Sort", "Merge Sort", "Quick Sort", "Heap Sort"
    };

    cout << "Carreras de algoritmos" << endl;
    cout << "Modos de ordenamiento:" << endl;
    cout << "1. Aleatorio sin duplicados" << endl;
    cout << "2. Aleatorio con duplicados" << endl;
    cout << "3. Ascendente" << endl;
    cout << "4. Descendente" << endl;

    for (int i = 0; i < datasets.size(); ++i) {
        cout << "\n" << "Resultados para " << datasetNames[i] << ":" << endl;
        for (int j = 0; j < algorithmNames.size(); ++j) {
            double time_taken = calculateTime(datasets[i], j + 1);
            cout << algorithmNames[j] << ": " << fixed << time_taken << setprecision(5) << " segundos" << endl;
        }
    }

    return 0;
}
