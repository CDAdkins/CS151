/*  Dog.h
    Author: Chris Adkins
    Module: 7
    Project: Lab 2
    File Description: This is the header file from our dog class.
    
*/

#pragma once
#include "Animal.h"
#include <iostream>

using namespace std;

class Dog: public Animal {
    private:
        string breed;
    public:
        Dog(string, string);
        void makeNoise();
        void showInfo();
        string getBreed();
        void setBreed(string);
};