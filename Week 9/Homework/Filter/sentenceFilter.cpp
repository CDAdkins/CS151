/*  sentenceFilter.cpp
    Author: Chris Adkins
    Module: 9
    Project: 1
    Problem Statement: This program reads a text file, properly changes uppercase and lowercase, then outputs to a new file.

    Algorithm:
        1. Create two strings for the two file names.
        2. Ask the user what they'd like the file names to be.
        3. Create two fstreams, one in and one out, with the file names from the user.
        4. create a char as a reference to the input file's get() function return value;
        5. If the char is a period, print the period and the following space. 
        6. Print the next char with the toupper function to the new file.
        7. If the char is not a period, simply print it with tolower() to the new file.
        8. Repeat steps 5 through 7 until your char is equal to EOF.

    Classes Needed:
        <iostream> - For printing to the user.
        <fstream>  - For file input and output.
*/

#include <fstream>
#include <iostream>

using namespace std;

int main() {
    string inFileName;
    string outFileName;

    cout << "Enter the file name for the input file: ";
    cin >> inFileName;
    cout << "Enter the file name for the output file: ";
    cin >> outFileName;

    ifstream inFile(inFileName, ios::in);
    ofstream outFile(outFileName, ios::out);

    char ch = inFile.get();
    ch = toupper(ch);
    outFile << ch;
    ch = inFile.get();
    while(ch != EOF) {
        if (ch == '.' && inFile.peek() != EOF) { // If our character is a period.
            outFile << ch; // Print the character.
            ch = inFile.get(); // Move to the next character, which should be a space.
            outFile << ch; // Print the space.
            ch = inFile.get(); // Move to the next character, which should be the beginning of our sentence.
            ch = toupper(ch);
            outFile << ch; // Print the character in uppercase.
            ch = inFile.get();
        } else { // If the character is not a period.
            ch = tolower(ch);
            outFile << ch; // Print the character in lowercase.
            ch = inFile.get();
        }
    }
    inFile.close();
    outFile.close();
}