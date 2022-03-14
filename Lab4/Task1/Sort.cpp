
#include "Sort.h"

Sort::Sort(int numberOfElem, int mnVal, int mxVal) {
    random_device randomDevice;
    uniform_int_distribution<int> intDistribution(mnVal, mxVal);
    delete[] v;
    v = new int[numberOfElem];
    cnt = numberOfElem;
    for (int i = 0; i < numberOfElem; i++)
        v[i] = intDistribution(randomDevice);
}

Sort::Sort(int a[], int size) {
    delete[] v;
    v = new int[size];
    cnt = size;
    memcpy(v, a, 4 * size);
}

Sort::Sort() : v(new int[6]{1, 3, 2, 5, 6, 4}), cnt(6) {

}

Sort::Sort(int n, ...) {
    va_list vaList;
    va_start(vaList, n);
    cnt = n;
    delete[] v;
    v = new int[n];
    for (int i = 0; i < n; i++)
        v[i] = va_arg(vaList, int);
    va_end(vaList);
}

Sort::Sort(const string &s) {
    const char *aux = s.c_str();
    char c[s.size() + 1];
    for (int i = 0; aux[i]; i++)
        c[i] = aux[i];
    c[s.size()] = 0;
    vector<int> a;
    for (char *p = strtok(c, ","); p; p = strtok(nullptr, ",")) {
        int nr = strtol(p, nullptr, 10);
        a.push_back(nr);
    }
    cnt = (int) a.size();
    v = new int[a.size()];
    for (int i = 0; i < cnt; i++)
        v[i] = a[i];
}

void Sort::InsertSort(bool ascendent) {
    for (int i = 1; i < cnt; i++) {
        int aux = v[i];
        int j;
        for (j = i - 1; j >= 0 && v[j] > aux; j--)
            v[j + 1] = v[j];
        v[j + 1] = aux;
    }
    if (!ascendent)
        reverse();
}

int Sort::part(int st, int dr) {
    int pozDr = dr;
    int pi = (st + dr) / 2;
    swap(v[pi], v[dr]);
    pi = v[dr];
    dr--;
    while (st <= dr) {
        while (v[st] <= pi and st <= dr)
            st++;
        while (v[dr] >= pi and st <= dr)
            dr--;
        if (st <= dr) {
            swap(v[st], v[dr]);
            st++;
            dr--;
        }
    }
    swap(v[st], v[pozDr]);
    return st;
}

void Sort::quicksort(int st, int dr) {
    if (st < dr) {
        int pivot = part(st, dr);
        quicksort(st, pivot - 1);
        quicksort(pivot + 1, dr);
    }
}

void Sort::reverse() {
    for (int i = 0; i < cnt / 2; i++)
        swap(v[i], v[cnt - i - 1]);
}

void Sort::QuickSort(bool ascendent) {
    quicksort(0, GetElementsCount());
    if (!ascendent)
        reverse();
}

void Sort::BubbleSort(bool ascendent) {
    bool finished;
    do {
        finished = true;
        for (int i = 0; i < cnt - 1; i++)
            if (v[i] > v[i + 1]) {
                swap(v[i], v[i + 1]);
                finished = false;
            }
    } while (!finished);
    if (!ascendent)
        reverse();
}

void Sort::Print() {
    for (int i = 0; i < cnt; i++)
        cout << v[i] << ' ';
    cout << '\n';
}

int Sort::GetElementsCount() const {
    return cnt;
}

int Sort::GetElementFromIndex(int index) {
    if (index < 0 || index >= (int) cnt)
        return 0;
    return v[index];
}
