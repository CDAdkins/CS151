#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int main() {
    const string fileName("array.dat");
    double multiplier;

    fstream dataFile(fileName, ios::binary | ios::in | ios::out);

    if (!dataFile) {
        cout << "Could not open file: " << fileName << endl;
    }

    cout << "Enter a multiplier: ";
    cin >> multiplier;

    for (int i = 0; i < 20; i++) {
        int data;
        long position = dataFile.tellg();
        dataFile.read(reinterpret_cast <char *>(&data), sizeof(int));
        cout << data << " -> ";
        data = round(data * multiplier);
        cout << data << endl;
        dataFile.seekp(position, ios::beg); // Writing the updated number.
        dataFile.write(reinterpret_cast <char *>(&data), sizeof(int));
    }
}