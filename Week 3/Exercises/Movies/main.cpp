#include "Movie.h"
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    vector<Movie*> library;

    library.push_back(new Movie("Avatar", 2009, 2.790));
    library.push_back(new Movie("The Force Awakens", 2015, 2.070));
    library.push_back(new Movie("Endgame", 2019, 2.796));
    library.push_back(new Movie("Infinity War", 2018, 2.050));
    library.push_back(new Movie("Jurassic World", 2015, 1.670));
    library.push_back(new Movie("Lion King", 2019, 1.600));
    library.push_back(new Movie("Titanic", 1997, 2.190));

    Movie temp;
    for (int i = 0; i < library.size() - 1; i++) {
        for (int j = i + 1; j < library.size(); j++) {
            if (library[i]->getRevenue() < library[j]->getRevenue()) {
                swap(library[i], library[j]);
            }
        }
    }

    cout << "\n" << setw(20) << left << "Title";
    cout << setw(6) << right << "Year";
    cout << setw(8) << "Sales" << endl ;
    cout << "-----------------------------------\n";
    for (int i = 0; i < library.size(); i++) {
        cout << setw(20) << left << library[i]->getTitle();
        cout << setw(6) << right << library[i]->getYear();
        cout << setw(8) << setprecision(3) << showpoint << library[i]->getRevenue() << endl;
    }
}