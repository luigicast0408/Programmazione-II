#include <iostream>
using namespace std;
template <typename T>
void selectionSort(T vector[], int size);
template <typename T>
void printVector(T vector[], int size);


int main(){
    int vector[5] = {4, 2, 6, 0, 12};
    int vector1[5] = {111, 70, 102, 1, 111};

    printVector(vector, 5);
    selectionSort(vector,5);
    printVector(vector,5);
}

template <typename T>
void selectionSort( T vector[], int size){
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size-1; ++j) {
            if (vector[i] > vector[j]){
                int temp=vector[i];
                vector[i]=vector[j];
                vector[j]=temp;
            }
        }
    }
}

template <typename T>
void printVector(T vector[], int size) {
    cout << "______VECTOR________" << endl;
    for (int i = 0; i < size; ++i) {
        cout << "vector->" << vector[i] << endl;
    }
    cout << "______VECTOR________" << endl;
}
