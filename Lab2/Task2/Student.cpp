#include "Student.h"
#include <string>
#include <iostream>

using namespace std;

Student::Student() {
    EnglishGrade = HistoryGrade = MathematicsGrade = avg = 0;
    cout << "Created a new student\n";
}

Student::~Student() {
    cout << "Deleted a student\n";
}

string Student::getName() {
    return name;
}

void Student::setName(const string &s) {
    name = s;
}

float Student::getEnglishGrade() const {
    return EnglishGrade;
}

float Student::getHistoryGrade() const {
    return HistoryGrade;
}

float Student::getMathematicsGrade() const {
    return MathematicsGrade;
}

bool Student::setEnglishGrade(float x) {
    if (1 <= x && x <= 10) {
        EnglishGrade = x;
        return true;
    }
    return false;
}

bool Student::setHistoryGrade(float x) {
    if (1 <= x && x <= 10) {
        HistoryGrade = x;
        return true;
    }
    return false;
}

bool Student::setMathematicsGrade(float x) {
    if (1 <= x && x <= 10) {
        MathematicsGrade = x;
        avg = (EnglishGrade + MathematicsGrade + HistoryGrade) / 3;
        return true;
    }
    return false;
}

float Student::getAverageGrade() const {
    return avg;
}