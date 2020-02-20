/*  time.cpp
    Author: Chris Adkins
    Module: 4
    Project: Excercise 1
    Problem Statement: 
    This program is a demonstration of the different ways time can be represented in C++.

    Algorithm:
        1. Create a pill structure with variables for a letter and a number of attempts.
        2. Create an array to hold 10 unique pointers to pills.
        3. Loop 10 times and create a pill for each loop.
        4. Randomly generate an int and attempt to put the pill in that slot.
        5. If the slot is open, break the loop and create a new pill.
        6. If the slot isn't open, generate a new number and increment numAttempts.
        7. Once pills have been placed in array, print a report using cout and iomanip to format it.
        8. Loop through the array and use a bubble sort to sort the pills by their letter.
        9. Print the alphabetical list the same way the previous report was printed.

    Classes Needed:
        <ctime>    - For presenting the time to the user.
        <iostream> - For printing to the user.
        <memory>   - For access to unique_ptr.
        <iomanip>  - For formatting the report.

*/

#include <iostream>
#include <iomanip>
#include <memory>
#include <ctime>

using namespace std;

int main() {
    struct pill {
        char letter; // Letter that differentiates the pills.
        int numAttempts; // Number of attempts it took to find an available slot.
        int initialSlot; // Used to keep track of the slot that the pill was first placed in.

        pill(char letter, int numAttempts){ // Pill constructor.
            this->letter = letter;
            this->numAttempts = numAttempts;
        }
    };

    srand(time(NULL));

    unique_ptr<pill> slots[10]; // Array of unique pointers that point to pills.
    char letters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int totalAttempts = 0; // Total number of attempts to place pills in slots.

    for (int i = 0; i < 10; i++) { // The outer loop occurs once per pill.
        int numAttempts = 0;
        bool slotFound = false;
        while(!slotFound) { // While a slot has not been found.
            int randNum = (rand() % 10); // Generate a random number between 0 and 9.
            numAttempts++; // Increment the number of attempts for this pill.
            if (!slots[randNum]) { // If we find an empty slot.
                slotFound; // Set our boolean to true;
                unique_ptr<pill> newPill(new pill(letters[i], numAttempts)); // Create a new pill.
                newPill->initialSlot = randNum;
                slots[randNum] = move(newPill); // Move the newly created pill into the slots[] array.
                break;
            }
        }
    }

    cout << "\nUnsorted List:\nSlot  Pill  Attempts\n----  ----  --------\n"; // Printing the unsorted list.
    for (int i = 0; i < 10; i++) { // Loop once per pill.
        totalAttempts += slots[i]->numAttempts; // Add the number of attempts per pill to the total.
        cout << setw(4) << right << slots[i]->initialSlot << setw(6) << slots[i]->letter << setw(8) << slots[i]->numAttempts << endl;
    }
    cout << "\nTotal Attempts: " << totalAttempts << endl;

    for (int i = 0; i < 9; i++) {
        for (int i = 0; i < 9; i++) {
            if (slots[i]->letter > slots[i + 1]->letter) { // If the current pill's letter comes after the next pill's letter.
                swap(slots[i], slots[i + 1]); // Swap the pill's positions.
            }
        }
    }


    cout << "\nSorted List:\nSlot  Pill  Attempts\n----  ----  --------\n"; // Printing the sorted list.
    for (int i = 0; i < 10; i++) { // Loop once per pill.
        cout << setw(4) << right << slots[i]->initialSlot << setw(6) << slots[i]->letter << setw(8) << slots[i]->numAttempts << endl;
    }
    cout << "\nTotal Attempts: " << totalAttempts << endl;
}