#include "Country.h"
#include <string>

using namespace std;

Country::Country(string name, int population, int area) {
    this->name = name;
    this->population = population;
    this->area=area;
}

string Country::getName() {
    return name;
}

int Country::getPopulation() {
    return population;
}

int Country::getArea() {
    return area;
}