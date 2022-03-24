#include "Number.h"

using namespace std;

Number::Number(const char *value, int base) {
    x.clear();
    for (int i = 0; value[i]; i++)
        x += value[i];
    this->base = base;
    internalNr = toBase10();
}

void Number::SwitchBase(int newBase) {
    x.clear();
    long long aux = internalNr;
    while (aux) {
        char crt = (char) (aux % newBase);
        if (crt < 10)
            x += (char) (crt + '0');
        else
            x += (char) ('A' + crt - 10);
        aux /= newBase;
    }
    reverse(x.begin(), x.end());
    base = newBase;
}

void Number::Print() {
    cout << x << '\n';
}

int Number::GetDigitsCount() {
    return (int) x.size();
}

int Number::GetBase() const {
    return base;
}

Number::Number(const Number &nr) {
    base = nr.base;
    internalNr = nr.internalNr;
    x = nr.x;
}

Number::Number(Number &&nr) {
    base = nr.base;
    internalNr = nr.internalNr;
    x = nr.x;
    nr.x.clear();
}

long long Number::toBase10() {
    long long ans = 0, p = 1;
    for (int i = (int) x.size() - 1; i >= 0; i--) {
        if (isdigit(x[i]))
            ans += p * (long long) (x[i] - '0');
        else {
            // is from A to F
            ans += p * (long long) (x[i] - 'A' + 10);
        }
        p *= base;
    }
    return ans;
}

bool Number::operator>(const Number &nr) const {
    return internalNr > nr.internalNr;
}

bool Number::operator<(const Number &nr) const {
    return internalNr < nr.internalNr;
}

int Number::operator[](int index) {
    if (index < 0 || index >= x.size())
        return 0;
    return x[index];
}

Number &Number::operator--() {
    string aux;
    for (int i = 1; i < x.size(); i++)
        aux += x[i];
    x = aux;
    internalNr = toBase10();
    return *this;
}

void Number::operator--(int) {
    x.pop_back();
    internalNr = toBase10();
}

Number &Number::operator=(const Number &nr) = default;

Number &Number::operator=(const int nr) {
    internalNr = nr;
    if (base == 0) {
        base = 10;
        x = to_string(nr);
    } else {
        // let's convert nr to base
        int aux = nr;
        x.clear();
        while (aux) {
            char crt = (char) (aux % base);
            if (crt < 10)
                x += (char) (crt + '0');
            else
                x += (char) ('A' + crt - 10);
            aux /= base;
        }
        reverse(x.begin(), x.end());
    }
    return *this;
}

Number &Number::operator+=(const Number &nr) {
    internalNr += nr.internalNr;
    return *this;
}

Number::Number(int x) {
    base = 10;
    internalNr = x;
    this->x = to_string(x);
}

Number &Number::operator=(const string &s) {
    base = 10;
    internalNr = stoll(s);
    x = s;
    return *this;
}

Number operator+(const Number &nr1, const Number &nr2) {
    Number res;
    res.internalNr = nr1.internalNr + nr2.internalNr;
    res.base = max(nr1.base, nr2.base);
    res.SwitchBase(res.base);
    return res;
}

Number operator-(const Number &nr1, const Number &nr2) {
    Number res;
    res.internalNr = nr1.internalNr - nr2.internalNr;
    res.base = max(nr1.base, nr2.base);
    res.SwitchBase(res.base);
    return res;
}

bool Number::operator>=(const Number &nr) const {
    return internalNr >= nr.internalNr;
}

bool Number::operator<=(const Number &nr) const {
    return internalNr <= nr.internalNr;
}

bool Number::operator==(const Number &nr) const {
    return internalNr == nr.internalNr;
}

Number::Number() = default;

Number::~Number() = default;

