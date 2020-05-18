/*  setDriver.cpp
    Author: Chris Adkins
    Module: 15
    Project: Lab 1
    Problem Statement: This is a driver program to demonstrate the equals and minus functions I've implemented.

    Algorithm:
        1. Create the equals function.
            a. Walk through the calling set, for each node compare it to the other_set.
            b. If any nodes do not match, return false.
            c. If all of the nodes match, iterate over the other_set and compare it to the calling set.
            d. If the nodes still match return true, otherwise return false.
        2. Create the minus function.
            a. Iterate over the called set's data.
            b. Use the contains function to check if the other_set has the same data.
            c. If the other_set does not have that data, add it to a new set. If it does, do nothing.
            d. Repeat until you've reached the end of the calling set.
            e. Return the newly created set.

    Classes Needed:
        <iostream> - For printing to the user.
        "SetLinkedList.h" - For access to the SetLinkedList class.
*/

#include <iostream>
#include "SetLinkedList.h"
using namespace std;

int main() {
    // Demonstration of the equals and minus functions.
    // Creating our initial sets.
    Set<string> setA;
    Set<string> setB;
    Set<string> setC;
    Set<string> setD;
    Set<int> setE;
    Set<int> setF;
    Set<int> setG;
    Set<int> setH;

    // Populating our sets.
    setA.insert("C");
    setA.insert("G");
    setA.insert("E");
    setA.insert("A");
    setB.insert("E");
    setB.insert("C");
    setB.insert("F");

    setC.insert("Carlos");
    setC.insert("John");
    setC.insert("Alice");
    setD.insert("John");
    setD.insert("Henry");
    setD.insert("Maria");

    setE.insert(5);
    setE.insert(1);
    setE.insert(3);
    setF.insert(1);
    setF.insert(3);
    setF.insert(5);
    setF.insert(7);
    setF.insert(9);

    setG.insert(5);

    // Gratuitous Instantiation Incoming.

    // Demonstration of minus and equal functions.
    setA.display();
    setB.display();
    Set<string> setABMinus(setA.minus(setB));
    setABMinus.display();
    Set<string> setABIntersect(setA.setIntersect(setB));
    setABIntersect.display();
    Set<string> setABMinusUnionIntersect(setABMinus.setUnion(setABIntersect));
    setABMinusUnionIntersect.display();
    setA.equals(setABMinusUnionIntersect) ? cout << "The sets are equal!\n" : cout << "The sets are not equal.\n";

    cout << "\n";

    setC.display();
    setD.display();
    Set<string> setCDMinus(setC.minus(setD));
    setCDMinus.display();
    Set<string> setCDIntersect(setC.setIntersect(setD));
    setCDIntersect.display();
    Set<string> setCDMinusUnionIntersect(setCDMinus.setUnion(setCDIntersect));
    setCDMinusUnionIntersect.display();
    setC.equals(setCDMinusUnionIntersect) ? cout << "The sets are equal!\n" : cout << "The sets are not equal.\n";

    cout << "\n";

    setE.display();
    setF.display();
    Set<int> setEFMinus(setE.minus(setF));
    setEFMinus.display();
    Set<int> setEFIntersect(setE.setIntersect(setF));
    setEFIntersect.display();
    Set<int> setEFMinusUnionIntersect(setEFMinus.setUnion(setEFIntersect));
    setEFMinusUnionIntersect.display();
    setE.equals(setEFMinusUnionIntersect) ? cout << "The sets are equal!\n" : cout << "The sets are not equal.\n";

    cout << "\n";

    setG.display();
    setH.display();
    Set<int> setGHMinus(setG.minus(setH));
    setGHMinus.display();
    Set<int> setGHIntersect(setG.setIntersect(setH));
    setGHIntersect.display();
    Set<int> setGHMinusUnionIntersect(setGHMinus.setUnion(setGHIntersect));
    setGHMinusUnionIntersect.display();
    setG.equals(setGHMinusUnionIntersect) ? cout << "The sets are equal!\n" : cout << "The sets are not equal.\n";
}