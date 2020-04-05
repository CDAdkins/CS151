/*  Bird.h
    Author: Chris Adkins
    Module: 7
    Project: Lab 2
    File Description: This is the header file from our Bird class.
    
*/

#pragma once
#include "Animal.h"
#include <iostream>

using namespace std;

class Bird : public Animal {
    public:
        Bird(string);
        void makeNoise();
        void showInfo();
};