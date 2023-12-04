#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

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
void generateRandomArrayNoRepeats(vector<int>& arr, int size) {
    arr.resize(size);
    for (int i = 0; i < size; ++i) {
        arr[i] = i + 1;
    }
    random_shuffle(arr.begin(), arr.end());
}

void generateRandomArrayWithRepeats(vector<int>& arr, int size) {
    arr.resize(size);
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % size; // Puedes ajustar el rango si es necesario
    }
}
void applySortingAlgorithms(vector<int>& arr, int size) {
    vector<int> arr_selection = arr;
    vector<int> arr_bubble = arr;
    vector<int> arr_insertion = arr;
    vector<int> arr_shell = arr;
    vector<int> arr_merge = arr;
    vector<int> arr_quick = arr;
    vector<int> arr_heap = arr;

    clock_t start, end;
    double duration;

    // Selection Sort
    start = clock();
    selectionSort(arr_selection);
    end = clock();
    duration = double(end - start) / CLOCKS_PER_SEC;
    cout << "Tiempo de ejecucion de Selection Sort: " << duration << " segundos" << endl;

    // Bubble Sort
    start = clock();
    bubbleSort(arr_bubble);
    end = clock();
    duration = double(end - start) / CLOCKS_PER_SEC;
    cout << "Tiempo de ejecucion de Bubble Sort: " << duration << " segundos" << endl;

    // Insertion Sort
    start = clock();
    insertionSort(arr_insertion);
    end = clock();
    duration = double(end - start) / CLOCKS_PER_SEC;
    cout << "Tiempo de ejecucion de Insertion Sort: " << duration << " segundos" << endl;

    // Shell Sort
    start = clock();
    shellSort(arr_shell);
    end = clock();
    duration = double(end - start) / CLOCKS_PER_SEC;
    cout << "Tiempo de ejecucion de Shell Sort: " << duration << " segundos" << endl;

    // Merge Sort
    start = clock();
    mergeSort(arr_merge, 0, size - 1);
    end = clock();
    duration = double(end - start) / CLOCKS_PER_SEC;
    cout << "Tiempo de ejecucion de Merge Sort: " << duration << " segundos" << endl;

    // Quick Sort
    start = clock();
    quickSort(arr_quick, 0, size - 1);
    end = clock();
    duration = double(end - start) / CLOCKS_PER_SEC;
    cout << "Tiempo de ejecucion de Quick Sort: " << duration << " segundos" << endl;

    // Heap Sort
    start = clock();
    heapSort(arr_heap);
    end = clock();
    duration = double(end - start) / CLOCKS_PER_SEC;
    cout << "Tiempo de ejecucion de Heap Sort: " << duration << " segundos" << endl;
}
int main() {
    srand(time(0)); // Semilla para números aleatorios

    int choice;
    cout << "Seleccione el tipo de arreglo a ordenar:" << endl;
    cout << "1. Arreglo sin numeros repetidos" << endl;
    cout << "2. Arreglo con numeros repetidos" << endl;
    cout << "Ingrese su elección: ";
    cin >> choice;

    int size = rand() % 10001 + 100000; // Tamaño entre 100,000 y 110,000
    vector<int> random_array;

    if (choice == 1) {
        generateRandomArrayNoRepeats(random_array, size);
    } else if (choice == 2) {
        generateRandomArrayWithRepeats(random_array, size);
    } else {
        cout << "Elección invalida. Saliendo del programa." << endl;
        return 1;
    }

    cout << "Aplicando algoritmos de ordenamiento al arreglo generado..." << endl;

    // Llamar a la función para aplicar los algoritmos de ordenamiento
    applySortingAlgorithms(random_array, size);

    
    return 0;
}
