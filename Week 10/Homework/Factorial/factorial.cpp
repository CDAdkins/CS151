/*  factorial.cpp
    Author: Chris Adkins
    Module: 11
    Project: Lab 1
    Problem Statement: This program calculates the factorial of a number given by the user.

    Algorithm:
        1. Get an int from the user and pass it into the factorial function.
        2. If the given number is less than 2, return the number.
        3. Create an int called total.
        4. Set total equal to total += (num * (num - 1)).
        5. Loop as many times as the value of the number.
        6. Set the total equal to total *= (num - i - 1).
        7. return the total.

    Classes Needed:
        <iostream> - For printing to the user.
*/

#include <iostream>

using namespace std;

int factorial(int);

int main() {
    int num = 0;
    cout << "Enter a number: ";
    cin >> num;
    cout << num << "! = " << factorial(num) << endl;
}

int factorial(int num) {
    int total = 0; // Int to keep track of the total.
    if (num < 2) {
        return num; // Factorial of 0 or 1 is itself.
    }
    total += (num * (num - 1)); // Initial math calls for multiplying the number by itself minus one.
    for (int i = 1; i < num - 1; i++) { // Looping according to the number.
        total *= (num - i - 1); // Multiply the total by itself, as well as the next number in line.
    }
    return total;
}