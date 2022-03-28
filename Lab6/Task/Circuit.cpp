
#include "Circuit.h"
#include <bits/stdc++.h>

void Circuit::AddCar(Car *c) {
    v[nrCars++] = c;
}

void Circuit::SetLength(int lg) {
    length = lg;
}

void Circuit::SetWeather(Weather w) {
    weather = w;
}

void Circuit::Race() {
    std::sort(v, v + nrCars, [this](Car *A, Car *B) {
        return (A->timeToFinish(this->weather, this->length) <
                B->timeToFinish(this->weather, this->length));
    });
}

void Circuit::ShowFinalRanks() {
    for (int i = 0; i < nrCars; i++)
        if (v[i]->timeToFinish(this->weather, this->length) != FLT_MAX) {
            std::cout << "The " << (i + 1) << "th place is "
                      << v[i]->name << '\n';
        } else break;
}

void Circuit::ShowWhoDidNotFinish() {
    for (int i = 0; i < nrCars; i++)
        if (v[i]->timeToFinish(this->weather, this->length) == FLT_MAX) {
            std::cout << v[i]->name << " did not finish.\n";
        }
}