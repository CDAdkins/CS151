/*  driver.cpp
    Author: Chris Adkins
    Module: 14
    Project: Lab 1
    Problem Statement: This is a driver program to demonstrate the functions I have added to the provided LinkedList class.

    Algorithm:
        1. Add the display function.
            a. Create a Node pointer to walk the list with.
            b. For each element in the list, cout the index and the node's data.
        2. Add the remove function.
            a. Create a Node pointer to walk the list with.
            b. Create a Node pointer called prev to represent the previous element.
            c. For each element in the list check to see if the current Node's data matches the argument.
            d. If it does, set prev->next = current->next.
            e. If it doesn't set prev = prev->next and current = current->next and repeat.
        3. Add the removeAt function.
            a. The steps are the same as the remove function except.
            b. Instead of checking the Node's data, check its index.
            c. React the same way you did when removing an element with remove.
        4. Add a function to find the last occurence of a data element.
            a. Create a Node pointer and set it to point at the head of the list.
            b. Use a for loop to walk over the entire list.
            c. If a Node's data matches the data you're looking for, save the index to an int called last.
            d. If you see the same data, overwrite last with the new index.
            e. return last once loop finishes.
        5. Add function to see if a data element exists in thelist.
            a. Do the same thing as finding the last occurence except once you find it the first time, return true.
        6. Create a function to change the value of an element given the index.
            a. Create a Node pointer called current, set it to the head of the list.
            b. Create a for loop to walk throught the list until you reach the given index.
            c. Modify the element with current->data = myData.
            d. return true.

    Classes Needed:
        <iostream> - For printing to the user.
*/


#include "LinkedList.h"
#include <iostream>
using namespace std;

int main() {
    LinkedList<string> myList;

    myList.addLast("first");
    myList.addLast("second");
    myList.addLast("third");
    myList.addLast("fourth");
    myList.addLast("fifth");
    
    cout << "Prior to any functions being called:";
    myList.display();
    
    myList.remove("third");
    cout << "\nAfter calling myList.remove(\"third\"):";
    myList.display();

    myList.removeAt(0);
    cout << "\nAfter calling myList.removeAt(0):";
    myList.display();

    myList.set(0, "fifth");
    cout << "\nAfter calling myList.set(0, \'fifth\"):";
    myList.display();

    cout << "\nCalling myList.lastIndexOf(\"fifth\") returns: ";
    cout << myList.lastIndexOf("fifth");

    cout << "\n\nCalling myList.contains(\"fourth\") returns: ";
    cout << myList.contains("fourth");
    cout << endl;
}