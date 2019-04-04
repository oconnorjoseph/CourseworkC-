// Purpose: Implementation file for Car.hpp (see Car.hpp)
// Created by Joseph Gerard O'Connor III on 08/10/16

// CS231 B1 Programming with C++ (Summer 2 2016)
// Due Date: 08/12/16

/* Edit History:
    08/10/16: Initial version of Car.cpp
    08/12/16: Fixed drive() to only increase milage
 */

#include <string>
#include <exception>
#include <iostream>
#include "Car.hpp"
#include "Vehicle.hpp"

Car::Car(float price, std::string make, std::string model, short productionYear, int milage, std::string licensePlate, DriveType driveType, unsigned short numberDoors) : Vehicle(price, make, model, productionYear), licensePlate(licensePlate), driveType(driveType), numberDoors(numberDoors) {
    drive(milage);
}
Car::Car(std::string make, std::string model, short productionYear, int milage, std::string licensePlate, DriveType driveType, unsigned short numberDoors) : Vehicle(make, model, productionYear), licensePlate(licensePlate), driveType(driveType), numberDoors(numberDoors) {
    drive(milage);
}

int Car::getMilage() const {
    return milage;
}
void Car::drive(int miles) {
    if (miles < -1) { // Guards against invalid milage
        throw std::invalid_argument("Milage must be positive or must be -1 to indicate that it is unspecified");
    } else if (miles == -1) { // Sets the milage to unspecified if -1 is passed as the miles argument
        milage = miles;
    } else {
        milage += miles;
    }
}

short Car::getNumberDoors() const {
    return numberDoors;
}

void Car::setNumberDoors(short numberDoors) {
    this->numberDoors = numberDoors;
}

Car::DriveType Car::getDriveType() const {
    return driveType;
}
void Car::setDriveType(DriveType driveType) {
    this->driveType = driveType;
}

std::string Car::getLicensePlate() const {
    return licensePlate;
}
void Car::setLicensePlate(std::string licensePlate) {
    this->licensePlate = licensePlate;
}
bool Car::isIdentified() const {
    return licensePlate != "";
}

void Car::displayWindowSticker() const {
    Vehicle::displayWindowSticker();
    std::cout << "Milage: " << (milage == -1 ? "Unspecified" : std::to_string(milage)) << std::endl;
    std::cout << "Number of Doors: " << (numberDoors == 0 ? "Unspecified" : std::to_string(numberDoors)) << std::endl;
    std::cout << "Drive type: " << DriveTypeNames.at(driveType) << std::endl;
    std::cout << "License Plate: " << (licensePlate == "" ? "Unspecified" : licensePlate) << std::endl;
    std::cout << "     " << (isIdentified() ? "I" : "Not i") << "dentified" << std::endl;
    
}

void Car::start() const {
    std::cout << "Placing key in ignition... " << "done." << std::endl;
    std::cout << "Turning key to ignite engine... " << "ignited." << std::endl;
    std::cout << "Engine has been started." << std::endl;
}