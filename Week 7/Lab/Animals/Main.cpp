/*  Main.cpp
    Author: Chris Adkins
    Module: 7
    Project: Lab 2
    Problem Statement: This program creates a base animal class, as well as derivitives to demonstrate is-a relationships.


    Algorithm:
        1. Create an Animal class with a constructor for the name of the animal.
        2. Create a Bird class that derives from the Animal class.
        3. Create a dog class that also derives from the Animal class.
        4. Give all of the classes constructors that initialize with member initialization lists.
        5. Override the animal class's functions in the derivitive classes.
        6. Display the various animals and their respective functions to the user.

    Classes Needed:
        <iostream> - For printing to the user.
        "Animal.h" - For the base class.
        "Dog.h" - For the derivitive class.
        "Bird.h" - For the other derivitive class.
*/

#include "Animal.h"
#include "Dog.h"
#include "Bird.h"
#include <iostream>

using namespace std;

int main() {
    // Creating the animals.
    Animal *oscar = new Animal("Oscar");
    Dog *inka = new Dog("Inka", "Mutt");
    Bird *tweety = new Bird("Tweety");
    cout << "\n";

    // Showing the names of the animals.
    oscar->showInfo();
    inka->showInfo();
    tweety->showInfo();
    cout << "\n";

    // The animals' makeNoise() functions.
    oscar->makeNoise();
    inka->makeNoise();
    tweety->makeNoise();
    cout << "\n";

    // The animals' sleep functions.
    oscar->sleep();
    inka->sleep();
    tweety->sleep();
}