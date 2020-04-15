/*  wordCounter.cpp
    Author: Chris Adkins
    Module: 8
    Project: Homework 1
    Problem Statement: This program takes a c-string and returns the number of words it contains.


    Algorithm:
        1. Create a c-string and initialize it with a sentence from the user.
        2. Create a function for counting the number of words.
            a. initialize a new int variable to one. This will be our word counter.
            b. Loop through every character in the string.
            c. If the current character is space, increment the word count by one.
        3. Print the number of words back to the user.

    Classes Needed:
        <iostream> - For printing to the user.
        <cstring> - For strlen().
*/

#include <iostream>
#include <cstring>

using namespace std;

void wordCounter(char myString[]);

int main() {
    const int SIZE = 100; // Maximum number of characters the array can hold.
    char myString[SIZE]; // Our char array.
    cout << "Enter a sentence: ";
    cin.getline(myString, SIZE); // Getting input from the user and assigning it to myString.
    wordCounter(myString); // Calling wordCounter with the user's string as an argument.
}

void wordCounter(char myString[]) {
    int numWords = 1; // Word counter starts at one.
    for (int i = 0; i < strlen(myString); i++) { // Looping through every character in array.
        if (myString[i] == ' ') { // If we find a ' ' char.
            numWords++; // Increment the word counter by one.
        }
    }
    cout << "This string has " << numWords << " words in it.\n"; // Print the result to the user.
}