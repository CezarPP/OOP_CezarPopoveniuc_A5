#pragma once

#include "Car.h"

class Toyota : public Car {
public:
    Toyota();

    ~Toyota();

    float timeToFinish(Weather W, int length) override;
};
