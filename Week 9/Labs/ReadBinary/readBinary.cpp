/*  readBinary.cpp
    Author: Chris Adkins
    Module: Week 9
    Project: Lab 2
    Problem Statement: This program reads ints and doubles from a binary file, multiplies the values, and replaces them.

    Classes Needed:
        <iostream> - For printing to the user.
        <fstream>  - For opening file input / output streams.
        <math.h>   - For the round() function.
*/

#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int main() {
    const string fileName("data.dat");
    double multiplier;

    fstream dataFile(fileName, ios::binary | ios::in | ios::out);

    if (!dataFile) {
        cout << "Could not open file: " << fileName << endl;
    }

    cout << "Enter a multiplier: ";
    cin >> multiplier;

    cout << "Multiplying the 10 ints in the file by " << multiplier << "...\n";
    for (int i = 0; i < 10; i++) { // Looping through the first 10 elements in the file.
        int data;
        long position = dataFile.tellg();
        dataFile.read(reinterpret_cast <char *>(&data), sizeof(int));
        cout << data << " -> ";
        data = round(data * multiplier);
        cout << data << endl;
        dataFile.seekp(position, ios::beg); // Writing the updated number.
        dataFile.write(reinterpret_cast <char *>(&data), sizeof(int));
    }

    cout << "\nMultiplying the 10 doubles in the file by " << multiplier << "...\n";
    for (int i = 0; i < 10; i++) { // Looping through the next 10 elements in the file.
        double data;
        long position = dataFile.tellg();
        dataFile.read(reinterpret_cast <char *>(&data), sizeof(double));
        cout << data << " -> ";
        data = data * multiplier;
        cout << data << endl;
        dataFile.seekp(position, ios::beg); // Writing the updated number.
        dataFile.write(reinterpret_cast <char *>(&data), sizeof(double));
    }
}