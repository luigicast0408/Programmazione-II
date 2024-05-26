#include <iostream>
using namespace std;

// Dichiarazioni delle funzioni
void quickSort(int vector[], int size);
void quickSort(int vector[], int left, int right);
void printVector(int vector[], int size);

int main() {
    int vector[] = {10, 7, 8, 9, 1, 5};
    int size = sizeof(vector) / sizeof(vector[0]);


    cout << "Original vector:" << endl;
    printVector(vector, size);

    quickSort(vector, size);

    cout << "Sorted vector:" << endl;
    printVector(vector, size);

    return 0;
}

// Funzione che avvia il quicksort sull'intero array
void quickSort(int vector[], int size) {
    quickSort(vector, 0, size - 1); // Chiamata alla funzione quickSort con gli indici iniziali dell'array
}

// Funzione di quicksort che ordina l'array tra gli indici left e right
void quickSort(int vector[], int left, int right) {
    int i = left, j = right; // Indici per attraversare l'array
    int temp;
    int pivot = vector[(left + right) / 2]; // Scelta del pivot come elemento centrale dell'array

    // Ciclo per partizionare l'array
    while (i <= j) {
        while (vector[i] < pivot) i++; // Trova un elemento maggiore o uguale al pivot
        while (vector[j] > pivot) j--; // Trova un elemento minore o uguale al pivot
        if (i <= j) {
            // Scambio degli elementi
            temp = vector[i];
            vector[i] = vector[j];
            vector[j] = temp;
            i++;
            j--;
        }
    }

    // Ricorsione sulla partizione di sinistra
    if (left < j) {
        quickSort(vector, left, j);
    }
    // Ricorsione sulla partizione di destra
    if (i < right) {
        quickSort(vector, i, right);
    }
}

void printVector(int vector[], int size) {
    cout << "____VECTOR____" << endl;
    for (int i = 0; i < size; ++i) {
        cout << "vector[" << i << "] = " << vector[i] << endl;
    }
    cout << "____VECTOR____" << endl;
}
