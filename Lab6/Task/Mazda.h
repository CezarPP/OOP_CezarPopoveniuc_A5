#pragma once

#include "Car.h"

class Mazda : public Car {
public:
    Mazda();

    ~Mazda();

    float timeToFinish(Weather W, int length) override;
};
