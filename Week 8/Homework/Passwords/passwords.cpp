/*  passwords.cpp
    Author: Chris Adkins
    Module: 8
    Project: Homework 2
    Problem Statement: This program takes a password and checks it against security criteria.

    Algorithm:
        1. Create a character array to be populated by the user.
        2. Use cin.getline() to get the input from the user and populate the array.
        3. Create a function to check the password against the criteria.
            a. Initialize three boolean values for the three security criteria.
            b. Loop through every character in the string.
            c. If a character satisfies a security criteria, set the corresponding boolean to true.
        4. Tell the user whether or not their password meets all of the criteria.

    Classes Needed:
        <iostream> - For printing to the user.
        <cstring> - For strlen.
*/

#include <iostream>
#include <cstring>

using namespace std;

bool checkPassword(char password[]);

int main() {
    const int SIZE = 100;
    char password[SIZE];

    cout << "\nEnter a password: ";
    cin.getline(password, SIZE);

    if (checkPassword(password)) {
        cout << "Your password meets all of the security conditions.\n";
    } else {
        cout << "\nYour password does not meet all of the security conditions.\n";
    }
}


bool checkPassword(char password[]) { // Returns true if conditions are met, false if they are not.
    bool sixChars = false;  // Does the password have at least six characters.
    bool hasUpper = false;  // Does the password have at least one uppercase character.
    bool hasLower = false;  // Does the password have at least one lowercase character.
    bool hasNumber = false; // Does the password contain at least one number.

    if (strlen(password) < 6) { // If we have less than six characters.
    cout << "\nYou must have at least six characters.";
        return false; //End the function and return false.
    } else {
        sixChars = true;
    }

    for (int i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) { // If we have an uppercase character.
            hasUpper = true; // This condition is fulfilled.
        }
        if (islower(password[i])) { // If we have a lowercase character.
            hasLower = true; // The lowercase condition is fulfilled.
        }
        if (isdigit(password[i])) {
            hasNumber = true;
        }
    }
    if (hasUpper && hasLower && hasNumber) { // If every condition is fulfilled.
        return true;
    } else { // The section below tells the user what their password is missing.
        if (!hasUpper) {
            cout << "\nYour password must include an upper case character.";
        }
        if (!hasLower) {
            cout << "\nYour password must include a lower case character";
        }
        if (!hasNumber) {
            cout << "\nYour password must include a number.";
        }
        return false;
    }
}