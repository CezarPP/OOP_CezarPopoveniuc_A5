#pragma once

#include "Car.h"

class Dacia : public Car {
public:
    Dacia();

    ~Dacia();

    float timeToFinish(Weather W, int length) override;
};
