/*  Main.cpp
    Author: Chris Adkins
    Module: 7
    Project: Homework 2
    Problem Statement: This program creates a type of string that can be encrypted by incrementing the values of each character.


    Algorithm:
        1. Create a class called EncryptableString that derives from the string class.
        2. Create a constructor that simply calls the constructrof the base string class.
        3. Create a function called Encrypt() in the new class.
            a. Iterate through the string and use isalnum to find alphanumeric characters.
            b. If an alphanumeric character is found, increment its value by one.

    Classes Needed:
        <iostream> - For printing to the user.
        "EncryptableString.h" - To demonstrate the class.
*/

#include "EncryptableString.h"
#include <iostream>

using namespace std;

int main() {
    // Initializing our encryptable strings.
    EncryptableString test1("Holy Moly!");
    EncryptableString test2("San Diego Zoo");
    EncryptableString test3("The cost is $25.89.");
    EncryptableString test4("Go away - unless you have tacos.");
    EncryptableString test5("No one can make you feel inferior without your consent.");

    
    // Printing Original Strings.
    cout << "\n\nOriginal Strings:\n";
    cout << test1 << endl;
    cout << test2 << endl;
    cout << test3 << endl;
    cout << test4 << endl;
    cout << test5 << endl;
    // Encrypting Strings.
    test1.encrypt();
    test2.encrypt();
    test3.encrypt();
    test4.encrypt();
    test5.encrypt();
    // Printing Encrypted Strings.
    cout << "\n\nEncrypted Strings:\n";
    cout << test1 << endl;
    cout << test2 << endl;
    cout << test3 << endl;
    cout << test4 << endl;
    cout << test5 << endl;

}