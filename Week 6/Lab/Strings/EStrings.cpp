/* EStrings.cpp - Enhance the String class using overloaded functions (original)
 * Author:    Chris Merrill
 * Module:    6
 * Project:   Lab 1
 * Problem statement:  Enhance the String class from Module 5, Lab 2 using
 *    overloaded functions to assignment, addition, extraction, and upper-case operators
 *
 * Discussion:
 *    - Starting point for Lab 6 (from Lab 5)
 */

#include<iostream>
#include<cstring>
using namespace std;

class EString {

    private:
        char *string;                               // pointer to an array of chars
        int size;                                  // size of the array

    public:
        EString(const char *s = "") ;           // constructor
        ~EString() ;                           // destructor
        EString(const EString &) ;            // copy constructor
        EString &operator=(const EString &); // Assingment Operator
        friend ostream &operator<<(ostream &, const EString &);
        EString &operator++();             // Prefix ++ Operator
        EString operator++(int);          // Postfix Operator
        int operator[](int);
        friend EString operator+(const EString &, const EString &);
        void explode();
};

// Constructor
EString::EString(const char *original) {
    size = strlen(original) ;
    string = new char[size + 1] ;
    strcpy(string, original) ;
}

// Destructor
EString::~EString() {
    delete [] string ;
}

// Copy constructor which creates a new String
EString::EString(const EString &original) {
    size = original.size;
    string = new char[size + 1];
    strcpy(string, original.string);
}

// Assignment Operator
EString & EString::operator=(const EString &original) {
    delete [] string;
    size = original.size;
    string = new char[size + 1];
    strcpy(string, original.string);
    return *this;
}

// Stream extraction operator
ostream & operator<<(ostream &out, const EString &output_EString) {
    out << output_EString.string;
    return out;
}

EString & EString::operator++() {  // Prefix increment operator.
    for (int i = 0; i < size; i++) { // Iterate through the string.
        string[i] = toupper(string[i]); // Convert the chars to uppercase.
    }
return *this;
}

EString EString::operator++(int) {  // Postfix increment operator.
    EString copy = *this; // Creating a new EString object based on *this.
    for (int i = 0; i < copy.size; i++) { // Iterate through the string.
        copy.string[i] = toupper(copy.string[i]); // Convert the chars to uppercase.
    }
    return copy;
}

int EString::operator[](int index) { // Overloading the [] subscript operator.
    if (index < 0 || index > size) { // If the index is less than 0, or greater than the length of the string.
        cout << "index out of bounds error. Exiting program...";
        exit(0); // Exit the program.
    } else {
        char **address = &string; // Getting the memory address of the beginning of or char array.
        cout << address + index;
        return 1;
    }
    return 0; // Don't think I need this but VSCode throws a warning if I don't.
}

EString operator+(const EString &estring1, const EString &estring2) { // Overloading the + operator.
    char newChars[estring1.size + estring2.size + 1]; // Creating a new char array. with 
    strcpy(newChars, estring1.string); // Using strcpy to place estring1 into the 
    strcat(newChars, " "); // Adding a space character to the char array.
    strcat(newChars, estring2.string); // Adding estring2 to the char array.
    EString newString(newChars); // Creating a new EString based on the char array.
    return newString; // Returning the new Estring.
}

void EString::explode() { // Function to print the string with a space between every character.
    for (int i = 0; i < size; i++) { // For every character in the string.
        cout << string[i] << " "; // Print the current character and a space character.
    }
    cout << "\n\t\t\t";
    for (int i = 0; i < size; i++) {
        cout << char(string[i] + 1) << " "; // Print the value of each character plus one.
    }
}

int main() {
    EString estring1("Hello Miracosta!"), estring2; // Creating two EString objects.
    EString estring3("New Year's Party at 8:30.");
    EString estring4("Have a good time!");
    estring2 = estring1; // Using the overloaded = assignment operator.
    ++estring1; // Converting estring1 to uppercase.

    // Demonstrating our functions to the user.
    cout << "Original String:\t" << estring3 << endl;
    cout << "Using postfix operator:\t" << estring3++ << endl;
    cout << "After using postfix:\t" << estring3 << endl;
    cout << "estring3:\t\t" << estring3 << "\nestring4:\t\t" << estring4 << endl;

    EString estring5 = estring3 + estring4;
    cout << "estring3 + estring4:\t" << estring5 << endl;
    cout << "estring4.explode():\t";
    estring4.explode();
}
