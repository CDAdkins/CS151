/*  binaryToDecimal.cpp
    Author: Chris Adkins
    Module: 11
    Project: Lab 2
    Problem Statement: This program converts binary numbers to decimal through both iterative and recursive means.

    Algorithm:
        1. Create a function to convert the numbers using an iterative approach.
            a. Create an int to represent the sum.
            b. Create an int value for use as an index.
            c. Create a for loop to run once per char in the string argument.
            d. Convert the number at the current index of the string to an int.
            e. Add the number to the sum.
            f. Multiply the sum by two and increment the index.
            g. Once the for loop has concluded, return the sum/2.
        2. Create a function to convert the numbers recursively.
            a. Create two static ints to represent the sum and the index.
            b. Create another int to represent the number at the index of the string.
            c. As long as our index is greater than 0.
                I. Decrement the index.
                II. Convert the next number in the string to an int.
                III. Add that number to the sum, then multiply the sum by two.
                IIII. Call the function again.
            d. return the sum/2.

    Classes Needed:
        <iostream> - For printing to the user.
*/

#include <iostream>

using namespace std;

int iterativeConversion(string);
int recursiveConversion(string);

int main() {
    string binary;
    cout << "\nBinary to Decimal Converter\n";
    cout << "---------------------------\n";
    cout << "Enter a Binary Number: ";
    cin >> binary;
    cout << "Iterative Function: " << iterativeConversion(binary) << endl;
    cout << "Recursive Function: " << recursiveConversion(binary) << endl;
}

int iterativeConversion(string binary) {
    int sum = 0;
    int ndx = 0;

    for (int i = 0; i < binary.length(); i++) {
        int num = stoi(binary.substr(ndx, 1)); // Converting a digit to int.
        sum += num; // Adding the converted digit to the sum.
        sum *= 2;
        ndx++;
    }
    return sum/2;
}

int recursiveConversion(string binary) {
    static int sum = 0;
    static int ndx = binary.length();
    int num;

    if (ndx > 0) {
        ndx--;
        num = stoi(binary.substr(binary.length() - ndx - 1, 1));
        sum += num;
        sum *= 2;
        recursiveConversion(binary);
    }
    return sum/2;
}