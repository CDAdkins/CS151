/*  StringBoundsCheck.cpp
    Author: Chris Adkins
    Module: Homework 13
    Project: 1
    Problem Statement: This program derives from the string class and implements bounds checking with the [] operator.

    Algorithm:
        1. Create a BoundsException class.
        2. Create the BCheckString class.
            a. Create a constructor that passes the string to the base class's constructor.
            b. Overload the [] operator and check that the argument is >= 0 and less than the string's size.
            c. If the argument is out of bounds, throw a BoundsException error, if not return the char at the index.
        3. Create a BCheckString object and call the [] operator to demonstrate the exception's functionality.

    Classes Needed:
        <iostream> - For printing to the user.
*/

#include <iostream>
using namespace std;

class BoundsException {}; // Exception Class.

class BCheckString : public string {
    private:
        string str;
    public:
        BCheckString(string word) : string(word) {
            str = word;
        }

        char& operator[] (int i) { // Overloading the [] operator.
            if (i < 0 || i >= str.size()) {
                throw BoundsException(); // Thowing the exception.
            }
            return str[i];
        }
};

int main() {
    BCheckString words("I have 20 characters."); // Initializing our BCheckString.
    try {
        for (int i = 0; i < words.size() + 1; i++) { // Looping one too many times and reading a char outside of the string.
            cout << words[i];
        }
    } catch (BoundsException e) {
        cout << "\nIndex Out of Bounds Exception.\n";
    }
}