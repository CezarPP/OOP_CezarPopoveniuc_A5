#pragma once
#include <string>
using namespace std;
class Student {
    string name;
    float MathematicsGrade, EnglishGrade, HistoryGrade;
    float avg;
public:
    string getName();
    void setName(const string& s);
    bool setMathematicsGrade(float x);
    float getMathematicsGrade() const;
    bool setEnglishGrade(float x);
    float getEnglishGrade() const;
    bool setHistoryGrade(float x);
    float getHistoryGrade() const;
    float getAverageGrade() const;

    Student();
    ~Student();
};