#include <iostream>
#include <cmath>
#include "Math.h"

using namespace std;

int main() {
    char a[] = "Concatenating 2 ";
    char b[] = "strings\n";
    char *res = Math::Add(a, b);
    cout << res;
    double x = 3.0, pi = acos(-1);
    cout << "Adding 2 ints: 1, 2 -> " << Math::Add(1, 2) << '\n';
    cout << "Adding 2 doubles -> " << Math::Add(x, pi) << '\n';
    cout << "Adding 3 integers: 5, 6 and 7 -> " << Math::Add(5, 6, 7) << '\n';
    cout << "Adding many integers :1..5 -> " << Math::Add(5, 1, 2, 3, 4, 5) << '\n';
    cout << "Multiplying 2 ints: 1, 2 -> " << Math::Mul(1, 2) << '\n';
    cout << "Adding 3 doubles: pi, 3.5, 4.4 -> " << Math::Add(acos(-1), 3.5, 4.4) << '\n';
    cout << "Multiplying 3 doubles: pi, 3.5, 4.4 -> " << Math::Mul(acos(-1), 3.5, 4.4) << '\n';
    cout << "Multiplying 3 ints: 3, 4, 5 -> " << Math::Mul(3, 4, 5) << '\n';
    cout << "Multiplying 2 doubles: pi, 2 -> " << Math::Mul(acos(-1), 2.0) << '\n';
    return 0;
}
