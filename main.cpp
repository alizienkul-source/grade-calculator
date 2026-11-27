#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
using namespace std;
int main() {
    string studentName;
    int score;
    int studentCount = 0;
    double classTotalAverage = 0.0;
    while (true) {
        cout << "\nStudent name (or end to finish): ";
        getline(cin, studentName);
        if (studentName == "end") {
            break;
        }
        double totalScore = 0.0;
        for (int i = 1; i <= 5; i++) {
            while (true) {
                cout << "Score " << i << ": ";
                if (!(cin >> score)) {
                    cout << "Invalid input. Enter a whole number from 0 to 100.\n";
                    cin.clear();
                    cin.ignore(1000, '\n');
                    continue;
                }
                if (score < 0 || score > 100) {
                    cout << "Invalid score. Enter a value from 0 to 100.\n";
                    continue;
                }
                totalScore += score;
                break;
            }
        }
        cin.ignore(1000, '\n');

        double average = totalScore / 5.0;
        string grade;
        if (average >= 90) {
            grade = "A";
        }
        else if (average >= 75) {
            grade = "B";
        }
        else if (average >= 60) {
            grade = "C";
        }
        else {
            grade = "F";
        }
        cout << fixed << setprecision(1);

        cout << studentName << ": average " << average
             << ", grade " << grade << endl;

        classTotalAverage += average;
        studentCount++;
    }
    if (studentCount == 0) {
        cout << "No students entered" << endl;
    }
    else {
        double classAverage = classTotalAverage / studentCount;
        cout << "Students entered: " << studentCount << endl;
        cout << "Class average: " << fixed << setprecision(1)
             << classAverage << endl;
    }
    return 0;
}
