/*  Test.cpp
    Author: Chris Adkins
    Module: 1
    Project: Testing
    Problem Statement: This code doesn't really do anything.

    Algorithm:
        1. Display "Hello World!" to the console.
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int num = 25;
    int* pointer = &num;

    cout << pointer;
}