/*  SimpleVector.cpp
    Author: Chris Adkins
    Module: Homework 13
    Project: 7
    Problem Statement: This program modifies the SimpleVector class to include a push_back and pop_back function.

    Algorithm:
        1. Add the sort function().
            a. Create two for loops, one inside the other.
            b. If the value on the left is higher than the value on the right, swap them.
            c. Print the results to the user.

    Classes Needed:
        <iostream> - For printing to the user.
*/

#include <iostream>
using namespace std;

template <class T>
class SortableVector {
    T *aptr;
    int arraySize;
public:
    SortableVector(int num) { // Constructor.
        arraySize = num;
        aptr = new T[arraySize];
        for (int i = 0; i < arraySize; i++) {
            aptr[i] = T();
        }
    }

    SortableVector(const SortableVector &obj) { // Copy Constructor.
        arraySize = obj.arraySize;
        aptr = new T[arraySize];
        for (int i = 0; i < arraySize; i++) {
            aptr[i] = obj[i];
        }
    }

    ~SortableVector() { // Destructor.
        if (arraySize > 0) {
            delete [] aptr;
        }
    }

    int size() const {
        return arraySize;
    }

    T &operator[](int num) { // Overloaded [] operator.
        if (num < 0 || num >= arraySize) {
            throw string("Index Out of Bounds Error.\n");
        }
        return aptr[num];
    }

    void print() const {
        for (int i = 0; i < arraySize; i++) {
            cout << aptr[i];
            i == (arraySize - 1) ? cout << "\n" : cout << ", "; // Print a comma unless it's the final element.
        }
    }

    void push_back(T val) {
        T *tempPtr = new T [arraySize + 1];
        for (int i = 0; i < arraySize; i++) { // Copying the old array into the new array.
            tempPtr[i] = aptr[i];
        }
        tempPtr[arraySize] = val; // Placing the value at the end of the new array.

        if (arraySize > 0) // Deleting the old array.
            delete [] aptr;

        aptr = tempPtr; // Assigning aptr to the new array.
        arraySize++; // Increment the array size.
    }

    T pop_back() {
        if (arraySize == 0)
            throw string("Vector is empty.\n");
        else {
            T lastValue = aptr[arraySize - 1]; // Hold the last value.
            T *tempPtr = new T [arraySize - 1]; // Create a new array, one element smaller.
            for (int i = 0; i < arraySize - 1; i++) {
                tempPtr[i] = aptr[i];
            }

            delete [] aptr; // Delete the old array.
            aptr = tempPtr; // Point aptr to the new array.
            arraySize--; // Decrement the array size.
            return lastValue; // Return the last value from the old array.
        }
    }

    void sort() { // Bubble Sort
        for (int i = 0; i < SortableVector<T>::arraySize; i++) {
            for (int x = 0; x < SortableVector<T>::arraySize; x++) {
                if (SortableVector<T>::aptr[x] > SortableVector<T>::aptr[x + 1] && x + 1 <= SortableVector<T>::arraySize) {
                    swap(SortableVector<T>::aptr[x], SortableVector<T>::aptr[x + 1]);
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