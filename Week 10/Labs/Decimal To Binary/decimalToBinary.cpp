/*  decimalToBinary.cpp
    Author: Chris Adkins
    Module: 11
    Project: Lab 1
    Problem Statement: This program converts decimal numbers into binary through both iterative, and recursive means.

    Algorithm:
        1. Create a function to recursively convert decimal into binary.
            a. Create a static string to hold your binary characters.
            b. Use the insert() function to add the given num%2 to your string at the beginning.
            c. If the num is still > 1, call the function again with num/2 as an argument.
            d. If the number is not > 1, return the string.
        2. Create an iterative function to convert decimal to binary.
            a. Create a string to hold your binary number.
            b. While the int num is greater than 0.
            c. Insert num%2 at the beginning of your binary string.
            d. Set num equal to itself divided by two.
            e. Once the while loop has concluded, return the binary string.

    Classes Needed:
        <iostream> - For printing to the user.
*/

#include <iostream>

using namespace std;

string iterativeConversion(int);
string recursiveConversion(int);

int main() {
    int num;
    cout << "\nBinary Number Converter\n";
    cout << "-----------------------\n";
    cout << "Enter a number: ";
    cin >> num;

    cout << "Iterative Function: " << iterativeConversion(num) << endl; // Calling our iterative function.
    cout << "Recursive Function: " << recursiveConversion(num) << endl; // Calling our recursive function.
}

string recursiveConversion(int num) { // Recursive function.
    static string binary; // static string holds it's value between calls.
    binary.insert(0, to_string(num%2)); // Inserting the num%2 value at the beginning of the binary string.

    if (num > 1) {
        recursiveConversion(num/2); // Recursive call with num/2 as argument.
    }
    return binary; // Once we have run the function to the point where num is = 1, return the string.
}

string iterativeConversion(int num) { // Iterative function.
    string binary; // String to hold the binary version of the number.
    while (num > 0) { // While the int is greater than 0.
        binary.insert(0, to_string(num%2)); // Insert the result of num%2 at the beginning of the string.
        num /= 2; // Half the value of the number before the next loop.
    }
    return binary; // Return the string containing the binary version of the number.
}