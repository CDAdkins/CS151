#pragma once

#include <string>

using namespace std;

class Country {
private:
    string name;
    int population;
    int area;

public:
    Country(string name, int population, int area);
    string getName();
    int getPopulation();
    int getArea();
};