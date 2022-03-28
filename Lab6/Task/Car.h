
#pragma once
#include <bits/stdc++.h>
#include "Weather.h"

class Car {
public:
    char *name = nullptr;
    int fuelCapacity = 0, fuelConsumption = 0;
    int averageSpeed[3] = {0};

    virtual float timeToFinish(Weather W, int length) = 0;

    Car() = default;
};
