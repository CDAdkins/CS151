/*  isMember.cpp
    Author: Chris Adkins
    Module: 11
    Project: Homework 2
    Problem Statement: This program recursively takes an int array and searches it for an int specified by the user.

    Algorithm:
        1. Create an int called num to represent the number we are searching.
        2. Create an array of ints.
        3. Ask the user how many elements will be in the array.
        4. Write a for loop to allow the user to enter a list of ints.
        5. Ask the user what number they'd like to search the array for.
        6. Create a function called isMember().
            a. Create an index and initialize it to -1.
            b. Create a boolean value called found, set it to false.
            c. Increment the index.
            d. As long as the index is less than the number of elements in the array.
            e. If you find the int, set found to true, if not, call the function again.
            f. Return found.

    Classes Needed:
        <iostream> - For printing to the user.
*/

#include <iostream>

using namespace std;

bool isMember(int[], int, int);

int main() {
    int num; // The number we are searching for.
    int numberOfInts; // The number of elements in the array.

    cout << "How many numbers will be in the array? ";
    cin >> numberOfInts; // populating the variable with the user's input.

    int numbers[numberOfInts]; // Initializing our int array.

    cout << "Enter an int, then press enter. Repeat until done.\n";
    for (int i = 0; i < numberOfInts; i++) { // Looping once per element in the array.
        cout << i + 1 << ": ";
        cin >> numbers[i];
    }

    cout << "Enter a number to search for: ";
    cin >> num;

    if (isMember(numbers, numberOfInts, num)) { // Calling our isMember function with the input from our user.
        cout << num << " is in the array.\n";
    } else {
        cout << num << " is not in the array.\n";
    }
}

bool isMember(int numbers[], int numberOfInts, int num) {
    static int ndx = -1; // Increments every time the function is called.
    static bool found = false; // Starts as false, is set to true if the int is found.
    ndx++; // Incrementing the index.
    if (ndx < numberOfInts) { // If the function has been called less than the amount of ints in the array.
        if (num == numbers[ndx]) { // If the number at the current index is equal to the number we are searching for.
            found = true; // Set our found variable to true.
        } else {
            isMember(numbers, numberOfInts, num); // Call the function again.
        }
    }
    return found; // Return whether or not the int was found.
}