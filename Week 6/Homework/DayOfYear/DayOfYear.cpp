/*  DayOfYear.cpp
    Author: Chris Adkins
    Module: 6
    Project: 1
    Problem Statement: This program takes a number between 1 and 365 and tells you the actual date from that number.


    Algorithm:
        1. Create a class called DayOfYear.
            a. private int for the number of days into the year the date is.
            b. Create arrays for the names of the months as well as the number of days in each month.
            c. Two constructors, one for a single int parameter, and one for a string as well as an int.
            d. Overloaded functions for ++, --, and <<.
        2. Create a main function to demonstrate the functions in the DayOfYear class.

    Classes Needed:
        <iostream> - For printing to the user.
*/

#include <iostream>

using namespace std;

class DayOfYear {
    private:
        int day = 0;
        const string months[12] = {"January", "February", "March", "April", "May", "June",
                             "July", "August", "September", "October", "November", "December"};
        // Array of ints to be used in reference to the above array.
        const int daysInMonths[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    public:
        friend ostream &operator<<(ostream &, const DayOfYear &); // Prototype for << operator overload.

        DayOfYear(int day) { // Single-Argument Constructor.
            this->day = day;
        }

        DayOfYear(string month, int day) {
            for (int i = 0; i < 12; i++) {
                if (month == months[i]) { // If we find a matching month.
                    if (day > daysInMonths[i] || day < 1) { // If we have too may or too few days.
                        cout << "Day out of range. Exiting Program..."; // Print an error.
                        exit(1); // Exit the program.
                    }
                    this->day += day;
                    break;
                }
                this->day += daysInMonths[i]; // If a month doesn't match, add the days in that month to the total.
                if (i == 11 && month != months[i]) { // If after checking all of the months w/out finding a match.
                    cout << "Invalid Month. Exiting Program..."; // Print an error.
                    exit(2); // Kill the program.
                }
            }
        }

        DayOfYear operator++() {          // Overloading the prefix ++ operator.
            if (day == 365) {
                return DayOfYear(1);
            }
            return DayOfYear(day + 1); //  Creates a new DayOfYear object and returns that.
        }                             //   Effectively making this operator a temporary version of the postfix version.

        DayOfYear operator++(int) { // Overloading the postfix operator. Permanent version of prefix.
            if (day == 365) {
                day = 1;
                return *this;
            }
            day++;              //  We directly increment the day variable by one.
            return *this;      //   Return the same object that predates the operator.
        }

        DayOfYear operator--() {           // Overloading the prefix -- operator.
            if (day == 1) {
                return DayOfYear(365);   //   Return a new DayOfYear object with 365 as an argument.
            }
            return DayOfYear(day - 1); //     Returns a new object with the day decremented by one.
        }                             //      Temporary version of the postfix operator.

        DayOfYear operator--(int) { // Overloading the postfix ++ operator. Permanent version of prefix.
            if (day == 1) {        //  If our date is January 1st. 
                day = 365;        //   Set the date equal to December 31st.
                return *this;    //    Return this object.
            }
            day--;             //  Directly decrement the day by one.
            return *this;     //   Return the calling object.
        }

        int getDay() {
            return day;
        }

        void setDay(int day) {
            this->day = day;
        }
};

ostream &operator<<(ostream &out, const DayOfYear &dayOut) { // Overloading the stream extraction operator.
    string month;
    int day = dayOut.day;
    for (int  i = 0; i < 12; i++) {
        if (day <= dayOut.daysInMonths[i]) {
            month = dayOut.months[i];
            break;
        }
        day -= dayOut.daysInMonths[i];
    }
    out << month << " " << day;
    // Determining if the number should have an -st, -nd, -rd, or -th at the end,
    if (day == 1 || day == 21 || day == 31) {
        out << "st";
    } else if (day == 2 || day == 22) {
        out << "nd";
    } else if (day == 3 || day == 23) {
        out << "rd";
    } else {
        out << "th";
    }
    return out;
}



int main() {
    DayOfYear day1(15);
    DayOfYear day2("January", 15);
    DayOfYear day3("December", 31);
    DayOfYear day4("January", 1);
    DayOfYear day5("March", 4);
    DayOfYear day6("July", 27);
    DayOfYear day7(31);
    DayOfYear day8(59);
    DayOfYear day9(180);
    DayOfYear day10(360);

    // Challenge 2 Demonstration. TODO
    cout << "\nChallenge 2 Demonstration:" << endl;
    cout << "--------------------------" << endl;
    cout << "day1(15):\t\t" << day1 << endl;
    cout << "day7(31):\t\t" << day7 << endl;
    cout << "day8(59):\t\t" << day8 << endl;
    cout << "day9(180):\t\t" << day9 << endl;
    cout << "day10(360):\t\t" << day10 << endl;

    // Challenge 3 Demonstration.
    cout << "\nChallenge 3 Demonstration:" << endl;
    cout << "--------------------------" << endl;
    cout << "Original Day 1:\t\t" << day1 << " |\tConstructor: day1(324);" <<endl;
    cout << "Original Day 2:\t\t" << day2 << " |\tConstructor: day2(\"November\", 20);" << endl;
    cout << "\nDay 1 with postfix ++:\t" << day1++ << " |\tcout << day1++;"<< endl;
    cout << "Day 2 with prefix ++:\t" << ++day2 << " |\tcout << ++day2;" << endl;
    cout << "\nDay 1 after postfix ++: " << day1 << " |\tcout << day1;" << endl;
    cout << "Day 2 after prefix ++:  " << day2 << " |\tcout << day2;" << endl;
    cout << "\nDay 1 with postfix --:\t" << day1-- << " |\tcout day1--;" << endl;
    cout << "Day 2 with prefix --: \t" << --day2 << " |\tcout << --day2;" << endl;
    cout << "\nDay 1 after postfix --: " << day1 << " |\tcout << day1;" << endl;
    cout << "Day 2 after prefix --:  " << day2 << " |\tcout << day2;" << endl;
    cout << "\nOriginal Day 3:\t\t" << day3 << endl;
    cout << "day3++:\t\t\t" << day3++ << endl;
    cout << "Original Day 4:\t\t" << day4 << endl;
    cout << "day4--:\t\t\t" << day4-- << endl;
    cout << "day5:\t\t\t" << day5.getDay() << " - " << day5 << endl;
    cout << "day6:\t\t\t" << day6.getDay() << " - " << day6 << endl;
    cout << "day7:\t\t\t" << day7.getDay() << " - " << day7 << endl;
}