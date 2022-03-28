#include "Mercedes.h"

Mercedes::Mercedes() : Car() {
    fuelCapacity = 50;
    fuelConsumption = 20;
    averageSpeed[0] = 200;
    averageSpeed[1] = 100;
    averageSpeed[2] = 150;

    const char *s = "Mercedes";
    int n = (int) strlen(s);
    name = (char *) malloc(n + 1);
    strcpy(name, s);
}

float Mercedes::timeToFinish(Weather W, int length) {
    float canDoKilometers = (float) fuelCapacity / (float) fuelConsumption;
    if (canDoKilometers < (float) length)
        return FLT_MAX;
    float time = (float) length / (float) averageSpeed[W];
    return time;
}

Mercedes::~Mercedes() {
    free(name);
}
