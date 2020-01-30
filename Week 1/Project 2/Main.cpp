#include "Country.h"
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

vector<Country> countryVector; // Global vector

void addCountry(Country country) {
    bool added = false; // If the country in question was added to the vector.
    if (countryVector.size() == 0) {
        countryVector.insert(countryVector.begin(), country);
        cout << "Added " << countryVector[0].getName() << " to empty vector.\n";
    } else {
        for (int i = 0; i < countryVector.size(); i++) {
            if (countryVector[i].getArea() > country.getArea()) {
                countryVector.insert(countryVector.begin() + i, country);
                cout << "Inserted " << country.getName() << " before " << countryVector[i + 1].getName() << endl;
                added = true;
                break;
            }
        }
        if (added == false) {
            countryVector.push_back(country);
            cout << "Added " << country.getName() << " to end of vector.\n";
        } else {
            added = false;
        }
    }
}

void printVector() { // Prints the vector in a formatted list.
    cout << "\n\n\n Country\t Population\t   Area\n";
    cout << "---------\t------------\t----------\n";

    for (int i = 0; i < countryVector.size(); i++) {
        Country country = countryVector[i];

        cout << country.getName() << "    \t"; // The spaces before the tab allow the populations to line up properly.

        if (country.getPopulation() < 1000) { // These if statements check the number of digits in population and area.
            cout << "     " << country.getPopulation(); // The number of spaces changes in order to align the ints to the right.
            if (country.getArea() < 100000) {
                cout << "\t   " << country.getArea() << endl;
            } else if (country.getArea() < 1000000) {
                cout << "\t  " << country.getArea() << endl;
            } else {
                cout << "\t " << country.getArea() << endl;
            }
        } else if(country.getPopulation() < 10000) {
            cout << "    " << country.getPopulation();
            if (country.getArea() < 100000) {
                cout << "\t   " << country.getArea() << endl;
            } else if (country.getArea() < 1000000) {
                cout << "\t  " << country.getArea() << endl;
            } else {
                cout << "\t " << country.getArea() << endl;
            }
        } else if (country.getPopulation() < 100000) {
            cout << "   " << country.getPopulation();
            if (country.getArea() < 100000) {
                cout << "\t   " << country.getArea() << endl;
            } else if (country.getArea() < 1000000) {
                cout << "\t  " << country.getArea() << endl;
            } else {
                cout << "\t " << country.getArea() << endl;
            }
        } else {
            cout << "  " << country.getPopulation();
            if (country.getArea() < 100000) {
                cout << "\t   " << country.getArea() << endl;
            } else if (country.getArea() < 1000000) {
                cout << "\t  " << country.getArea() << endl;
            } else {
                cout << "\t " << country.getArea() << endl;
            }
        }
    }
}

int main() {
    Country argentina("Argentina", 43132, 1074000);
    addCountry(argentina); // Do this for all of them
    Country bolivia("Bolivia", 10520, 424200);
    addCountry(bolivia);
    Country brazil("Brazil", 204519, 3286000);
    addCountry(brazil);
    Country chile("Chile", 18006, 292260);
    addCountry(chile);
    Country columbia("Columbia", 48529, 448800);
    addCountry(columbia);
    Country ecuador("Ecuador", 16279, 109843);
    addCountry(ecuador);
    Country guyana("Guyana", 747, 83000);
    addCountry(guyana);
    Country paraguay("Paraguay", 7003, 157048);
    addCountry(paraguay);
    Country peru("Peru", 31153, 496200);
    addCountry(peru);
    Country suriname("Suriname", 560, 63252);
    addCountry(suriname);
    Country uruguay("Uruguay", 3310, 68037);
    addCountry(uruguay);
    Country venezuela("Venezuela", 30620, 353831);
    addCountry(venezuela);

    printVector();
}