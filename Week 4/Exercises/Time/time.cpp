#include <ctime>
#include <string>
#include <iostream>

using namespace std;

int main() {
    string days[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    string months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    time_t now = time(NULL);
    tm* local = localtime(&now);

    cout << ctime(&now) << "\n\n";

    cout << days[0] << "/";
}