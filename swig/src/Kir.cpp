#include "Kir.h"

Kir::Kir(std::string dickName, double pG, double pL): name(dickName) {
    penisGirth = pG;
    penisLength = pL;
}

Kir::~Kir()
{
}

float Kir::getVolume() {
    return penisGirth * penisLength;
}

std::string Kir::getName() {
    return name;
}


void Kir::setPenises(std::vector<float> ps) {

    penises = ps;

}


std::vector<float> Kir::getPenises() {

    return penises;

}
