#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> myVector; // Initializing Vector

    cout << myVector.capacity() << endl; // Shows Initial Capacity

    //myVector.push_back(6); // Adds the int 6 to the end of the vector

    cout << myVector.capacity() << endl; // Shows the doubling of vector capacity

    myVector.shrink_to_fit(); // Shrinks the capacity of vector to num of ints in Vector

    cout << myVector.capacity() << endl; // Shows capacity after shrink

    if (myVector[0] == 0) {
        myVector.insert(myVector.begin(), 99);
    }

    cout << "\n\n";

    for (int i = 0; i < myVector.size(); i++) {
        cout << myVector[i] << ", ";
    }
}
