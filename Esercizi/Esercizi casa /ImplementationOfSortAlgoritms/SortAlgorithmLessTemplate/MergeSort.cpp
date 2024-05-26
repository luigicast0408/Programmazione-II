#include <iostream>
using namespace std;

// Funzione per unire due sottoarray
void merge(int vector[], int left, int mid, int right) {
    int n1 = mid - left + 1; // Lunghezza del primo sottoarray
    int n2 = right - mid; // Lunghezza del secondo sottoarray

    // Creiamo gli array temporanei
    int L[n1], R[n2]; //VLA (Variable Length Array)

    // Copiamo i dati negli array temporanei
    for (int i = 0; i < n1; ++i)
        L[i] = vector[left + i];
    for (int i = 0; i < n2; ++i)
        R[i] = vector[mid + 1 + i];

    // Indici iniziali del primo e secondo sottoarray
    int i = 0, j = 0;

    // Indice iniziale del sottoarray unito
    int k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            vector[k] = L[i];
            i++;
        } else {
            vector[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiamo i rimanenti elementi di L[], se ci sono
    while (i < n1) {
        vector[k] = L[i];
        i++;
        k++;
    }

    // Copiamo i rimanenti elementi di R[], se ci sono
    while (j < n2) {
        vector[k] = R[j];
        j++;
        k++;
    }
}

// Funzione ricorsiva per ordinare l'array usando Merge Sort
void mergeSort(int vector[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // Troviamo il punto medio

        // Ordiniamo la prima e la seconda metà
        mergeSort(vector, left, mid);
        mergeSort(vector, mid + 1, right);

        // Uniamo le due metà ordinate
        merge(vector, left, mid, right);
    }
}

// Funzione per stampare l'array
void printVector(int vector[], int size) {
    cout << "______VECTOR________" << endl;
    for (int i = 0; i < size; ++i) {
        cout << "vector[" << i << "] -> " << vector[i] << endl;
    }
    cout << "______VECTOR________" << endl;
}

int main() {
    int vector[5] = {4, 2, 6, 0, 12};
    int vector1[5] = {111, 70, 102, 1, 111};

    cout << "Original vector:" << endl;
    printVector(vector, 5);

    mergeSort(vector, 0, 4);

    cout << "Sorted vector:" << endl;
    printVector(vector, 5);

    cout << "Original vector1:" << endl;
    printVector(vector1, 5);

    mergeSort(vector1, 0, 4);

    cout << "Sorted vector1:" << endl;
    printVector(vector1, 5);

    return 0;
}