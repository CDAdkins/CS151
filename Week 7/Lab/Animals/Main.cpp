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

        Questions:
            1. The base class is called Animal.
            2. The derived classes are Bird and Dog.
            3. No, Animal does not have a parent class.
            4. showInfo() is overwritten, makeNoise() isoverwritten, sleep() is not.
            5. 
                a. If the name variable were made protected then it could be freely accessed
                   by the child classes. No need for getters and setters. 
               
                b. If the Animal class's access modifier were instead changed, it would
                   not make the name variable accessible to the child classes.

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