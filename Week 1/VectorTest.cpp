#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> myVector{1, 2, 3, 4, 5}; // Initializing Vector

    cout << myVector.capacity() << endl; // Shows Initial Capacity

    myVector.push_back(6); // Adds the int 6 to the end of the vector

    cout << myVector.capacity() << endl; // Shows the doubling of vector capacity

    myVector.shrink_to_fit(); // Shrinks the capacity of vector to num of ints in Vector

    cout << myVector.capacity() << endl; // Shows capacity after shrink
}
