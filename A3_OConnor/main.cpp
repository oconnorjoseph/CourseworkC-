// Purpose: Keeps track of 6 different vehicles in an array to test the Vehicle base class and its Car, Truck, and Plane derived classes
// Created by Joseph Gerard O'Connor III on 08/10/16

// CS231 B1 Programming with C++ (Summer 2 2016)
// Due Date: 08/12/16

/* Edit History:
    08/10/16: Initial version of main.cpp
    08/10/16: Added testing of the Vehicle base class and its derived classes
    08/12/16: Adding testing of all public methods of the Vehicle, Car, Truck, and Plane classes
 */

#include <array>
#include <memory>
#include <iomanip>
#include <iostream>
#include "Vehicle.hpp"
#include "Car.hpp"
#include "Truck.hpp"
#include "Plane.hpp"

int main() {
    typedef std::unique_ptr<Vehicle> ptr;
    /*
     Variable created to test members of Truck class neither inherited from Car class nor Vehicle class
     */
    Truck* truckPtr = new Truck("Ford", "F150", -1, 25000, "", Car::FRONT_WHEEL_DRIVE, 2);
    /*
     Variable created to test members of Plane class not inherited from Vehicle class
     */
    Plane* planePtr = new Plane();
    /*
     Array of Vehicle pointers pointing to various derived classes of Vehicle
     */
    std::array<ptr, 6> vehicles {
        ptr(new Car(5600, "Jeep", "Grand Cherokee", 2006, 136497, "HZE-0339", Car::ALL_WHEEL_DRIVE, 4)),
        ptr(new Car("Subaru", "Outback", 2017, -1, "", Car::FOUR_WHEEL_DRIVE, 4)),
        ptr(truckPtr),
        ptr(new Truck(499.99, "GMC", "", 2002, 349769, "JunkRide")),
        ptr(new Plane(357000000, "Boeing", "747", 2016, 225)),
        ptr(planePtr)
    };
    
    // The following contiguous lines test public member functions of the Vehicle base class
    std::cout << "Before transformation: " << std::endl;
    std::cout << "Price: $" << std::fixed << std::setprecision(2) << vehicles[0]->getPrice() << std::endl;
    std::cout << "Make: " << vehicles[0]->getMake() << std::endl;
    std::cout << "Model: " << vehicles[0]->getModel() << std::endl;
    std::cout << "Production Year: " << vehicles[0]->getProductionYear() << std::endl;
    vehicles[0]->setPrice(435000);
    vehicles[0]->setMake("Lamborghini");
    vehicles[0]->setModel("Aventador");
    vehicles[0]->setProductionYear(2016);
    std::cout << std::endl << "After transformation: " << std::endl;
    vehicles[0]->displayWindowSticker();
    
    // The following contiguous lines test public member functions of the Car class
    std::cout << std::endl << "Before transformation: " << std::endl;
    std::cout << "Milage: " << truckPtr->getMilage() << std::endl;
    /*
     Only "." after "License Plate:" indicates getLicensePlate() returned an empty string
     */
    std::cout << "License Plate:" << truckPtr->getLicensePlate() << "." << std::endl;
    std::cout << "Drive Type: " << truckPtr->getDriveType() << std::endl; // 0 indicates Front Wheel Drive
    std::cout << "Number of doors: " << truckPtr->getNumberDoors() << std::endl;
    truckPtr->drive(75001);
    truckPtr->setLicensePlate("TYF-4334");
    truckPtr->setDriveType(Car::REAR_WHEEL_DRIVE);
    truckPtr->setNumberDoors(1);
    std::cout << std::endl << "After transformation: " << std::endl;
    truckPtr->displayWindowSticker();
    
    // The following contiguous lines test public member functions of the Truck class
    std::cout << std::endl << "Tinkering with a truck..." << std::endl;
    std::cout << std::boolalpha << "Bed is open: " << truckPtr->isBedOpen() << std::endl;
    truckPtr->openBed();
    std::cout << "Bed is open: " << truckPtr->isBedOpen() << std::endl;
    truckPtr->placeInBed("Piles of hay");
    truckPtr->placeInBed("One lonely needle");
    truckPtr->displayBedContents();
    truckPtr->removeFromBed("Piles of hay");
    truckPtr->displayBedContents();
    truckPtr->emptyBed();
    truckPtr->displayBedContents();
    truckPtr->closeBed();
    std::cout << "Bed is open: " << truckPtr->isBedOpen() << std::endl;
    
    // The following contiguous lines test public member functions of the Plane class
    std::cout << std::endl << "Before transformation:" << std::endl;
    std::cout << "Wingspan: " << planePtr->getWingspanFt() << " ft" << std::endl;
    std::cout << "Altitude: " << planePtr->getAltituteFt() << " ft" << std::endl;
    std::cout << "In flight? " << planePtr->isFlying() << std::endl;
    planePtr->setWingspanFt(30);
    planePtr->fly();
    planePtr->setAltituteFt(5280);
    std::cout << std::endl << "After transformation:" << std::endl;
    std::cout << "Wingspan: " << planePtr->getWingspanFt() << " ft" << std::endl;
    std::cout << "Altitude: " << planePtr->getAltituteFt() << " ft" << std::endl;
    std::cout << "In flight? " << planePtr->isFlying() << std::endl;
    planePtr->land();
    planePtr->setAltituteFt(-500); // Altitude set on land located below sea level
    std::cout << std::endl << "After landing plane & setting altitude:" << std::endl;
    std::cout << "Wingspan: " << planePtr->getWingspanFt() << " ft" << std::endl;
    std::cout << "Altitude: " << planePtr->getAltituteFt() << " ft" << std::endl;
    std::cout << "In flight? " << planePtr->isFlying() << std::endl << std::endl;
    
    
    for (ptr &vehicle : vehicles) {
        vehicle->displayWindowSticker();
        vehicle->start();
        std::cout << std::endl;
    }
}
