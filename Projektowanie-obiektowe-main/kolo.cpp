#include "kolo.h"
#include <cmath>    // dla M_PI

Kolo::Kolo(double r) {
    promien = r;
}

double Kolo::getPromien() const {
    return promien;
}

double Kolo::getSrednica() const {
    return 2 * promien;
}

double Kolo::getObwod() const {
    return 2 * M_PI * promien;
}
