/*  squareRoot.cpp
    Author: Chris Adkins
    Module: Lab 13
    Project: 2
    Problem Statement: This program demonstrates the use of exceptions regarding perfect squares.

    Algorithm:
        1. Create an empty class called ImperfectSquareException.
        2. Create a function called getSquareRoot with an int as an argument.
            a. Check to see if the argument's square root is a whole number.
            b. If it is not, throw an ImperfectSquareException, if it is, return the square root.
        3. Create a try-catch block in main.
        4. Call the getSquareRoot function in the try block.
        5. The catch block should then catch an ImperfectSquareException and print an error to the user.

    Classes Needed:
        <iostream> - For printing to the user.
        <math.h>   - For the sqrt() function.
*/

#include <iostream>
#include <math.h>
using namespace std;

class ImperfectSquareException {}; // Exception class.

int getSquareRoot(int num); // Function Prototype

int main() {
    for (int i = 0; i <= 25; i++) {
        try {
            cout << i << ": " << getSquareRoot(i) << endl;
        } catch (ImperfectSquareException e) {
            cout << "Not a perfect square." << endl;
        }
    }
}

int getSquareRoot(int num) {
    double root = sqrt(double(num)); // Casting the int to a double to avoid integer division.
    if (root != int(root)) { // If the root is not the same when cast as an int, it is not a perfect square.
        throw ImperfectSquareException(); // Throw the exception.
    }
    return root; // If the number is a perfect square then return the square root.
}