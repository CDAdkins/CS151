/*  sorting.cpp
    Author: Chris Adkins
    Module: Homework 12
    Project: 1
    Problem Statement: This program creates an abstract class, then implements its functions in a subclass.

    Algorithm:
        1. Create the AbstractSort class.
            a. Create the abstract sort function.
            b. Implement a compare function to return how two ints compare to eachother.
            c. Create an int to represent the number of comparisons made in a sort.
        2. Create a subclass of the AbstractSort class.
            a. Override the sort function to use an actual sorting algorithm.
            b. Bubble sort requires an inner and outer loop with a swap function included.
        3. Create an object from the subclass.
        4. Print an array before and after sorting it with the subclass.

    Classes Needed:
        <iostream> - For printing to the user.
*/

#include <iostream>
using namespace std;

class AbstractSort {
    private:
        int comparisons = 0; // Keeps track of the number of comparisons being made.
    protected:
        virtual void sort(int arr[], int size) = 0; // Abstract member function.

        bool compare(int a, int b) { // Function to compare two int variables.
            comparisons++; // Increment the comparisons variable.
            if (a > b) {
                return true; 
            } else {
                return false;
            }
        }

        int getComparisons() {
            return comparisons;
        }
};

class BubbleSort : public AbstractSort { // Subclass of AbstractSort
    public:
        virtual void sort(int arr[], int size) { // Bubble Sort function.
            for (int i = 0; i < size; i++) { // Outer Loop
                for (int x = 0; x < size; x++) { // Inner Loop
                    if (compare(arr[x], arr[x + 1]) && (x + 1) < size) { // If the next int is greater than the current int.
                        swap(arr[x], arr[x + 1]); // Swap the two ints.
                    }
                }
            }
            cout << "Number of Comparisons: " << this->getComparisons() << endl;
        }
};

int main() {
    const int SIZE = 10;
    int arr[SIZE] = {4, 7, 2, 12, 99, 3, 53, 70, 21, 33}; // Initial, unsorted array.
    BubbleSort bubble; // Creating a BubbleSort object.

    cout << "\nBefore Sorting:\n";
    for (int i = 0; i < SIZE; i++) { // Loop to print the array before sorting it.
        i < 9 ? cout << arr[i] << ", " : cout << arr[i] << "\n";
    }
    cout << "\n";


    cout << "After Sorting:\n";
    bubble.sort(arr, SIZE); // Calling our sort function 
    for (int i = 0; i < SIZE; i++) { // Loop to print the array after sorting it.
        i < 9 ? cout << arr[i] << ", " : cout << arr[i] << "\n";
    }
}