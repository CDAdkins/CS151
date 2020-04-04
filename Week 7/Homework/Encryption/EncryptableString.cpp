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