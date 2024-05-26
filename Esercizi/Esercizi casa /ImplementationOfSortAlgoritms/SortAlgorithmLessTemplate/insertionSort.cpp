#include <iostream>
using namespace std;

void insertionSort(int vector[], int size);
void printVector(int vector[], int size);

int main() {
    int vector[5] = {4, 2, 6, 0, 12};
    int vector1[5] = {111, 70, 102, 1, 111};

    cout << "Original vector:" << endl;
    printVector(vector, 5);

    insertionSort(vector, 5);

    cout << "Sorted vector:" << endl;
    printVector(vector, 5);

    cout << "Original vector1:" << endl;
    printVector(vector1, 5);

    insertionSort(vector1, 5);

    cout << "Sorted vector1:" << endl;
    printVector(vector1, 5);

    return 0;
}

void insertionSort(int vector[], int size) {
    for (int i = 1; i < size; ++i) {
        int temp = vector[i];
        int j = i - 1;
        // Sposta gli elementi di vector[0..i-1] che sono maggiori di temp
        // di una posizione in avanti rispetto alla loro posizione attuale
        while (j >= 0 && vector[j] > temp) {
            vector[j + 1] = vector[j];
            j--;
        }
        vector[j + 1] = temp;
    }
}

void printVector(int vector[], int size) {
    cout << "______VECTOR________" << endl;
    for (int i = 0; i < size; ++i) {
        cout << "vector[" << i << "] -> " << vector[i] << endl;
    }
    cout << "______VECTOR________" << endl;
}
