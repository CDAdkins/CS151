/*  initBinary.cpp
    Author: Chris Adkins
    Module: Week 9
    Project: Lab 1
    Problem Statement: This program write a series of ints and doubles to abinary file.

    Classes Needed:
        <iostream> - For printing to the user.
        <fstream>  - For opening file input / output streams.
        <math.h>   - For the sqrt() function.
*/

#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int main() {
    const string fileName = "data.dat";
    fstream dataFile(fileName, ios::out | ios::binary); // File stream set up for output to a binary file.

    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    if (!dataFile) { // If there is a problem opening / creating the file.
        cout << "Error opening file: " << fileName;
        exit(1);
    }

    for (int i = 0; i < 10; i++) { // Writing to the dat file.
        dataFile.write(reinterpret_cast<char *>(&nums[i]), sizeof(int));
    }

    for (int i = 0; i < 10; i++) { // Writing to the dat file.
        double num = sqrt(nums[i]);
        dataFile.write(reinterpret_cast<char *>(&num), sizeof(double));
    }

    dataFile.close(); // Closing the output stream to the file.
    dataFile.open(fileName, ios::binary | ios::in); // Opening the file as an input stream.
    cout << "Reading the first 10 values from the file:\n";

    // I read from the file so I can verify the writes without using a hex editor.
    for (int i = 0; i < 10; i++) {
        int data;
        dataFile.read(reinterpret_cast<char *>(&data), sizeof(int));
        cout << data << endl;
    }

    cout << "\nReading the last 10 values from the file:\n";
    for (int i = 0; i < 10; i++) {
        double data;
        dataFile.read(reinterpret_cast<char *>(&data), sizeof(double));
        cout << data << endl;
    }
}