#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int main() {
    const string fileName = "data.dat";
    fstream dataFile(fileName, ios::out | ios::binary);

    double nums[] = {1.5, 2.6, 3.7, 4.8, 5.9};

    if (!dataFile) {
        cout << "Error opening file: " << fileName;
        exit(1);
    }

    for (int i = 1; i <= 10; i++) { // Writing to the dat file.
        dataFile.write(reinterpret_cast<char *>(&i), sizeof(double));
    }

    dataFile.close();
    dataFile.open(fileName, ios::binary | ios::in);
    for (int i = 0; i < 10; i++) {
        double data;
        dataFile.read(reinterpret_cast<char *>(&data), sizeof(double));
        cout << data << endl;
    }
}