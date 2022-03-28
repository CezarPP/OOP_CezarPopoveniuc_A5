#pragma once
#define MAX_COUNT_CARS 100

#include "Car.h"
#include "Weather.h"

class Circuit {
private:
    int length = 0, nrCars = 0;
    Weather weather = Sunny;
public:
    Car *v[MAX_COUNT_CARS] = {nullptr};

    void SetWeather(Weather w);

    void SetLength(int lg);

    void AddCar(Car *c);

    void Race();

    void ShowFinalRanks();

    void ShowWhoDidNotFinish();
};