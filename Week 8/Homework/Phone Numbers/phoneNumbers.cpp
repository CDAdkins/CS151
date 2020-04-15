/*  phoneNumbers.cpp
    Author: Chris Adkins
    Module: 8
    Project: Homework 3
    Problem Statement: This program creates an array of names and phone numbers and allows users to search within it.

    Algorithm:
        1. Create the array of strings.
        2. Create a string to hld the search term.
        3. Use the getline() function to read input from the user into the search string.
        4. Create a function to search the array for the search term.
            a. Create a boolean value to indicate if any results have been found.
            b. Iterate over every string in the array.
            c. use the find() function to search the current string for the search term.
            d. If the term is found, print the entire string to the user and set the found bool to true;
            e. If nothing is found, tell the user there are no results.

    Classes Needed:
        <iostream> - For printing to the user.
        <string>   - For find() and getline().
*/

#include <iostream>
#include <string>

using namespace std;

void search(string name, string numbers[]);

int main() {
    string numbers[] = { // Our name and number database.
        "Hoshikawa Tanaka, 678-1223",
        "Joe Looney, 586-0097",
        "Geri Palmer, 223-8787",
        "Lynn Lopez, 887-1212",
        "Holly Gaddis, 223-8878",
        "Julio Reyes, 486-0998",
        "Bob Kain, 586-8712",
        "Jacques Franc, 586-7676",
        "Warren Glover, 223-9037",
        "Jeane Rodriguez, 678-4939",
        "Ron Palmer, 486-2783"
    };

    string name; // The search term we will be using.
    cout << "Enter the name / number you'd like to search for (case-sensitive): ";
    getline(cin, name); // Setting the user input to the name string,
    search(name, numbers); // Calling our search function with our search term.
}

void search(string name, string numbers[]) {
    bool found = false; // Becomes true if a match is found.
    cout << "\nSearch Results:\n---------------\n";
    for (int i = 0; i < 11; i++) { // Iterate over every string in the array.
        if (numbers[i].find(name) < 50) { // If we find a match in the current string.
            cout << numbers[i] << "\n"; // Print the current string to the user.
            found = true; // Set our boolean to true.
        }
    }
    if (!found) { // If we never find a match.
        cout << "No Matches Found...\n";
    }
}