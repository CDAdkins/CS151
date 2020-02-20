/*  time.cpp
    Author: Chris Adkins
    Module: 4
    Project: Excercise 1
    Problem Statement: 
    This program is a demonstration of the different ways time can be represented in C++.

    Algorithm:
        1. Create two arrays, one for days and one for months to convert a month/day's number to its name.
        2. Create a tm structure for local time.
        3. Use the tm structure to print the date in the formats listed in the assignment.
        4. Create a tm structure for my DOB and populate it with accurate data.
        5. Use ctime to print information about DOB.
        6. Create an int to hold the number of seconds in a week.
        7. Use that int to print the date 1 week before DOB using ctime.

    Classes Needed:
        <ctime>    - For presenting the time to the user.
        <iostream> - For printing to the user
        
*/

#include <ctime>
#include <iostream>

using namespace std;

int main() {
    // These two arrays represent the names of the days and months in order.
    string days[]     = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    string months[]   = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int secondsInWeek = 7*24*60*60; // daysPerWeek * hoursInDay * minutesInHour * secondsInMinute.

    time_t now = time(NULL); // Creating a time variable for printing the current time.
    tm* local  = localtime(&now); // tm structure holding the local time.
    
    tm birthday; // second tm structure holding the time of my birth date.
    birthday.tm_year  = 1998 - 1900;
    birthday.tm_mon   = 11;
    birthday.tm_mday  = 27;
    birthday.tm_hour  = 4;
    birthday.tm_min   = 20;
    birthday.tm_sec   = 0;
    birthday.tm_isdst = 0;

    time_t time_of_birthday = mktime(&birthday); // converting our tm structure to a time variable to be printed.

    cout << "\n" << local->tm_mon + 1 << "/" << local->tm_mday << "/" << local->tm_year - 100 << endl; // m/d/yy
    cout << months[local->tm_mon] << " " << local->tm_mday << ", " << local->tm_year + 1900 << endl; // Month day, yyyy
    cout << local->tm_mday << "-" << months[local->tm_mon].substr(0, 3) << "-" << local->tm_year + 1900 << endl; // d-m-yyyy

    if (local->tm_min < 10) { // if statement to determine if we need a 0 before the minute, Ex: 11:9am -> 11:09am.
        cout << local->tm_hour << ":0" << local->tm_min << endl;
    } else {
        cout << local->tm_hour << ":" << local->tm_min << endl;
    }

    if (local-> tm_hour < 13) { // If we need to convert from 24h time to 12h time. 
        if (local->tm_min < 10) { // Determining of an extra 0 is needed for the minute.
            cout << local->tm_hour << ":0" << local->tm_min << "am" << endl; // If we don't need to convert then we are in am.
        } else {
            cout << local->tm_hour << ":" << local->tm_min << "am" << endl;
        }
        
    } else {
        if (local->tm_min < 10) {// Determining of an extra 0 is needed for the minute.
            cout << local->tm_hour << ":0" << local->tm_min << "pm" << endl; // If we do then subtract 12 from the hour and write pm.
        } else {
            cout << local->tm_hour << ":" << local->tm_min << "pm" << endl;
        } 
    }

    cout << "\n" << ctime(&time_of_birthday) << endl; // Printing DOB
    cout << "I was born " << time_of_birthday << " seconds after epoch!" << endl;

    cout << "\nThere are " << secondsInWeek << " seconds in one week!" << endl;

    birthday.tm_sec -= secondsInWeek; // Subtracting one weeks worth of seconds from the birth date.
    time_of_birthday = mktime(&birthday); // updating time_of_birthday to use the new date.

    cout << "The week before my birth date was " << ctime(&time_of_birthday) << endl;
}