#pragma once

#include "Car.h"

class Ford : public Car {
public:
    Ford();

    ~Ford();

    float timeToFinish(Weather W, int length) override;
};
