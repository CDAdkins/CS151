#include <iostream>

using namespace std;

int main() {
    string monthNames[] = {"January", "Febuary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int temperatures[] = {38, 42, 50, 61, 72, 79, 84, 83, 75, 64, 54, 43};
    string warmestMonth;
    string coldestMonth;
    int warmestTemp = INT16_MIN;
    int coldestTemp = INT16_MAX;

    for (int i = 0; i < 12; i++) { // Loop to display months with temps.
        cout << monthNames[i] << ":     \t";
        if (temperatures[i] > warmestTemp) { // If statements to find warmest month.
            warmestTemp = temperatures[i];
            warmestMonth = monthNames[i];
            cout << " " << warmestTemp << endl;
        } else {
            cout << " " << temperatures[i] << endl;
        }
    }
    cout << "\nWarmest Month Was " << warmestMonth << ": " << warmestTemp << " degrees\n";

    for (int i = 0; i < 12; i++) {
        if (temperatures[i] < coldestTemp) { // If statements to find warmest month.
            coldestTemp = temperatures[i];
            coldestMonth = monthNames[i];
        }
    }
    cout << "\nColdest Month Was " << coldestMonth << ": " << coldestTemp << " degrees";
}
