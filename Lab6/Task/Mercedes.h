#pragma once

#include "Car.h"

class Mercedes : public Car {
public:
    Mercedes();

    ~Mercedes();

    float timeToFinish(Weather W, int length) override;
};
