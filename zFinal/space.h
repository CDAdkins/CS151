#pragma once
#include <string>
#include "player.h"
using namespace std;

class Space { // Abstract Base Class
    protected:
        string name;
        int position;

    public:
        string getName();
        int getPosition();
};