    #include <iostream>
    #include <vector>
    #include <ctime>
    #include <algorithm>

    using namespace std;

    // Funciones de ordenamiento optimizadas
    void selectionSort(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n - 1; i++) {
            int minIdx = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[minIdx]) {
                    minIdx = j;
                }
            }
            if (minIdx != i) {
                swap(arr[i], arr[minIdx]);
            }
        }
    }

    void bubbleSort(vector<int>& arr) {
        int n = arr.size();
        bool swapped;
        for (int i = 0; i < n - 1; i++) {
            swapped = false;
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped) {
                break;
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

        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }

        for (int i = n - 1; i >= 0; i--) {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
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
    void applySortingAlgorithm(vector<int>& arr, string algorithm) {
        if (algorithm == "Selection Sort") {
            selectionSort(arr);
        } else if (algorithm == "Bubble Sort") {
            bubbleSort(arr);
        } else if (algorithm == "Insertion Sort") {
            insertionSort(arr);
        } else if (algorithm == "Shell Sort") {
            shellSort(arr);
        } else if (algorithm == "Merge Sort") {
            mergeSort(arr, 0, arr.size() - 1);
        } else if (algorithm == "Quick Sort") {
            quickSort(arr, 0, arr.size() - 1);
        } else if (algorithm == "Heap Sort") {
            heapSort(arr);
        }
    }
    // Funciones para generar arreglos para cada tipo de carrera y ordenamiento
    void generateRandomArrayNoRepeatsInRange(vector<int>& arr, int size) {
        arr.resize(size);
        for (int i = 0; i < size; ++i) {
            arr[i] = rand() % size + 1;
        }
        random_shuffle(arr.begin(), arr.end());
    }

    void generateRandomArrayWithRepeatsInRange(vector<int>& arr, int size) {
        arr.resize(size);
        for (int i = 0; i < size; ++i) {
            arr[i] = rand() % size + 1;
        }
    }
    void generateRandomArrayNoRepeatsMultiplied(vector<int>& arr, int size) {
        arr.resize(size);
        for (int i = 0; i < size; ++i) {
            arr[i] = (rand() % 501 + 1001) * 15; 
        }
    }

    void generateRandomArrayWithRepeatsMultiplied(vector<int>& arr, int size) {
        arr.resize(size);
        for (int i = 0; i < size; ++i) {
            arr[i] = (rand() % 502 + 1000) * 15;
        }
    }

    void generateSortedArrayMultiplied(vector<int>& arr, int size) {
        arr.resize(size);
        for (int i = 0; i < size; ++i) {
            arr[i] = (rand() % 501 + 1001) * 15;
        }
        sort(arr.begin(), arr.end());
    }

    void generateReverseSortedArrayMultiplied(vector<int>& arr, int size) {
        arr.resize(size);
        for (int i = 0; i < size; ++i) {
            arr[i] = (rand() % 501 + 1001) * 15;
        }
        sort(arr.rbegin(), arr.rend());
    }
    // Funciones para generar arreglos ordenados e inversos
    void generateSortedArray(vector<int>& arr, int size) {
        for (int i = 0; i < size; ++i) {
            arr.push_back(rand() % 10001 + 100000);
        }
        sort(arr.begin(), arr.end());
    }

    void generateReverseSortedArray(vector<int>& arr, int size) {
        for (int i = 0; i < size; ++i) {
            arr.push_back(rand() % 10001 + 100000);
        }
        sort(arr.rbegin(), arr.rend());
    }
    void raceSortingAlgorithms() {
        // Vector de algoritmos
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

        int size = rand() % 10001 + 100000; // Tamaño entre 100,000 y 110,000
        for (int i = 0; i < raceTypes.size(); ++i) {
            cout << "Carrera " << i + 1 << ": " << raceTypes[i] << endl;

            
            vector<int> random_array;

            // Generar el arreglo según el tipo de carrera
            if (i == 0) {
                generateRandomArrayNoRepeats(random_array, size);
            } else if (i == 1) {
                generateRandomArrayWithRepeats(random_array, size);
            } else if (i == 2) {
                generateSortedArray(random_array, size);
            } else if (i == 3) {
                generateReverseSortedArray(random_array, size);
            }

            vector<double> execution_times(algorithms.size(), 0.0);

            random_shuffle(algorithms.begin(), algorithms.end());

            for (int j = 0; j < algorithms.size(); ++j) {
                vector<int> arr = random_array;

                clock_t start, end;
                double duration;

                start = clock();

                // Aplicar el algoritmo de ordenamiento
                applySortingAlgorithm(arr, algorithms[j]);

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

            cout << "---------------> El ganador de la carrera (" << raceTypes[i] << " )es: " << algorithms[winner_index] << " con un tiempo de " << min_time << " segundos <------------" << endl;
        }
    }
    void raceSortingAlgorithms2() {
        // Vector de algoritmos
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


        int size = (rand() % 501 + 1001)*15; // Tamaño entre 1000 y 1500
                    
        for (int i = 0; i < raceTypes.size(); ++i) {
            cout << "Carrera " << i + 1 << ": " << raceTypes[i] << endl;


            vector<int> random_array_multiplied;

            // Generar el arreglo según el tipo de carrera
            if (i == 0) {
                generateRandomArrayNoRepeatsMultiplied(random_array_multiplied, size);
            } else if (i == 1) {
                generateRandomArrayWithRepeatsMultiplied(random_array_multiplied, size);
            } else if (i == 2) {
                generateSortedArrayMultiplied(random_array_multiplied, size);
            } else if (i == 3) {
                generateReverseSortedArrayMultiplied(random_array_multiplied, size);
            }

            vector<double> execution_times(algorithms.size(), 0.0);

            random_shuffle(algorithms.begin(), algorithms.end());

            for (int j = 0; j < algorithms.size(); ++j) {
                vector<int> arr = random_array_multiplied;

                clock_t start, end;
                double duration;

                start = clock();

                // Aplicar el algoritmo de ordenamiento
                applySortingAlgorithm(arr, algorithms[j]);

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

            cout << "---------------> El ganador de la carrera (" << raceTypes[i] << " )es: " << algorithms[winner_index] << " con un tiempo de " << min_time << " segundos <------------" << endl;
        }
    }
    void raceSortingAlgorithms3() {
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
        
        int size = rand() % 20001 + 60000; // Tamaño entre 60,000 y 80,000
        
        for (int i = 0; i < raceTypes.size(); ++i) {
            cout << "Carrera " << i + 1 << ": " << raceTypes[i] << endl;


            vector<int> random_array;

            // Generar el arreglo según el tipo de carrera
            if (i == 0) {
                generateRandomArrayNoRepeatsInRange(random_array, size);
            } else if (i == 1) {
                generateRandomArrayWithRepeatsInRange(random_array, size);
            } else if (i == 2) {
                generateSortedArrayMultiplied(random_array, size);
            } else if (i == 3) {
                generateReverseSortedArrayMultiplied(random_array, size);
            }

            vector<double> execution_times(algorithms.size(), 0.0);

            random_shuffle(algorithms.begin(), algorithms.end());

            for (int j = 0; j < algorithms.size(); ++j) {
                vector<int> arr = random_array;

                clock_t start, end;
                double duration;

                start = clock();

                applySortingAlgorithm(arr, algorithms[j]);

                end = clock();
                duration = double(end - start) / CLOCKS_PER_SEC;

                cout << j + 1 << ". " << algorithms[j] << ", Tamanio: " << size << ", Tipo: " << raceTypes[i] << ", Tiempo: " << duration << " segundos" << endl;

                execution_times[j] += duration;
            }

            double min_time = execution_times[0];
            int winner_index = 0;
            for (int j = 1; j < execution_times.size(); ++j) {
                if (execution_times[j] < min_time) {
                    min_time = execution_times[j];
                    winner_index = j;
                }
            }

            cout << "-----------> El ganador de la carrera (" << raceTypes[i] << " )es: " << algorithms[winner_index] << " con un tiempo de " << min_time << " segundos <----------------" << endl;
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
        } else if (option == 2) {
            raceSortingAlgorithms2();
        } else if (option == 3) {
            raceSortingAlgorithms3(); 
        }else {
            cout << "Opcion invalida. Saliendo del programa." << endl;
            return 1;
        }

        return 0;
    }