/*  Main.cpp
    Author: Chris Adkins
    Module: 3
    Project: 1
    Problem Statement: 
    This program takes input from the user to create a dynamically allocated array full of test scores and finds an average.

    Algorithm:
        1. Create a pointer to an int array with a size based on user input.
        2. Create a loop to allow the user to enter the test scores for each test.
        3. Create a method to sort the test scores.
            a. use a temp and swapped variable to keep track of what has been swapped.
            b. loop through the scores and compare test score values. 
            c. Swap smaller values wih larger values to sort in ascending order.
        4. Print the sorted list to the user.
        5. Create a method to find the average score from the array.
            a. Loop through the array and add up the total sum.
            b. Divide the sum by the total number of scores and print the average to the user.

    Classes Needed:
        <iostream> - For printing to the user
        <iomanip> - For print formatting.
*/

#include <iostream>
#include <iomanip>

using namespace std;

void sortScores(double* ptr, int size) {
    double temp; // Temp used for swapping scores.
    bool swapped = true;

    while (swapped) {
        swapped = false;
        for (int i = 0; i < size - 1; i++) { // Loop through the test scores.
            if (*(ptr + i) > *(ptr + i + 1)) { // If the next element is larger than our current element.
                temp = *(ptr + i + 1); // Set temp to the next element.
                *(ptr + i+1) = *(ptr + i); // Move current element forward one place.
                *(ptr + i) = temp; // Set the current position to the score stored in temp.
                swapped = true; // Indicate that a swap has occurred.
            }
        }
    }
}

double averageScore(double* ptr, int size) {
    double total = 0;

    for (int i = 0; i < size; i++) {
        total += *(ptr + i);
    }

    return (double)total/size;
}

int main() {
    int numTests; // The number of test scores that will be stored.

    cout << "How many test scores are you storing: ";
    cin >> numTests;

    double* testScores = new double[numTests]; // Create array based on user input.

    for(int i = 0; i < numTests; i++) { // Loop once per test score.
        cout << "Test " << i + 1 << ": ";
        cin >> *(testScores + i); // Fill the array with inputs from user.

        while(*(testScores + i) < 0) { // Check to see if inputs are less than zero.
            cout << "Only enter positive values for test scores.\n"; // Print errors and get new input.
            cout << "Test " << i + 1 << ": ";
            cin >> *(testScores + i);
        }
    }

    sortScores(testScores, numTests); // Call the sort method.

    cout << fixed << setprecision(1); // Limit decimals to tenths place.

    cout << "\nSorted Scores: \n"; // Print sorted scores to user.
    for(int i = 0; i < numTests; i++) {
        cout << *(testScores + i) << ", ";
    }

    // print message for average
    cout << "\n\nAverage Score: ";
    cout << averageScore(testScores, numTests);

    delete[] testScores;
}