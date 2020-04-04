/*  PString.cpp
    Author: Chris Adkins
    Module: 7
    Project: Homework 1
    File Description: This is the PString class. It derives from the string class. It also has a palindrome checking function.
*/

#include <iostream>
#include <string>
#include "PString.h"


PString::PString(string word) :string(word) { // This constructor takes a string and passes it into the STL string's constructor.
    
}

bool PString::isPalindrome() { // Function for deciding whether or not a string is a palindrome.
    string original = *this; // The unmodified string before we remove non-alphanumeric characters.
    for (int i = 0; i < this->length(); i++) { // This for loop rids the string of any non-alphanumeric characters.
        if (!isalnum((*this)[i])) { // If the char at the current index is not alphanumeric.
            this->erase(i, 1); // Erase the character at the current index.
            i--; // If we delete a character, we will also move our index back one.
        }
    }
    for (int i = 0; i < this->length(); i++) {
        if (toupper((*this)[i]) != toupper((*this)[this->length() - i - 1])) { // If (Adjusting for capitalizations) the two characters are not equal.
            cout << "\"" << original << "\" is not a palindrome.\n"; // Inform the user of the result.
            return false;
        }
    }
    cout << "\"" << original << "\" is a palindrome!" << endl; // This code only ever runs if the string is a palindrome.
    return true;
}