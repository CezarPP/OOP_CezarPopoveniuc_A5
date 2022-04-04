#include <bits/stdc++.h>

using namespace std;

float operator "" _Kelvin(const char *x) {
    float ans = strtof(x, nullptr) - 273.15f;
    return ans;
}

float operator "" _Fahrenheit(const char *x) {
    float ans = (strtof(x, nullptr) - 32) * 0.5556f;
    return ans;
}

int main() {
    float a = 300_Kelvin;
    float b = 120_Fahrenheit;
    cout << a << ' ' << b << '\n';
    return 0;

}