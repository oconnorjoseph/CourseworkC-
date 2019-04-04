// Purpose: Implementation file for Vehicle.hpp (see Vehicle.hpp)
// Created by Joseph Gerard O'Connor III on 08/10/16

// CS231 B1 Programming with C++ (Summer 2 2016)
// Due Date: 08/12/16

/* Edit History:
    08/10/16: Initial version of Vehicle.cpp
    08/12/16: Fixed setModel() to actually change model instead of make
    08/12/16: Adding guarding against negative values to setProductionYear()
    08/12/16: Remove unnecessary standard library #include s
 */

#include <string>
#include <exception>
#include <iostream>
#include <iomanip>
#include "Vehicle.hpp"

Vehicle::Vehicle(float price, std::string make, std::string model, short productionYear) : make(make), model(model) {
    setPrice(price);
    setProductionYear(productionYear);
}

Vehicle::Vehicle(std::string make, std::string model, short productionYear) : price(-1), make(make), model(model) {
    setProductionYear(productionYear);
}

float Vehicle::getPrice() const {
    return price;
}

void Vehicle::setPrice(float price) {
    if (price < -1) { // Gaurds against invalid vehicle prices
        throw std::invalid_argument("Price cannot be negative unless it is set to -1 to indicate that it is unspecified");
    }
    this->price = price;
}

short Vehicle::getProductionYear() const {
    return productionYear;
}

void Vehicle::setProductionYear(short year) {
    if (year < -1) { // Gaurds against invalid vehicle production years
        throw std::invalid_argument("Production year cannot be negative unless it is set to -1 to indicate that it is unspecified");
    }
    productionYear = year;
}

std::string Vehicle::getMake() const {
    return make;
}

void Vehicle::setMake(std::string make) {
    this->make = make;
}

std::string Vehicle::getModel() const {
    return model;
}

void Vehicle::setModel(std::string model) {
    this->model = model;
}

void Vehicle::displayWindowSticker() const {
    // Use of conditional operators allows formatting unspecified values to actually display "Unspecified"
    std::cout << "Make: " << (make == "" ? "Unspecified" : make) << std::endl;
    std::cout << "Model: " << (model == "" ? "Unspecified" : model) << std::endl;
    std::cout << "Production Year: " << (productionYear == -1 ? "Unspecified" : std::to_string(productionYear)) << std::endl;
    std::cout << "Price: ";
    if (price == -1) {
        std::cout << "Unspecified";
    } else {
        std::cout << "$" << std::fixed << std::setprecision(2) << price; // Ensures 2 decimal places print
    }
    std::cout << std::endl;
}