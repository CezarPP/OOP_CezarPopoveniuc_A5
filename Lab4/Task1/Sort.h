
#pragma once

#include <bits/stdc++.h>

using namespace std;

class Sort {
    int *v = nullptr;
    int cnt;

    int part(int st, int dr);

    void quicksort(int st, int dr);

    void reverse();

public:
    // first
    Sort(int numberOfElem, int mnVal, int mxVal);

    // second
    Sort();

    //third
    Sort(int a[], int size);

    // fourth
    Sort(int n, ...);

    // fifth
    Sort(const string &s);

    void InsertSort(bool ascendent = false);

    void QuickSort(bool ascendent = false);

    void BubbleSort(bool ascendent = false);

    void Print();

    int GetElementsCount() const;

    int GetElementFromIndex(int index);

};