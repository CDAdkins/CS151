#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int main() {
    const string fileName = "array.dat";
    ofstream outFile(fileName, ios::out | ios::binary);

    if (!outFile) {
        cout << "Error opening file: " << fileName;
        exit(1);
    }

    for (int i = 1; i <= 10; i++) {
        outFile.write(reinterpret_cast<char *>(&i), sizeof(int));
    }

    for (int i = 1; i <= 10; i++) {
        double square = sqrt(i);
        cout << square << endl;
        outFile.write(reinterpret_cast<char *>(&square), sizeof(double));
    }
    outFile.close();
}