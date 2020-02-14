#include <iostream>
#include <iomanip>

using namespace std;

class Student {
    public:
    string name;
    double score;

    Student(string name, double score) {
        this->name = name;
        this->score = score;
    }

    Student() {
        name = " ";
        score = 0.0;
    }

    ~Student() {
    }

    string getName() {
        return name;
    }

    double getScore() {
        return score;
    }

    void setName(string name) {
        this->name = name;
    }

    void setScore(double score) {
        this->score = score;
    }
};

void sortScores(Student* ptr, int size) {
    Student temp(" ", 0.0); // Temp used for swapping students.
    bool swapped = true;

    while (swapped) {
        swapped = false;
        for (int i = 0; i < size - 1; i++) { // Loop through the test scores.
            if ((ptr + i)->score > (ptr + i + 1)->score) { // If the next element is larger than our current element.
                temp = *(ptr + i + 1); // Set temp to the next student.
                *(ptr + i+1) = *(ptr + i); // Move current student forward one place.
                *(ptr + i) = temp; // Set the current position to the student stored in temp.
                swapped = true; // Indicate that a swap has occurred.
            }
        }
    }
}

double averageScore(Student* ptr, int size) {
    double total = 0;

    for (int i = 0; i < size; i++) {
        total += (ptr + i)->score;
    }

    return (double)total/size;
}

int main() {
    int numTests; // The number of test scores that will be stored.

    cout << "How many test scores are you storing: ";
    cin >> numTests;

    Student* testScores = new Student[numTests]; // Create array based on user input.

    for(int i = 0; i < numTests; i++) { // Loop once per test score.
        cout << "\nStudent " << i + 1 << "'s Name: ";
        cin >> (testScores + i)->name;
        cout << (testScores + i)->name << "'s " << " Score: ";
        cin >> (testScores + i)->score; // Fill the array with inputs from user.

        while((testScores + i)->score < 0) { // Check to see if inputs are less than zero.
            cout << "Only enter positive values for test scores.\n"; // Print errors and get new input.
            cout << "Test " << i + 1 << ": ";
            cin >> (testScores + i)->score;
        }
    }

    sortScores(testScores, numTests); // Call the sort method.

    cout << fixed << setprecision(1); // Limit decimals to tenths place.

    cout << "\nSorted Scores:\nName\t\tScore\n"; // Print sorted scores to user.
    cout << "----------------------\n";
    for(int i = 0; i < numTests; i++) {
        cout << (testScores + i)->name << "\t\t";
        cout << (testScores + i)->score << endl;
    }

    cout << "\n\nAverage Score: "; // Display the average score to the user.
    cout << averageScore(testScores, numTests);

    delete[] testScores;
}