/*  Main.cpp
    Author: Chris Adkins
    Module: 3
    Project: 3
    Problem Statement: 
    This program takes an array of 30 ints and finds the mode.

    Algorithm:
        1. Create a pointer to an int array with a size of 30.
        2. Loop 30 times and allow the user to populate the int array.
        3. Create a method to sort the array and find the mode.
            a. use a temp and swapped variable to keep track of what has been swapped.
            b. loop through the scores and compare test score values. 
            c. Swap smaller values wih larger values to sort in ascending order.
        4. Loop through the array and keep track of the int that is most often used in the array.
        5. Print the sorted array and the mode to the user.

    Classes Needed:
        <iostream> - For printing to the user
*/

#include <iostream>

using namespace std;

int pieMode(int* pies, int size) {
    double temp; // Temp used for swapping pies.
    bool swapped = true;

    while (swapped) {
        swapped = false;
        for (int i = 0; i < size - 1; i++) { // Loop through the test scores.
            if (*(pies + i) > *(pies + i + 1)) { // If the next element is larger than our current element.
                temp = *(pies + i + 1); // Set temp to the next element.
                *(pies + i+1) = *(pies + i); // Move current element forward one place.
                *(pies + i) = temp; // Set the current position to the score stored in temp.
                swapped = true; // Indicate that a swap has occurred.
            }
        }
    }

    int number = *(pies);
    int mode = number;
    int count = 1;
    int countMode = 1;
    for (int i = 0; i < size; i++) {
        if(*(pies + i) == number) {
            count++;
        } else {
            if (count > countMode) {
                countMode = count;
                mode = number;
            }
            count = 1;
            number = *(pies + i);
        }
    }
    return mode;
}

int main() {
    int* pies = new int[30];

    for (int i = 0; i < 30; i++) {
        cout << "How many pieces of pie does Person " << i + 1 << " eat? ";
        cin >> *(pies + i);
    }

    cout << "Sorted List:\n";
    for (int i = 0; i < 30; i++) {
        cout << *(pies + i) << ", ";
    }

    cout << "\nMode: " << pieMode(pies, 30);
}