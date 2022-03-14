#include "Sort.h"

int main() {
    Sort s1(10, 1, 100);
    s1.Print();
    s1.InsertSort(true);
    cout << "With really random values: ";
    s1.Print();

    Sort s2("10,1,2,9,3,120531,1335");
    s2.QuickSort();
    cout << "With string parameter: ";
    s2.Print();

    Sort s3(5, 2, 1, 4, 3, 3);
    s3.BubbleSort(true);
    s3.Print();

    int a[] = {13, 12, 1, 3, 14, 20, 25, 1, 3};
    Sort s4(a, 9);
    cout << "Element count of s4 is: " << s4.GetElementsCount() << '\n';
    cout << "At the 4th position we have: " << s4.GetElementFromIndex(4) << '\n';

    // initialization list
    Sort s5;
    cout << "Initialization list: ";
    s5.Print();

    return 0;
}
