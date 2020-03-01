/*  copy.cpp
    Author: Chris Adkins
    Module: 5
    Project: Lab 2
    Problem Statement: This program creates a class that mimics the functionality of strings.


    Algorithm:
        1. Create and define a string class.
        2. Create two private variables, an int for size and a char* called string.
        3. Create prototypes for the constructors as well as the print and change functions.
        4. Outside the string class, create the functions we created prototypes for.
        5. Use main to demonstrate the functions of the string class.

    Classes Needed:
        <iostream> - For printing to the user.
        <cstring> - For strcpy, strlen
*/

#include <cstring>
#include <iostream>

using namespace std;

class String {
    private:
    char *string;
    int size;

    // Prototypes.
    public:
    String(const String &);
    ~String();
    String(const char *s = "");
    void change(const char *);
    void print();    
};

String::String(const String &original) { // Copy Constructor
    size = original.size;
    string = new char[size + 1];
    strcpy(string, original.string);
}

String::~String() { // Destructor
    delete[] string;
}

String::String(const char *original) { // Constructor
    size = strlen(original);
    string = new char[size + 1];
    strcpy(string, original);
}

void String::change(const char *original) { // Change function
    delete[] string;
    size = strlen(original);
    string = new char[size + 1];
    strcpy(string, original);
}

void String::print() { // Print function
    cout << string << endl;
}

int main() {
    String str1("MiraCosta College");
    String str2 = str1;

    cout << "\nstr1(MiraCosta College), str2 = str1:\n";
    str1.print();
    str2.print();

    str2.change("Cal State San Marcos");
    cout << "\nAfter calling str2.change()\n";
    str1.print();
    str2.print();
    
    str1.change("UCSD");
    cout << "\nAfter calling str1.change()\n";
    str1.print();
    str2.print();
}