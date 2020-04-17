/*  palindromes.cpp
    Author: Chris Adkins
    Module: Week 8
    Project: Lab 1
    Problem Statement: This program takes a string and tells the user whether or not it is a palindrome.

    Algorithm:
        1. Create a function called isPalindrome().
            a. Create strings to hold the original string, an alphanumeric only string, and a string in reverse.
            b. Use the tolower function to convert the string argument to lowercase.
            c. Loop through the lowercase string and use isalnum to populate the alnumString with only the alnum characters.
            d. Use the string::swap() function to reverse the string.
            e. Use the string::compare() function to check the alnumString against the reversed string.
            f. If the compare function returns 0, you have a palindrome, if it doesn't, you don't.
        2. Call the isPalindrome() function with the string you'd like to check as an argument.

    Classes Needed:
        <iostream>  - For printing to the user.
        <algorithm> - For the for_each function.
*/

#include <iostream>
#include <algorithm>

using namespace std;

bool isPalindrome(string);

int main() {
    // Function calls for demonstrative purposes.
    isPalindrome("Chic");
    isPalindrome("Book");
    isPalindrome("Kayak");
    isPalindrome("Don't nod.");
    isPalindrome("12345");
    isPalindrome("25 ABC 9cba52");
    isPalindrome("Not even close.");
    isPalindrome("Campus motto: Bottoms up, Mac!");
    isPalindrome("A man, a plan, a canal -- Panama");
}

bool isPalindrome(string aString) {
    string original = aString; // A string to hold all of the punctuation for returning to the user.
    string alnumString; // String to hold all alphanumeric characters.
    string reverse; // String to be reversed to check for palindrome.

    for_each(aString.begin(), aString.end(), [](char &c) {c = tolower(c);}); // Converting the string to lowercase.

    for (int i = 0; i < aString.length(); i++) { // Iterate over every character.
        if (isalnum(aString[i])) { // If the char is alphanumeric.
            alnumString.append(1, aString[i]); // Add the character to the alnumString.
        }
    }
    reverse.assign(alnumString); // Assigning the contents of alnumString to reverse.

    for (int i = 0; i < reverse.length() / 2; i++) { // Looping once for every two characters.
        swap(reverse[i], reverse[reverse.length() - i - 1]); // Reversing the string.
    }
    if(reverse.compare(alnumString) == 0) { // If the two string are the same forward and reverse.
        cout << original << " is a palindrome!\n"; // Tell the user it is a palindrome.
        return true; // Make the function return true;
    } else {
        cout << original << " is not a palindrome.\n"; // Tell the user it is not a palindrome.
        return false; // Make the function return false.
    }
}