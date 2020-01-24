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
            if (numbersVector[ndx] < randomNum) { // If we find an int in the vector that is smaller than our random int.
                cout << "numbersVector[" << ndx << "] = " << numbersVector[ndx] << ", inserting " << randomNum << endl; // Printing what we are doing
                numbersVector.insert(numbersVector.begin() + ndx, randomNum); // Insert our random int at the index we are currently looking at.
                break; // We break here to limit our program to one insertion per randomly generated int.
            }
        }
    }

    for (int i = 0; i < 30; i++) {
        numbersVector.pop_back();
    }

    cout << "\nSorted Vector:\n " << "["; // Printing our final, sorted vector.
    for (int i = 0; i < 30; i++) {
        if (i == 29) { // Formatting
            cout << numbersVector.back();
            numbersVector.pop_back();
        } else {
            cout << numbersVector.back() << ", ";
            numbersVector.pop_back();

        }
    }
    cout << "]\n";
}
