#include <iostream>
#include "Student.h"
#include "Globals.h"

int main() {
    Student Boris, Gigel;
    Boris.setName("Boris");
    Gigel.setName("Gigel");
    Boris.setMathematicsGrade(3);
    Boris.setHistoryGrade(1);
    Boris.setEnglishGrade(2);
    Boris.setEnglishGrade(-1); // should remain 2
    cout << "Boris' English grade is " << Boris.getEnglishGrade() << '\n';
    Gigel.setHistoryGrade(6);
    Gigel.setMathematicsGrade(8);
    Gigel.setEnglishGrade(10);
    if (compareAverage(&Gigel, &Boris) == 1)
        cout << "Gigel is better\n";
    else if (compareAverage(&Gigel, &Boris) == 0)
        cout << "They are equals\n";
    else cout << "Boris is the superior one\n";
    return 0;
}
