#include <iostream>
using namespace std;

template <typename T>
void bubbleSort(T vector[], int size);
template <typename T>
void bubbleSortWithBool(T vector[], int size);
template <typename T>
void printVector(T vector[], int size);
template <typename T>
void mySwap(T& a, T& b);

int main(){
    int arr[] = {5, 3, 8, 4, 2};
    int arr1[] = {9, 4, 2, 410, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array:" << endl;
    printVector(arr, size);
    printVector(arr1,size);

    bubbleSort(arr, size);
    bubbleSort(arr1,size);

    cout << "Sorted array:" << endl;
    printVector(arr, size);

    cout << "Sorted array:" << endl;
    printVector(arr1, size);


    return 0;
}

template <typename T>
void bubbleSort(T vector[], int size){
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (vector[j] > vector[j + 1]) {
                mySwap(vector[j], vector[j + 1]);
            }
        }
    }
}

template <typename T>
void mySwap(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
void printVector(T vector[], int size){
    for (int i = 0; i < size; ++i) {
        cout << "Vector[" << i << "] = " << vector[i] << endl;
    }
}
template <typename T>
void bubbleSortWithBool(T vector[], int size){int temp;
    bool swap;
    do {
        swap = false;
        for (int i = 0; i < size - 1; i++) {
            if (vector[i] > vector[i + 1]) {
                mySwap(vector[i], vector[i+1]);
                swap = true;
            }
        }
    } while (swap);
}