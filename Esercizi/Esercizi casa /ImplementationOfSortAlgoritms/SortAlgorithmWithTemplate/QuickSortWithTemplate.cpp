#include <iostream>
using namespace std;

template <typename T>
void printVector(T* vector, int size);

template <typename T>
void quickSort(T* vector, int size);

template <typename T>
void quickSort(T* vector, int  left, int right,int size);



int main(){

}

template <typename T>
void printVector(T* vector, int size){
    cout<<"____VECTOR_____"<<endl;
    for (int i = 0; i < size; ++i) {
        cout<<"vector["<<i<<"]"<<"="<<vector[i]<<endl;
    }
    cout<<"____VECTOR_____"<<endl;
}

template <typename T>
void quickSort(T* vector, int  left, int right,int size){
  int i=left, j=right;
  int pivot = vector[(left + right) / 2];
  int temp;
    while (i >= j){
        while (vector[i] < pivot) i++;
        while (vector[i] > pivot) j--;
        temp=vector[i];
        if (i <= j){
            vector[i]=vector[j];
            vector[j]=temp;
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

template <typename T>
void quickSort(T vector[], int size) {
    quickSort(vector, 0, size - 1); // Chiamata alla funzione quickSort con gli indici iniziali dell'array
}

