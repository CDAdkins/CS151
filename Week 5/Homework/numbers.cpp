/*  numbers.cpp
    Author: Chris Adkins
    Module: 5
    Project: Homework 1
    Problem Statement: This program takes an int entered by the user and converts it into english text.
    5, 18, 295, 1019, and 9999


    Algorithm:
        1. Create arrays to hold the name for numbers under 20, then under 100.
        2. Create strings to hold 'hundred', and 'number'.
        3. Get the number from the user using cin.
        4. Create a method to find the number of digits in the number.
        5. Depending on the length of the number, use our arrays to match the digits with their corresponding name.
        6. Stitch the digit names together and output the end result to the user.

    Classes Needed:
        <iostream> - For printing to the user and receiving input.
*/

#include <iostream>

using namespace std;

// Array full of strings representing all numbers under 20.
string underTwenty[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
                        "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen",
                        "eighteen", "nineteen"};

// Array of strings representing the tens place of numbers.
string underOneHundred[] = {"twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"};

string hundred = "hundred";
string thousand = "thousand";
int number; // Number entered by the user.

int getNumber() {
    int num;
    cout << "Enter the number: ";
    cin >> num;
    return num;
}

void convertToText(int digits, int num) {
    switch (digits) {
        case 4: 
        cout << underTwenty[(num / 1000) - 1] << " " << thousand << " "; // Print the first digit in the number.
        num %= 1000;
        case 3: 
        if (num / 100 > 0) { // If the number in the hundreds place is not 0.
            cout << underTwenty[(num / 100) - 1] << " " << hundred << " ";
        }

        num %= 100;
        case 2: 
        if (num / 10 > 0) { // If the number in the tens place is not 0.
            if (num >= 20) {
                cout << underOneHundred[(num/10) - 2] << " ";
                num %= 10;
            }
        }
        
        case 1: cout << underTwenty[num - 1];
    }
}

void getNumDigits(int num) { // This function gets the number of digits in the number
    if (num < 20) {
        convertToText(1, num); // It then calls convertToText() with the proper arguments.
    } else if (num < 100) {
        convertToText(2, num);
    } else if (num < 1000) {
        convertToText(3, num);
    } else {
        convertToText(4, num);
    }
}

int main() {
    getNumDigits(getNumber()); // Calling our functions to get the number from the user, then converting it.
}