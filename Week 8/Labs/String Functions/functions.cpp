/*  filename.cpp
    Author: Chris Adkins
    Module: Week 8
    Project: Lab 2
    Problem Statement: This program demonstrates a number of string functions.

    Algorithm:
        1. Create an int to be populated by a user's input.
        2. Use to_string to convert the int to a string.
        3. Use an istringstream to convert the string back to an int.
        4. Convert the int to a binary number.
        5. Use stoi to convert the binary back to an int.
        6. Use a stringstream to convert the int into hex.
        7. Use stringstream to convert the hex back into an int.

    Classes Needed:
        <iostream> - For printing to the user.
        <sstream>  - For istreamstream
*/

#include <iostream>
#include <sstream>

using namespace std;

int main() {
    int original = 0;
    string originalAsString;

    cout << "\nEnter an number: ";
    cin >> original;

    originalAsString = to_string(original) + " rah!";
    cout << "That number converted to string: " << originalAsString << endl;

    istringstream inpstr(originalAsString);
    int originalCopy;
    inpstr >> originalCopy;
    cout << "Converted back to a number: " << originalCopy << endl;

    char *binary = new char[33];
    *(binary + 32) = '\0';
    int index = 0;
    do {
        *(binary + (--index)) = (char) (originalCopy % 2 + '0');
        originalCopy /= 2;
    } while (originalCopy > 0); {
        cout << "That number in binary is: " << (binary + index) << endl;
    }

    originalCopy = stoi((binary + index), nullptr, 2);
    cout << "Back to decimal: " << originalCopy << endl;

    stringstream iostr;
    iostr << hex << original;
    cout << "The number in hex: 0x" << iostr.str() << endl;

    iostr >> dec >> original;
    cout << "Back to decimal again: " << originalCopy << endl;
}