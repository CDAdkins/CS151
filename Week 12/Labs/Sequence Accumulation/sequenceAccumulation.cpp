/*  sequenceAccumulation.cpp
    Author: Chris Adkins
    Module: Lab 13
    Project: 4
    Problem Statement: 

    Algorithm:
        1. Create a function template for accum.
            a. The accum function should have a variable called sum.
            b. Initialize sum with the proper data type with T().
            c. Use a for loop to iterate over the vector and add the values to the sum.
            d. Return the sum.
        2. In main, create three vectors with the data types int, double, and string.
        3. Call the accum function with the three different vectors and print the results.

    Classes Needed:
        <iostream> - For printing to the user.
        <vector>   - For the vectors.
*/

#include <iostream>
#include <vector>
using namespace std;

template <class T>
T accum(vector<T> v) { // Function that will add the contents of a vector regardless of type.
    T sum = T(); // Initializing our sum to whatever type of data we are dealing with.
    for (int i = 0; i < v.size(); i++) { // Iterate over the vector.
        sum += v[i]; // Add each value to the sum.
    }
    return sum;
};

int main() {
    // Defining three vectors of three different types.
    vector<int> intVector = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<double> doubleVector = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8. , 9.9, 10.0};
    vector<string> stringVector = {"Hello", "World"};

    // Calling our accum function with the three different vectors as arguments.
    cout << accum(intVector) << endl;
    cout << accum(doubleVector) << endl;
    cout << accum(stringVector) << endl;
};