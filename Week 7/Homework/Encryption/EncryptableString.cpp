/*  EncryptableString.cpp
    Author: Chris Adkins
    Module: 7
    Project: Homework 2
    File Description: This is the EncryptableString class. It derives from the string class. 
                      It contains a function called encrypt() that will obfuscate the string very basically.
*/

#include "EncryptableString.h"

EncryptableString::EncryptableString(string word) : string(word) {
    //Just calling the base class constructor.
}

void EncryptableString::encrypt() {
    for (int i = 0; i < this->length(); i++) { // This for loop looks for alphanumeric characters.
        if (isalnum((*this)[i])) { // If the char at the current index is alphanumeric.
            (*this)[i]++; // Increment the value of the char by one.
        }
    }
}