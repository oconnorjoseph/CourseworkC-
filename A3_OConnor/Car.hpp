// Purpose: Enables the creation of cars with a sample of members related to the actions and aspects of cars as well as cars as a whole
// Created by Joseph Gerard O'Connor III on 08/10/16

// CS231 B1 Programming with C++ (Summer 2 2016)
// Due Date: 08/12/16

/* Edit History:
    08/10/16: Initial version of Car.hpp
    08/12/16: Added extensive documentation
 */

#ifndef CAR_HPP
#define CAR_HPP

#include <string>
#include <map>
#include "Vehicle.hpp"

class Car: public Vehicle {
public:
    /*
     Different drive types of which a car could have one (FWD, RWD, AWD, 4WD, or unspecified)
     */
    enum DriveType {FRONT_WHEEL_DRIVE, REAR_WHEEL_DRIVE, ALL_WHEEL_DRIVE, FOUR_WHEEL_DRIVE, UNSPECIFIED};
    
    /**
     Initializes a Car object with data members as the given arguments
     
     A price argument value less than -1 will throw an invalid_argument exeception with the message "Price cannot be negative unless it is set to -1 to indicate that it is unspecified"
     A productionYear argument value less than -1 will throw an invalid_argument exeception with the message "Production year cannot be negative unless it is set to -1 to indicate that it is unspecified"
     A milage argument value less than -1 will throw an invalid_argument exeception with the message "Milage must be positive or must be -1 to indicate that it is unspecified"
     
     @param price The price of the car (-1 is considered unspecified)
     @param make The make or company making the car ("" is considered unspecified)
     @param make The model or version of the car ("" is considered unspecified)
     @param productionYear The year the car was produced (-1 is considered unspecified)
     @param milage The amount of miles that car has already racked up (-1 is considered unspecified)
     @param licensePlate The numbers and alphabetic characters on the car's license plate ("" is considered unspecified or no license plate)
     @param DriveType Drive type describing which set of tires are directly spun (UNSPECIFIED is considered UNSPECIFIED)
     @param numberDoors The number of doors on the car (0 is considered unspecified)
     */
    Car(float price = -1, std::string make = "", std::string model = "", short productionYear = -1, int milage = -1, std::string licensePlate = "", DriveType driveType = UNSPECIFIED, unsigned short numberDoors = 0);
    
    /**
     Initializes a Car object with data members as the given arguments
     
     A productionYear argument value less than -1 will throw an invalid_argument exeception with the message "Production year cannot be negative unless it is set to -1 to indicate that it is unspecified"
     A milage argument value less than -1 will throw an invalid_argument exeception with the message "Milage must be positive or must be -1 to indicate that it is unspecified"
     Sets the price of the car as unspecified (price = -1)
     
     @param make The make or company making the car ("" is considered unspecified)
     @param make The model or version of the car ("" is considered unspecified)
     @param productionYear The year the car was produced (-1 is considered unspecified)
     @param milage The amount of miles that car has already racked up (-1 is considered unspecified)
     @param licensePlate The numbers and alphabetical characters on the car's license plate ("" is considered unspecified or no license plate)
     @param DriveType Drive type describing which set of tires are directly spun (UNSPECIFIED is considered UNSPECIFIED)
     @param numberDoors The number of doors on the car (0 is considered unspecified)
     */
    Car(std::string make, std::string model = "", short productionYear = -1, int milage = -1, std::string licensePlate = "", DriveType driveType = UNSPECIFIED, unsigned short numberDoors = 0);
    
    /**
     Returns the milage on the car
     
     @return The car's milage (an unspecified milage will be returned as -1)
     */
    int getMilage() const;
    
    /**
     Increases the car's milage by the miles argument's value
     
     An argument value less than -1 will throw an invalid_argument exeception with the message "Milage must be positive or must be -1 to indicate that it is unspecified"
     
     @param miles number of miles to tack onto the car
     */
    void drive(int miles);
    
    /**
     Returns the number of doors on the car
     
     @return The car's total number of doors (an unspecified number of doors will be returned as -1)
     */
    short getNumberDoors() const;
    
    /**
     Sets the car's number of doors to the argument value
     
     @param numberDoors The number of doors the car should have (numberDoors = 0 is considered unspecified)
     */
    void setNumberDoors(short numberDoors);
    
    /**
     Returns the car's drive type (FWD, RWD, AWD, 4WD, or unspecified)
     
     @return The price of the car (an unspecified price will be returned as -1)
     */
    DriveType getDriveType() const;
    
    /**
     Sets the car's drive type to the argument
     
     @param driveType the DriveType enum of which drive type the car should have (driveType = UNSPECIFIED is considered unspecified)
     */
    void setDriveType(DriveType driveType);
    
    /**
     Returns the line of numbers and alphabetic characters on the car's license plate
     
     @return The numbers and alphabetic characters on the cars license plate (no license plate / unspecified license plate will be returned as -1)
     */
    std::string getLicensePlate() const;
    
    /**
     Sets the car's license plate's character combination to the argument value
     
     @param licensePlate The ordered numeric and alphabetic characters the license plate should have (licensePlate = "" is considered unspecified)
     */
    void setLicensePlate(std::string licensePlate);
    
    /**
     Returns whether the car has a license plate (true) or not (false)
     
     @return True if the car has a license plate, otherwise false
     */
    bool isIdentified() const;
    
    /**
     Prints formatted information about the car to the command line, including:
     1) The car's make
     2) The car's model
     3) The car's production year
     4) The car's price
     5) The car's milage
     6) The car's license plate
     7) The car's drive type
     8) The car's number of doors
     */
    virtual void displayWindowSticker() const;
    
    /**
     Print the steps of starting the car by key to the command line
     */
    virtual void start() const;
    
    /*
     Virtual destructor acts to ensure derived classes' destructors are initialized
     */
    virtual ~Car() = default; 
private:
    int milage; // number of miles the car has traveled in its lifetime
    unsigned short numberDoors; // number of doors on the car
    DriveType driveType; // The car's drive type (FWD, RWD, AWD, 4WD, or unspecified)
    std::string licensePlate; // The line of numeric and alaphabetic characters on the car's license plate
    
    // Maps each of the DriveTypes to its textual counterpart
    const std::map<DriveType, const std::string> DriveTypeNames {
        {FRONT_WHEEL_DRIVE, "Front Wheel Drive"},
        {REAR_WHEEL_DRIVE, "Rear Wheel Drive"},
        {ALL_WHEEL_DRIVE, "All Wheel Drive"},
        {FOUR_WHEEL_DRIVE, "Four Wheel Drive"},
        {UNSPECIFIED, "Unspecified"}
    };
};

#endif /* CAR_HPP */
