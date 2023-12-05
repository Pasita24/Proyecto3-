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
//<--------------------------------------------- Algoritmos Inversos---------------------------->
void selectionSortReverse(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[maxIdx]) {
                maxIdx = j;
            }
        }
        swap(arr[i], arr[maxIdx]);
    }
}

void bubbleSortReverse(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void insertionSortReverse(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void shellSortReverse(vector<int>& arr) {
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] < temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

void mergeReverse(vector<int>& arr, int low, int mid, int high) {
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
        if (left[i] >= right[j]) {
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

void mergeSortReverse(vector<int>& arr, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergeSortReverse(arr, low, mid);
        mergeSortReverse(arr, mid + 1, high);
        mergeReverse(arr, low, mid, high);
    }
}

int partitionReverse(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] > pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSortReverse(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partitionReverse(arr, low, high);
        quickSortReverse(arr, low, pi - 1);
        quickSortReverse(arr, pi + 1, high);
    }
}

void heapifyReverse(vector<int>& arr, int n, int i) {
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
        heapifyReverse(arr, n, largest);
    }
}

void heapSortReverse(vector<int>& arr) {
    int n = arr.size();

    // Construir el heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapifyReverse(arr, n, i);
    }

    // Extraer elementos uno por uno del heap
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapifyReverse(arr, i, 0);
    }
}
//<--------------------------------------- Fin --------------------------->

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
    cout << "Tiempo de ejecucion de Selection Sort(tamanio: "<< size <<"):" << duration << " segundos" << endl;

    // Bubble Sort
    start = clock();
    bubbleSort(arr_bubble);
    end = clock();
    duration = double(end - start) / CLOCKS_PER_SEC;
    cout << "Tiempo de ejecucion de Bubble Sort(tamanio: "<< size <<"):"<<duration << " segundos" << endl;

    // Insertion Sort
    start = clock();
    insertionSort(arr_insertion);
    end = clock();
    duration = double(end - start) / CLOCKS_PER_SEC;
    cout << "Tiempo de ejecucion de Insertion Sort(tamanio: "<< size <<"):" << duration << " segundos" << endl;

    // Shell Sort
    start = clock();
    shellSort(arr_shell);
    end = clock();
    duration = double(end - start) / CLOCKS_PER_SEC;
    cout << "Tiempo de ejecucion de Shell Sort(tamanio: "<< size <<"):" << duration << " segundos" << endl;

    // Merge Sort
    start = clock();
    mergeSort(arr_merge, 0, size - 1);
    end = clock();
    duration = double(end - start) / CLOCKS_PER_SEC;
    cout << "Tiempo de ejecucion de Merge Sort(tamanio: "<< size <<"):" << duration << " segundos" << endl;

    // Quick Sort
    start = clock();
    quickSort(arr_quick, 0, size - 1);
    end = clock();
    duration = double(end - start) / CLOCKS_PER_SEC;
    cout << "Tiempo de ejecucion de Quick Sort(tamanio: "<< size <<"):" << duration << " segundos" << endl;

    // Heap Sort
    start = clock();
    heapSort(arr_heap);
    end = clock();
    duration = double(end - start) / CLOCKS_PER_SEC;
    cout << "Tiempo de ejecucion de Heap Sort(tamanio: "<< size <<"):" << duration << " segundos" << endl;
}
void applyReverseSortingAlgorithms(vector<int>& arr, int size) {
    vector<int> arr_selection = arr;
    vector<int> arr_bubble = arr;
    vector<int> arr_insertion = arr;
    vector<int> arr_shell = arr;
    vector<int> arr_merge = arr;
    vector<int> arr_quick = arr;
    vector<int> arr_heap = arr;

    clock_t start, end;
    double duration;

    // Selection Sort in reverse order
    start = clock();
    selectionSortReverse(arr_selection);
    end = clock();
    duration = double(end - start) / CLOCKS_PER_SEC;
    cout << "Tiempo de ejecucion de Selection Sort (Mayor a menor)(tamanio: "<< size <<"):"<< duration << " segundos" << endl;

    // Bubble Sort in reverse order
    start = clock();
    bubbleSortReverse(arr_bubble);
    end = clock();
    duration = double(end - start) / CLOCKS_PER_SEC;
    cout << "Tiempo de ejecucion de Bubble Sort (Mayor a menor)(tamanio: "<< size <<"):"<< duration << " segundos" << endl;

    // Insertion Sort in reverse order
    start = clock();
    insertionSortReverse(arr_insertion);
    end = clock();
    duration = double(end - start) / CLOCKS_PER_SEC;
    cout << "Tiempo de ejecucion de Insertion Sort (Mayor a menor)(tamanio: "<< size <<"):" << duration << " segundos" << endl;

    // Shell Sort in reverse order
    start = clock();
    shellSortReverse(arr_shell);
    end = clock();
    duration = double(end - start) / CLOCKS_PER_SEC;
    cout << "Tiempo de ejecucion de Shell Sort (Mayor a menor)(tamanio: "<< size <<"):" << duration << " segundos" << endl;

    // Merge Sort in reverse order
    start = clock();
    mergeSortReverse(arr_merge, 0, size - 1);
    end = clock();
    duration = double(end - start) / CLOCKS_PER_SEC;
    cout << "Tiempo de ejecucion de Merge Sort (Mayor a menor)(tamanio: "<< size <<"):" << duration << " segundos" << endl;

    // Quick Sort in reverse order
    start = clock();
    quickSortReverse(arr_quick, 0, size - 1);
    end = clock();
    duration = double(end - start) / CLOCKS_PER_SEC;
    cout << "Tiempo de ejecucion de Quick Sort (Mayor a menor)(tamanio: "<< size <<"):" << duration << " segundos" << endl;

    // Heap Sort in reverse order
    start = clock();
    heapSortReverse(arr_heap);
    end = clock();
    duration = double(end - start) / CLOCKS_PER_SEC;
    cout << "Tiempo de ejecucion de Heap Sort (Mayor a menor)(tamanio: "<< size <<"):" << duration << " segundos" << endl;
}
void raceSortingAlgorithms() {
    vector<string> algorithms = {
        "Selection Sort",
        "Bubble Sort",
        "Insertion Sort",
        "Shell Sort",
        "Merge Sort",
        "Quick Sort",
        "Heap Sort"
    };

    vector<string> raceTypes = {
        "Arreglo sin numeros repetidos",
        "Arreglo con numeros repetidos",
        "Arreglo ordenado",
        "Arreglo ordenado inversamente"
    };

    for (int i = 0; i < raceTypes.size(); ++i) {
        cout << "Carrera " << i + 1 << ": " << raceTypes[i] << endl;

        int size = rand() % 10001 + 100000; // Tamaño entre 100,000 y 110,000
        vector<int> random_array;

        // Generar el arreglo según el tipo de carrera
        if (i == 0) {
            generateRandomArrayNoRepeats(random_array, size);
        } else if (i == 1) {
            generateRandomArrayWithRepeats(random_array, size);
        } else if (i == 2) {
            for (int i = 0; i < size; ++i) {
                random_array.push_back(rand() % 10001 + 100000);
            }
            sort(random_array.begin(), random_array.end());
        } else if (i == 3) {
            for (int i = 0; i < size; ++i) {
                random_array.push_back(rand() % 10001 + 100000);
            }
            sort(random_array.rbegin(), random_array.rend());
        }

        vector<double> execution_times(algorithms.size(), 0.0);

        random_shuffle(algorithms.begin(), algorithms.end());

        for (int j = 0; j < algorithms.size(); ++j) {
            vector<int> arr = random_array;

            clock_t start, end;
            double duration;

            start = clock();

            // Aplicar el algoritmo de ordenamiento
            if (algorithms[j] == "Selection Sort") {
                selectionSort(arr);
            } else if (algorithms[j] == "Bubble Sort") {
                bubbleSort(arr);
            } else if (algorithms[j] == "Insertion Sort") {
                insertionSort(arr);
            } else if (algorithms[j] == "Shell Sort") {
                shellSort(arr);
            } else if (algorithms[j] == "Merge Sort") {
                mergeSort(arr, 0, size - 1);
            } else if (algorithms[j] == "Quick Sort") {
                quickSort(arr, 0, size - 1);
            } else if (algorithms[j] == "Heap Sort") {
                heapSort(arr);
            }

            end = clock();
            duration = double(end - start) / CLOCKS_PER_SEC;

            cout << j + 1 << ". " << algorithms[j] << ", Tamanio: " << size << ", Tipo: " << raceTypes[i] << ", Tiempo: " << duration << " segundos" << endl;

            // Almacenar el tiempo de ejecución del algoritmo
            execution_times[j] += duration;
        }

        // Encontrar el ganador de la carrera
        double min_time = execution_times[0];
        int winner_index = 0;
        for (int j = 1; j < execution_times.size(); ++j) {
            if (execution_times[j] < min_time) {
                min_time = execution_times[j];
                winner_index = j;
            }
        }

        cout << "El ganador de la carrera (" << raceTypes[i] << " )es: " << algorithms[winner_index] << " con un tiempo de " << min_time << " segundos" << endl;
    }
}
int main() {
    srand(time(0)); // Semilla para números aleatorios

    cout << "Nuestro menu principal va a ser:" << endl;
    cout << "1.- Cola de espera" << endl;
    cout << "2.- Trazabilidad de objetos" << endl;
    cout << "3.- Eventos de cada escenario" << endl;

    int option;
    cout << "Ingrese su eleccion: ";
    cin >> option;

    if (option == 1) {
        raceSortingAlgorithms();
    } else {
        cout << "Opcion invalida. Saliendo del programa." << endl;
        return 1;
    }

    return 0;
}