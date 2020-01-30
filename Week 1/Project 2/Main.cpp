/*  Main.cpp
    Author: Chris Adkins
    Module: 1
    Project: 2
    Problem Statement: 
    This program creates a vector full of country classes and places them into a vector
    in ascending order by area. It then prints a nicely formatted list to the user.

    Algorithm:
        1. Create a Country class with a string for name and an int for area and population.
        2. Create a global vector to hold our countries.
        3. Create a method to add a country to the vector in ascending order by area.
            A. We will do this with a for loop used to compare our country's area to the countries already in the vector.
            B. If the country has a larger area than us, insert our country before the aforementioned country in the vector.
        4. Create every country necessary and call the addCountry() function detailed above, call the method once per country created.
        5. Create a method to print the contents of our vector into a formatted list.
            A. Use too many if-else statements to check the length of the ints so we can print them right-aligned.
            B. EX: if population < 100000 only print " " rather than "    " if the population is < 1000
            C. This must be done both for the population as well as the area.
        6. Call our printVector() method which will print the results to the user.

    Classes Needed:
        <iostream> - For printing to the user
*/

#include "Country.h"
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

vector<Country> countryVector; // Global vector

void addCountry(Country country) {
    bool added = false; // If the country in question was added to the vector. Resets to false every time the method is run.
    if (countryVector.size() == 0) { // If the vector is empty.
        countryVector.insert(countryVector.begin(), country); // Place the country at the start of the vector.
        cout << "Added " << countryVector[0].getName() << " to empty vector.\n"; // Output to show what's going on.
    } else {
        for (int i = 0; i < countryVector.size(); i++) { // Iterate through the entire vector.
            if (countryVector[i].getArea() > country.getArea()) { // If our country is smaller than the country at [i].
                countryVector.insert(countryVector.begin() + i, country); // Take the place of the country at [i] and push it down one spot.
                cout << "Inserted " << country.getName() << " before " << countryVector[i + 1].getName() << endl; // Verbosity, really.
                added = true; // Lets us know that the country was actually added to the vector.
                break;
            }
        }
        if (added == false) { // If the country was not added to the vector (Due to it being the largest country in terms of area).
            countryVector.push_back(country); // Add the country the the end of the vector.
            cout << "Added " << country.getName() << " to end of vector.\n";
        }
    }
}

void printVector() { // Prints the vector in a formatted list.
    cout << "\n\n Country\t Population\t   Area\n"; // Printing the list categories
    cout << "---------\t------------\t----------\n";

    for (int i = 0; i < countryVector.size(); i++) { // Running once per country in vector.
        Country country = countryVector[i]; // Reference to make the code slightly more readable.

        cout << country.getName() << "    \t"; // The spaces before the tab allow the populations to line up properly.

        if (country.getPopulation() < 1000) { // These if statements check the number of digits in population and area.
            cout << "     " << country.getPopulation(); // The number of spaces changes in order to align the ints to the right.
            if (country.getArea() < 100000) { // If an area has more digits, we print one less space, this keeps our areas aligned properly.
                cout << "\t   " << country.getArea() << endl; // From here to line 99 much of the code is repeated in order to ->
            } else if (country.getArea() < 1000000) {        //  account for population not directly correlating with area.
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
    Country argentina("Argentina", 43132, 1074000); // Creating our country object (name, population, area).
    addCountry(argentina); // Calling our method to place the country in question into the vector.
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

    printVector(); // Calling our print method.
}