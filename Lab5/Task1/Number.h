#pragma once

#include <bits/stdc++.h>

using namespace std;

class Number {
    long long internalNr = 0;
    int base = 0;
    string x;

    long long toBase10();

public:
    Number();

    Number(int x);

    Number(const char *value, int base); // where base is between 2 and 16

    ~Number();

    Number(const Number &nr); // copy constructor
    Number(Number &&nr); //move constructor

    bool operator>(const Number &nr) const;

    bool operator<(const Number &nr) const;

    bool operator>=(const Number &nr) const;

    bool operator<=(const Number &nr) const;

    bool operator==(const Number &nr) const;

    int operator[](int index); //index operator

    Number &operator=(const Number &nr);

    Number &operator=(const string &s);

    Number &operator+=(const Number &nr);

    Number &operator=(int nr);

    Number &operator--(); // for --x
    void operator--(int); // for x--
    void SwitchBase(int newBase);

    void Print();

    friend Number operator+(const Number &nr1, const Number &nr2);

    friend Number operator-(const Number &nr1, const Number &nr2);

    int GetDigitsCount(); // returns the number of digits for the current number
    int GetBase() const; // returns the current base
};