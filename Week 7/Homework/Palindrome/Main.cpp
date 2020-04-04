/*  Main.cpp
    Author: Chris Adkins
    Module: 7
    Project: Homework 1
    Problem Statement: This program takes a string and evaluates whether or not it is a palindrome.


    Algorithm:
        1. Create a class called PString that is derived from the string class.
        2. Create a constructor that calls the constructor for the base string class.
        3. Create a function that checks if the string is a palindrome.
            a. Remove any non-alphanumeric characters from the string with isalnum().
            b. check the first character in the string against the last character.
            c. If the characters are not identical, return false.
            d. If the characters are identical, check the second char against the second to last char.
            e. Keep moving the index points until you reach the end of the word.

    Classes Needed:
        <iostream> - For printing to the user.
        <string> - For string functions.
*/

#include <iostream>
#include "PString.h"
#include <string>

using namespace std;

int main() {
    string userInput;
    

    // Test Cases.
    PString test1("Chic");
    PString test2("Book");
    PString test3("Kayak");
    PString test4("25 ABC 9cba52");
    PString test5("Don't nod");
    PString test6("Not even close!");
    PString test7("A man, a plan, a canal -- Panama");

    test1.isPalindrome();
    test2.isPalindrome();
    test3.isPalindrome();
    test4.isPalindrome();
    test5.isPalindrome();
    test6.isPalindrome();
    test7.isPalindrome();

    cout<<"\n\n-----------------------------------------\n| ";
    cout << "Welcome to the Palindrome Checker 3000|\n";
    cout << "-----------------------------------------\n\nEnter your word or phrase: ";
    getline(cin, userInput); // Getting input from the user.
    PString input(userInput); // Creating a PString from the string given by the user.
    input.isPalindrome(); // Checking the user's input for a palindrome.
}