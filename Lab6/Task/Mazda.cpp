
#include "Mazda.h"

Mazda::Mazda() : Car() {
    fuelCapacity = 340;
    fuelConsumption = 3;
    averageSpeed[0] = 100;
    averageSpeed[1] = 100;
    averageSpeed[2] = 120;

    const char *s = "Mazda";
    int n = (int) strlen(s);
    name = (char *) malloc(n + 1);
    strcpy(name, s);
}

float Mazda::timeToFinish(Weather W, int length) {
    float canDoKilometers = (float) fuelCapacity / (float) fuelConsumption;
    if (canDoKilometers < (float) length)
        return FLT_MAX;
    float time = (float) length / (float) averageSpeed[W];
    return time;
}

Mazda::~Mazda() {
    free(name);
}
