#include <iostream>
#include <string>
#include <cmath>
#include "Point.h"
void arrayInt(int vectorInt[], int size,int data);
void arrayChar(char vectorChar[], int size,char data);
void arrayPoint(int size,int Xc, int Yc);
using namespace std;

template<typename T>
int searchElement(T data, T vector[], int size){
    for (int i = 0; i < size; ++i) {
        if (vector[i]==data){
            return  i;
        }
    }
    return -1;
}

template<typename T>
void printVector(T vector[], int size){
    for (int i = 0; i < size; ++i) {
        cout<<vector[i]<<endl;
    }
}

int main() {

    int vectorInt[] = {1, 2, 3, 4, 5};
    int sizeInt = sizeof(vectorInt) / sizeof(vectorInt[0]);
    int searchDataInt;
    cout << "Enter the value to search in the array of integers: "<<endl;
    cin >> searchDataInt;
    arrayInt(vectorInt, sizeInt, searchDataInt);

    char vectorChar[] = {'a', 'b', 'c', 'd', 'e'};
    int sizeChar = sizeof(vectorChar) / sizeof(vectorChar[0]);
    char searchDataChar;
    cout << "Enter the character to search in the array of characters: "<<endl;
    cin >> searchDataChar;
    arrayChar(vectorChar, sizeChar, searchDataChar);

    int size;
    cout << "Enter the number of points you want to insert: "<<endl;
    cin >> size;

    int Xc, Yc;
    cout << "Enter the X and Y coordinates of the point to search in the array of points: "<<endl;
    cin >> Xc >> Yc;
    arrayPoint(size, Xc, Yc);

    return 0;
}

void arrayInt(int vectorInt[], int size, int data){
    printVector(vectorInt,size);
    if (int position=searchElement(data,vectorInt,size)!=-1){
        cout<<"Data found at the position "<<position<<endl;
    } else{
        cout<<"Data not found" <<endl;
    }
}

void arrayChar(char vectorChar[], int size,char data){
    printVector(vectorChar,size);
    if(int position=searchElement(data,vectorChar,size)!= -1 ){
        cout<<"Data found at the position"<<position<<endl;
    } else {
        cout<<"Data not found "<<endl;
    }
}

void arrayPoint(int size, int Xc, int Yc){
    Point vectorPointer[size];

    for (int i = 0; i < size; ++i) {
        Point point = Point(Xc + i, Yc + i);
        vectorPointer[i] = point;
    }

    cout << "Array of points:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << vectorPointer[i];
    }

    Point searchPoint = Point(Xc, Yc);
    if (int position = searchElement(searchPoint, vectorPointer, size) != -1) {
        cout << "Data found at position " << position << endl;
    } else {
        cout << "Data not found" << endl;
    }
}
