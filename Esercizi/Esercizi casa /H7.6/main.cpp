#include <iostream>
#include "Rectangle.h"
void arrayInt(int vectorInt[], int size);
void arrayChar(char vectorChar[], int size);
void arrayRectangle(int size);

using namespace std;

template<typename T>
void sortElements(T vector[], int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (vector[i] < vector[j]) {
                T temp = vector[i];
                vector[i] = vector[j];
                vector[j] = temp;
            }
        }
    }
}


int main(int argc, char *argv[]) {
    int vectorInt[5]={2,1,5,90,3};
    char vectorChar[5]={'b','a','c','f','h'};
    arrayInt(vectorInt,4);
    arrayChar(vectorChar,4);
    arrayRectangle(4);
}

void arrayInt(int vectorInt[], int size){
    cout<<"_____ NO SORT_____"<<endl;
    for (int i = 0; i < size; ++i) {
        cout<<vectorInt[i]<<endl;
    }
    cout<<"_____ NO SORT_____"<<endl;
    sortElements(vectorInt, size);

    cout<<"_____SORT_____"<<endl;
    for (int i = 0; i < size; ++i) {
        cout<<vectorInt[i]<<endl;
    }
    cout<<"_____SORT_____"<<endl;
}

void arrayChar(char vectorChar[], int size){
    cout<<"_____ NO SORT_____"<<endl;
    for (int i = 0; i < size; ++i) {
        cout<<vectorChar[i]<<endl;
    }
    cout<<"_____ NO SORT_____"<<endl;
    sortElements(vectorChar, size);

    cout<<"_____SORT_____"<<endl;
    for (int i = 0; i < size; ++i) {
        cout<<vectorChar[i]<<endl;
    }
    cout<<"_____SORT_____"<<endl;
}


void arrayRectangle(int size){
    double height,width;
    Rectangle vectorRectangle[size];
    for (int i = 0; i < size; ++i) {
        do {
            cout<<"Insert height"<<endl;
            cin>>height;

            cout<<"Insert width"<<endl;
            cin>>width;

        }while(height<0 && width <0);
        vectorRectangle[i]=Rectangle(height,width);
    }

    cout<<"_________ARRAY OF RECTANGLE______"<<endl;
    for (int i = 0; i < size; ++i) {
        vectorRectangle[i].print();
    }

    sortElements(vectorRectangle, size);

    for (int i = 0; i < size; ++i) {
        vectorRectangle[i].print();
    }
    cout<<"_________ARRAY OF RECTANGLE______"<<endl;
}





