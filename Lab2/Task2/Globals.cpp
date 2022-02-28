#include "Globals.h"
#include "Student.h"

int compareName(Student *S1, Student *S2) {
    if (S1->getName() > S2->getName())
        return 1;
    else if (S1->getName() == S2->getName())
        return 0;
    return -1;
}

int compareEnglishGrade(Student *S1, Student *S2) {
    if (S1->getEnglishGrade() > S2->getEnglishGrade())
        return 1;
    else if (S1->getEnglishGrade() < S2->getEnglishGrade())
        return -1;
    return 0;
}

int compareMathematicsGrade(Student *S1, Student *S2) {
    if (S1->getMathematicsGrade() > S2->getMathematicsGrade())
        return 1;
    else if (S1->getMathematicsGrade() < S2->getMathematicsGrade())
        return -1;
    return 0;
}

int compareHistoryGrade(Student *S1, Student *S2) {
    if (S1->getHistoryGrade() > S2->getHistoryGrade())
        return 1;
    else if (S1->getHistoryGrade() < S2->getHistoryGrade())
        return -1;
    return 0;
}

int compareAverage(Student *S1, Student *S2) {
    if (S1->getAverageGrade() > S2->getAverageGrade())
        return 1;
    else if (S1->getAverageGrade() < S2->getAverageGrade())
        return -1;
    return 0;
}
