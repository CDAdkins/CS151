#include <iostream>
#include <iomanip>

using namespace std;

int pieMode(int* pies, int size) {
    double temp; // Temp used for swapping pies.
    bool swapped = true;

    while (swapped) {
        swapped = false;
        for (int i = 0; i < size - 1; i++) { // Loop through the test scores.
            if (*(pies + i) > *(pies + i + 1)) { // If the next element is larger than our current element.
                temp = *(pies + i + 1); // Set temp to the next element.
                *(pies + i+1) = *(pies + i); // Move current element forward one place.
                *(pies + i) = temp; // Set the current position to the score stored in temp.
                swapped = true; // Indicate that a swap has occurred.
            }
        }
    }

    int number = *(pies);
    int mode = number;
    int count = 1;
    int countMode = 1;
    for (int i = 0; i < size; i++) {
        if(*(pies + i) == number) {
            count++;
        } else {
            if (count > countMode) {
                countMode = count;
                mode = number;
            }
            count = 1;
            number = *(pies + i);
        }
    }
    return mode;
}

int main() {
    int* pies = new int[30];

    for (int i = 0; i < 30; i++) {
        cout << "How many pieces of pie does Person " << i + 1 << " eat? ";
        cin >> *(pies + i);
    }

    cout << "Sorted List:\n";
    for (int i = 0; i < 30; i++) {
        cout << *(pies + i) << ", ";
    }

    cout << "\nMode: " << pieMode(pies, 30);
}