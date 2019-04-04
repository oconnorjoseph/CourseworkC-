// Purpose: Implementation file for Truck.hpp (see Truck.hpp)
// Created by Joseph Gerard O'Connor III on 08/10/16

// CS231 B1 Programming with C++ (Summer 2 2016)
// Due Date: 08/12/16

/* Edit History:
    08/10/16: Initial version of Truck.cpp
 */

#include <string>
#include <iostream>
#include "Truck.hpp"
#include "Car.hpp"

Truck::Truck(float price, std::string make, std::string model, short productionYear, int milage, std::string licensePlate, DriveType driveType, short numberDoors, bool bedOpen) : Car(price, make, model, productionYear, milage, licensePlate, driveType, numberDoors), bedOpen(bedOpen) {}

Truck::Truck(std::string make, std::string model, short productionYear, int milage, std::string licensePlate, DriveType driveType, short numberDoors, bool bedOpen) : Car(make, model, productionYear, milage, licensePlate, driveType, numberDoors), bedOpen(bedOpen) {}

bool Truck::isBedOpen() const {
    return bedOpen;
}
void Truck::openBed() {
    bedOpen = true;
}
void Truck::closeBed() {
    bedOpen = false;
}

void Truck::displayBedContents() const {
    std::cout << "Truck bed contains: ";
    if (bedContents.empty()) {
        std::cout << "Nothing";
    } else {
        std::cout << bedContents.at(0); // Allows for proper "," formatting in the list
    }
    for (int i = 1; i < bedContents.size(); ++i) {
        std::cout << ", " << bedContents.at(i);
    }
    std::cout << std::endl;
}

void Truck::placeInBed(std::string item) {
    bedContents.push_back(item);
}
void Truck::removeFromBed(std::string item) {
    for (int i = 0; i < bedContents.size(); ++i) { // Searches for item in vector and then removes it
        if (item == bedContents.at(i)) {
            bedContents.erase(bedContents.begin() + i, bedContents.begin() + i + 1);
            return;
        }
    }
    std::string exceptionMsg = "Truck bed does not contain " + item; // Gaurds against misrepresenting an items name and not actually removing it as a result
    throw std::invalid_argument(exceptionMsg);
}

bool Truck::doesBedContain(std::string item) {
    for (std::string string : bedContents) { // Searches the truck bed for the item
        if (item == string) {
            return true;
        }
    }
    return false;
}

void Truck::emptyBed() {
    bedContents.clear();
}

void Truck::displayWindowSticker() const {
    Car::displayWindowSticker();
}

void Truck::start() const {
    Car::start();
}