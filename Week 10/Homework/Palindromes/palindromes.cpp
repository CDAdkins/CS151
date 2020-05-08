/*  palindromes.cpp
    Author: Chris Adkins
    Module: 11
    Project: 3
    Problem Statement: This program recursively tests strings and tells the user if it is a palindrome.

    Algorithm:
        1. Create a function called isPalindrome.
            a. Check to see if the first index is greater than or equal to the second index.
            b. If it is, return 1, the string is a palindrome.
            c. If it is not, do nothing.
            d. Check to see if the character at the current index is equal to the character at the second index.
            e. If it is, do nothing, if it isn't return false as the string is not a palindrome.
            f. Call the isPalindrome function recursively with the int values incremented (prescript)

    Classes Needed:
        <iostream> - For printing to the user.
*/

#include <iostream>
using namespace std;

bool isPalindrome(string, int, int);

int main() {
    int count; // The number of words we will be checking.
    string str; // The string we are currently testing for palindromes.
    cout << "How many words would you like to test? ";
    cin >> count; // Initializing count with the user's input.
    for (int i = 0; i < count; i++) {
        cout << "\nEnter a word: ";
        cin >> str; // Initializing str with the user's input.
        isPalindrome(str, 0, str.length()-1) == 1 ? cout << str << " is a palindrome!\n" : cout << str << " is not a palindrome!\n";
    }
}

bool isPalindrome(string str, int lower, int upper) {
    if (lower >= upper) // If we have checked all of the characters.
        return 1; // We have a palindrome.
    if (toupper(str[lower]) != toupper(str[upper])) // If our lower character doesn't match our upper character.
        return 0; // We do not have a palindrome.
    return isPalindrome(str, ++lower, --upper); // Call the function again with updated values.
}