#include <iostream>
using namespace std;

void bubbleSort(int vector[], int size);
void bubbleSortWithBool(int vector[], int size);
void printVector(int vector[], int size);

int main() {
    int vector[5] = {4, 2, 6, 0, 12};
    int vector1[5] = {111, 70, 102, 1, 111};

    printVector(vector, 5);
    bubbleSort(vector, 5);
    printVector(vector, 5);

    printVector(vector1, 5);
    bubbleSortWithBool(vector1, 5);
    printVector(vector1, 5);

    return 0;
}

void bubbleSort(int vector[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (vector[j] > vector[j + 1]) {
                int temp = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = temp;
            }
        }
    }
}

void bubbleSortWithBool(int vector[], int size) {
    int temp;
    bool swap;
    do {
        swap = false;
        for (int i = 0; i < size - 1; i++) {
            if (vector[i] > vector[i + 1]) {
                temp = vector[i];
                vector[i] = vector[i + 1];
                vector[i + 1] = temp;
                swap = true;
            }
        }
    } while (swap);
}

void printVector(int vector[], int size) {
    cout << "______VECTOR________" << endl;
    for (int i = 0; i < size; ++i) {
        cout << "vector->" << vector[i] << endl;
    }
    cout << "______VECTOR________" << endl;
}
