
#include "Toyota.h"

Toyota::Toyota() : Car() {
    fuelCapacity = 500;
    fuelConsumption = 10;
    averageSpeed[0] = 40;
    averageSpeed[1] = 20;
    averageSpeed[2] = 50;

    const char *s = "Toyota";
    int n = (int) strlen(s);
    name = (char *) malloc(n + 1);
    strcpy(name, s);
}

float Toyota::timeToFinish(Weather W, int length) {
    float canDoKilometers = (float) fuelCapacity / (float) fuelConsumption;
    if (canDoKilometers < (float) length)
        return FLT_MAX;
    float time = (float) length / (float) averageSpeed[W];
    return time;
}

Toyota::~Toyota() {
    free(name);
}
