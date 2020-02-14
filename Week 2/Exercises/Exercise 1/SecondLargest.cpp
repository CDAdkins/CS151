#include <iostream>
#include <vector>

using namespace std;

int secondLargest(vector<int> vector) { // Method to find the second largest int.
    int largest = INT32_MIN; // This will hold the largest int in the array.
    int secondLargest = INT32_MIN; // This will hold the second largest int in the array.

    for (int i = 0; i < vector.size(); i++) {
        if (vector[i] > largest) {
            secondLargest = largest;
            largest = vector[i];
        } else if (vector[i] > secondLargest) {
            secondLargest = vector[i];
        }
    }
    cout << "Second Largest Int: " << &secondLargest << endl;
}


int main() {
    vector<int> intVector = {9, 6, 3, 4, 2};

    secondLargest(intVector);
}