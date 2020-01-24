/*  Project1_VectorSort.cpp
    Author: Chris Adkins
    Module: 1
    Project: 1
    Problem Statement: This code creates an empty int vector and populates it with sorted randomly generated ints.

    Algorithm:
        1. Create our vector.
        2. Use srand to create our seed.
        3. Create a loop that will create a random int 30 times.
        4. Use rand to create that random int.
        5. Use % to convert the int to an int between 1 - 10
        6. Create a second loop to check the vector for an insertion point.
        7. Compare the vector's ints to the random int, if the random int is larger, insert the int.
        8. Repeat 4 - 7 until done.
        9. Use back() to print the last item in the vector, then use pop_back() to remove it before using back() again.

    Classes Needed:
        iostream - For printing to the user
        vector   - Necessary to use vectors
        time.h   - To generate a random seed based on the time.
*/

#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

int main() {
    vector<int> numbersVector(30); // Vector with 30 ints that = 0.
    srand(time(NULL)); // Setting our random seed based on the time.
    int randomNum; // The int that will store our randomly generated int.

    for (int i = 0; i < 30; i++) { // One loop per int generated.
        randomNum = rand() % RAND_MAX; // Generate a random number between 0 and 2147483647
        randomNum = randomNum % 10 + 1; // Converting the *probably* massive number to something between 1 and 10
        for (int ndx = 0; ndx < 30; ndx++) { // Thirty loops to check the vector's ints for an insertion point.
            if (numbersVector[ndx] < randomNum || numbersVector.size() == 0) { // If we find an int in the vector that is smaller than our random int.
                cout << "numbersVector[" << ndx << "] = " << numbersVector[ndx] << ", inserting " << randomNum << endl; // Printing what we are doing
                numbersVector.insert(numbersVector.begin() + ndx, randomNum); // Insert our random int at the index we are currently looking at.
                break; // We break here to limit our program to one insertion per randomly generated int.
            }
        }
    }
    for (int i = 0; i < 30; i++) {
        numbersVector.pop_back(); // Popping the 0's off the stack.
    }
    cout << "\nSorted Vector:\n " << "["; // Printing our final, sorted vector.
    for (int i = 0; i < 30; i++) {
        if (i == 29) { // Formatting
            cout << numbersVector.back(); // Printing the last item in the vector
            numbersVector.pop_back(); // Removing the last item in the vector
        } else {
            cout << numbersVector.back() << ", "; // Printing the last item in the vector
            numbersVector.pop_back(); // Removing the last item in the vector
        }
    }
    cout << "]\n";
}
