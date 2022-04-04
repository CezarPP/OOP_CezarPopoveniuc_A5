#include <bits/stdc++.h>
#include "Vector.h"

using namespace std;

bool cmp(const int &a, const int &b) {
    return a > b;
}

bool isNice(const int &x, const int &y) {
    return x % 2 == y % 2;
}

bool isNicePair(const pair<int, int> &x, const pair<int, int> &y) {
    return x.first % 3 == y.first % 3;
}

int main() {
    Vector<int> v;
    v.push(3);
    v.push(2);
    v.push(124);
    int &x = v.get(0);
    cout << x << '\n';
    v.sort(cmp);
    v.print();
    v.sort();
    v.print();
    cout << v.count() << '\n';
    for (int i = 3; i < 10; i += 4)
        v.insert(i, 1);
    v.print();
    v.remove(3);
    v.print();
    cout << v.pop() << '\n';
    v.set(3, 4);
    v.set(1, 12);
    v.print();
    cout << v.firstIndexOf(3, isNice) << '\n';
    for (int i = 20; i <= 100; i++)
        v.push(i * i);
    v.print();

    Vector<pair<int, int>> a;
    for (int i = 20; i >= 10; i--)
        a.push(make_pair(i, i * i));
    for (int i = 0; i < a.count(); i++)
        cout << a.get(i).first << ' ' << a.get(i).second << '\n';
    a.sort();
    for (int i = 0; i < a.count(); i++)
        cout << a.get(i).first << ' ' << a.get(i).second << '\n';
    cout << a.firstIndexOf(make_pair(20, 10), isNicePair) << '\n';
    cout << a.firstIndexOf(make_pair(20, 400), nullptr) << '\n';
    cout << a.firstIndexOf(make_pair(20, 400)) << '\n';

    return 0;
}
