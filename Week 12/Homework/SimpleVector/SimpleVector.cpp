/*  SimpleVector.cpp
    Author: Chris Adkins
    Module: Homework 13
    Project: 7
    Problem Statement: This program modifies the SimpleVector class to include a push_back and pop_back function.

    Algorithm:
        1. Add the push_back function.
            a. Create a new array one element larger than the old one.
            b. Copy the old array into the new array.
            c. Copy the argument into the new array at the end.
            d. Delete the old array and increment the array size.
        2. Add the pop_back function.
            a. Make sure the vector is not empty, if so, throw an error.
            b. Create a new array, one element smaller than the current one.
            c. Copy all but the last element into the new array.
            d. Save the last element in the old array.
            e. Delete the old array, decrement the array size.
            f. Return the last value that was saved earlier.

    Classes Needed:
        <iostream> - For printing to the user.
*/

#include <iostream>
using namespace std;

template <class T>
class SimpleVector {
    T *aptr;
    int arraySize;
public:
    SimpleVector(int num) { // Constructor.
        arraySize = num;
        aptr = new T[arraySize];
        for (int i = 0; i < arraySize; i++) {
            aptr[i] = T();
        }
    }

    SimpleVector(const SimpleVector &obj) { // Copy Constructor.
        arraySize = obj.arraySize;
        aptr = new T[arraySize];
        for (int i = 0; i < arraySize; i++) {
            aptr[i] = obj[i];
        }
    }

    ~SimpleVector() { // Destructor.
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
};

int main() {
    cout << "Int Vector Demonstration:\n";
    cout << "-------------------------\n";
    SimpleVector<int> intVector(0); // Creating an empty vector of ints.
    try {
        intVector[0] = 1; // Trying to access an element that doesn't exist.
    } catch (string e) {
        cout << e;
    }

    try {
        intVector.pop_back(); // Trying to pop an element off of an empty vector.
    } catch (string e) {
        cout << e;
    }
    // Adding some ints to the vector using the push_back function.
    intVector.push_back(1);
    intVector.push_back(2);
    intVector.push_back(3);
    intVector.push_back(4);
    intVector.push_back(5);
    // Printing the vector.
    intVector.print();
    // popping an element off of the stack with pop_back().
    cout << intVector.pop_back() << endl;
    // Printing the vector after popping the element off.
    intVector.print();

    cout << "\nString Vector Demonstration:\n";
    cout << "----------------------------\n";
    SimpleVector<string> stringVector(0);
    try {
        stringVector[0] = "One"; // Trying to access an element that doesn't exist.
    } catch (string e) {
        cout << e;
    }

    try {
        stringVector.pop_back(); // Trying to pop an element off of an empty vector.
    } catch (string e) {
        cout << e;
    }
    // Adding some ints to the vector using the push_back function.
    stringVector.push_back("One");
    stringVector.push_back("Two");
    stringVector.push_back("Three");
    stringVector.push_back("Four");
    stringVector.push_back("Five");
    // Printing the vector.
    stringVector.print();
    // popping an element off of the stack with pop_back().
    cout << stringVector.pop_back() << endl;
    // Printing the vector after popping the element off.
    stringVector.print();
}