#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void shellSort(vector<int>& arr) {
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

void merge(vector<int>& arr, int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    vector<int> left(n1), right(n2);

    for (int i = 0; i < n1; ++i) {
        left[i] = arr[low + i];
    }

    for (int j = 0; j < n2; ++j) {
        right[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = low;

    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            ++i;
        } else {
            arr[k] = right[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        arr[k] = left[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        arr[k] = right[j];
        ++j;
        ++k;
    }
}

void mergeSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
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

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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

    // Construir el heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Extraer elementos uno por uno del heap
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]); 
        heapify(arr, i, 0);
    }
}

int main() {
    srand(time(0)); // Semilla para números aleatorios

    int size = rand() % 10001 + 100000; // Tamaño entre 100,000 y 110,000
    vector<int> arr_selection(size), arr_bubble(size), arr_insertion(size), arr_shell(size), arr_merge(size), arr_quick(size), arr_heap(size);


    // Generar números únicos para cada algoritmo
    for (int i = 0; i < size; ++i) {
        arr_selection[i] = i + 1;
        arr_bubble[i] = i + 1;
        arr_insertion[i] = i + 1;
    }

    // Barajar los arreglos para obtener números aleatorios
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(arr_selection[i], arr_selection[j]);
        swap(arr_bubble[i], arr_bubble[j]);
        swap(arr_insertion[i], arr_insertion[j]);
    }

    // Calcular el tiempo de ejecución de Selection Sort
    clock_t start_selection = clock();
    selectionSort(arr_selection);
    clock_t end_selection = clock();
    double duration_selection = double(end_selection - start_selection) / CLOCKS_PER_SEC; // Convertir a segundos

    cout << "Tiempo de ejecucion de Selection Sort para un arreglo de tamanio " << size << ": " << duration_selection << " segundos" << endl;

    // Calcular el tiempo de ejecución de Bubble Sort
    clock_t start_bubble = clock();
    bubbleSort(arr_bubble);
    clock_t end_bubble = clock();
    double duration_bubble = double(end_bubble - start_bubble) / CLOCKS_PER_SEC; // Convertir a segundos

    cout << "Tiempo de ejecucion de Bubble Sort para un arreglo de tamanio " << size << ": " << duration_bubble << " segundos" << endl;

    // Calcular el tiempo de ejecución de Insertion Sort
    clock_t start_insertion = clock();
    insertionSort(arr_insertion);
    clock_t end_insertion = clock();
    double duration_insertion = double(end_insertion - start_insertion) / CLOCKS_PER_SEC; // Convertir a segundos

    cout << "Tiempo de ejecucion de Insertion Sort para un arreglo de tamanio " << size << ": " << duration_insertion << " segundos" << endl;

    // Calcular el tiempo de ejecución de Shell Sort
    clock_t start_shell = clock();
    shellSort(arr_shell);
    clock_t end_shell = clock();
    double duration_shell = double(end_shell - start_shell) / CLOCKS_PER_SEC; // Convertir a segundos

    cout << "Tiempo de ejecucion de Shell Sort para un arreglo de tamanio " << size << ": " << duration_shell << " segundos" << endl;

    // Calcular el tiempo de ejecución de Merge Sort
    clock_t start_merge = clock();
    mergeSort(arr_merge, 0, size - 1);
    clock_t end_merge = clock();
    double duration_merge = double(end_merge - start_merge) / CLOCKS_PER_SEC; // Convertir a segundos

    cout << "Tiempo de ejecucion de Merge Sort para un arreglo de tamanio " << size << ": " << duration_merge << " segundos" << endl;


    // Calcular el tiempo de ejecución de Quick Sort
    clock_t start_quick = clock();
    quickSort(arr_quick, 0, size - 1);
    clock_t end_quick = clock();
    double duration_quick = double(end_quick - start_quick) / CLOCKS_PER_SEC; // Convertir a segundos

    cout << "Tiempo de ejecucion de Quick Sort para un arreglo de tamanio " << size << ": " << duration_quick << " segundos" << endl;

    // Calcular el tiempo de ejecución de Heap Sort
    clock_t start_heap = clock();
    heapSort(arr_heap);
    clock_t end_heap = clock();
    double duration_heap = double(end_heap - start_heap) / CLOCKS_PER_SEC; // Convertir a segundos

    cout << "Tiempo de ejecucion de Heap Sort para un arreglo de tamanio " << size << ": " << duration_heap << " segundos" << endl;

    return 0;
}
