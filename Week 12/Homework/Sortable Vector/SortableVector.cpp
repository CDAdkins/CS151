/*  SortableVector.cpp
    Author: Chris Adkins
    Module: Homework 13
    Project: 9
    Problem Statement: This program modifies the SimpleVector class to include a sort function.

    Algorithm:
        1. Add the sort function.
            a. 

    Classes Needed:
        <iostream> - For printing to the user.
*/

#include <iostream>
#include "SimpleVector.h"
using namespace std;

template <class T>
class SortableVector : public SimpleVector<T> {
    private:
    public:
    /* SortableVector(int i) : SimpleVector<T>(i) {
        // Passing the constructor to our base class.
    } */

    SortableVector(int s) {
        SimpleVector<T>::arraySize = s ;
        SimpleVector<T>::aptr = new T [s] ;

        for (int count = 0 ; count < SimpleVector<T>::arraySize ; count++)
        *(SimpleVector<T>::aptr + count) = 0;
        
    }

    void print() {
        for (int i = 0; i < SimpleVector<T>::arraySize; i++) {
            cout << SimpleVector<T>::aptr[i];
            i == SimpleVector<T>::arraySize ? cout << "\n" : cout << ", ";
        }
    }

    void sort() {
        for (int i = 0; i < SimpleVector<T>::arraySize; i++) {
            for (int x = 0; x < SimpleVector<T>::arraySize; x++) {
                if (SimpleVector<T>::aptr[x] > SimpleVector<T>::aptr[x + 1] && x + 1 <= SimpleVector<T>::arraySize) {
                    swap(SimpleVector<T>::aptr[x], SimpleVector<T>::aptr[x + 1]);
                }
            }
        }
    }
};

int main() {
    //Sorting 10 doubles.
    SortableVector<double> doubleVector(0);
    // Populating our double vector.
    doubleVector.push_back(1.6);
    doubleVector.push_back(5.6);
    doubleVector.push_back(2.9);
    doubleVector.push_back(4.0);
    doubleVector.push_back(6.9);
    doubleVector.push_back(3.7);
    doubleVector.push_back(8.8);
    doubleVector.push_back(4.9);
    doubleVector.push_back(9.9);
    doubleVector.push_back(2.7);
    cout << "\nUnsorted Double Vector:\n";
    doubleVector.print();
    doubleVector.sort();
    cout << "Sorted Double Vector:\n";
    doubleVector.print();

    SortableVector<string> stringVector(0);
    // Populating our double vector.
    stringVector.push_back("Jack");
    stringVector.push_back("Johnny");
    stringVector.push_back("Eric");
    stringVector.push_back("Bradley");
    stringVector.push_back("Steve");
    stringVector.push_back("Terry");
    stringVector.push_back("Richard");
    stringVector.push_back("Greg");
    stringVector.push_back("Ron");
    stringVector.push_back("Leslie");
    cout << "\nUnsorted String Vector:\n";
    stringVector.print();
    stringVector.sort();
    cout << "Sorted String Vector:\n";
    stringVector.print();
}