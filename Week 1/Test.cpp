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
    int array1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int array2[10];
    vector<int> vec1(10, 100);
    vector<int> vec2(vec1);
    cout << vec1[4] << "\n" << vec2[4] << endl;

    for (int i = 0; i < 10; i++) {
        array2[i] = array1[i];
    }

    for (int i = 0; i < 10; i++) {
        cout << array2[i] << ", ";
    }
}
