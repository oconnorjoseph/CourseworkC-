// Purpose: Implementation file for Plane.hpp (see Plane.cpp)
// Created by Joseph Gerard O'Connor III on 08/10/16

// CS231 B1 Programming with C++ (Summer 2 2016)
// Due Date: 08/12/16

/* Edit History:
    08/10/16: Initial version of Plane.cpp
 */

#include <string>
#include <iostream>
#include "Plane.hpp"
#include "Vehicle.hpp"

Plane::Plane(float price, std::string make, std::string model, short productionYear, unsigned int wingspanFt) : Vehicle(price, make, model, productionYear), wingspanFt(wingspanFt), altitudeFt(0), currentlyFlying(false) {}

Plane::Plane(std::string make, std::string model, short productionYear, unsigned int wingspanFt) : Vehicle(make, model, productionYear), wingspanFt(wingspanFt), altitudeFt(0), currentlyFlying(false) {}

int Plane::getAltituteFt() const {
    return altitudeFt;
}

void Plane::setAltituteFt(int altitudeFt) {
    this->altitudeFt = altitudeFt;
}

unsigned int Plane::getWingspanFt() const {
    return wingspanFt;
}

void Plane::setWingspanFt(unsigned int wingspanFt) {
    this->wingspanFt = wingspanFt;
}

bool Plane::isFlying() const {
    return currentlyFlying;
}

void Plane::fly() {
    currentlyFlying = true;
}

void Plane::land() {
    currentlyFlying = false;
}

void Plane::displayWindowSticker() const {
    Vehicle::displayWindowSticker();
    std::cout << "Wingspan: " << (wingspanFt == 0 ? "Unspecified" : std::to_string(wingspanFt)) << std::endl;
}

void Plane::start() const {
    std::cout << "Activating electric spin motor... " << "activated." << std::endl;
    std::cout << "Electric spin motor is spinning the main shaft to ignite the engine... " << "engine ignited." << std::endl;
    std::cout << "Increasing fuel flow to increse engine spin speed... " << "25% operating speed... " << "50% operating speed... " << "75% operating speed... " << "operating speed has been reached." << std::endl;
    std::cout << "Engine is ready for flight." << std::endl;
}