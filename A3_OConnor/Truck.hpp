// Purpose: Enables the creation of trucks with a sample of members related to the actions and aspects of trucks, cars in general, and vehicles in general
// Created by Joseph Gerard O'Connor III on 08/10/16

// CS231 B1 Programming with C++ (Summer 2 2016)
// Due Date: 08/12/16

/* Edit History:
    08/10/16: Initial version of Truck.hpp
    08/12/16: Added extensive documentation
 */

#ifndef TRUCK_HPP
#define TRUCK_HPP

#include <string>
#include <vector>
#include "Car.hpp"

class Truck: public Car {
public:
    /**
     Initializes a Truck object with data members as the given arguments
     
     A price argument value less than -1 will throw an invalid_argument exeception with the message "Price cannot be negative unless it is set to -1 to indicate that it is unspecified"
     A productionYear argument value less than -1 will throw an invalid_argument exeception with the message "Production year cannot be negative unless it is set to -1 to indicate that it is unspecified"
     A milage argument value less than -1 will throw an invalid_argument exeception with the message "Milage must be positive or must be -1 to indicate that it is unspecified"
     Initializes the truck bed to be empty
     
     @param price The price of the truck (-1 is considered unspecified)
     @param make The make or company making the truck ("" is considered unspecified)
     @param make The model or version of the truck ("" is considered unspecified)
     @param productionYear The year the truck was produced (-1 is considered unspecified)
     @param milage The amount of miles that truck has already racked up (-1 is considered unspecified)
     @param licensePlate The numbers and alphabetic characters on the truck's license plate ("" is considered unspecified or no license plate)
     @param DriveType Drive type describing which set of tires are directly spun (UNSPECIFIED is considered UNSPECIFIED)
     @param numberDoors The number of doors on the truck (0 is considered unspecified)
     @param bedOpen True if the truck bed is open (down) or false if the truck bed is closed (up)
     */
    Truck(float price = -1, std::string make = "", std::string model = "", short productionYear = -1, int milage = -1, std::string licensePlate = "", DriveType driveType = UNSPECIFIED, short numberDoors = 0, bool bedOpen = false);
    
    /**
     Initializes a Truck object with data members as the given arguments
     
     A productionYear argument value less than -1 will throw an invalid_argument exeception with the message "Production year cannot be negative unless it is set to -1 to indicate that it is unspecified"
     A milage argument value less than -1 will throw an invalid_argument exeception with the message "Milage must be positive or must be -1 to indicate that it is unspecified"
     Sets the price of the truck as unspecified (price = -1)
     Initializes the truck bed to be empty
     
     @param make The make or company making the truck ("" is considered unspecified)
     @param make The model or version of the truck ("" is considered unspecified)
     @param productionYear The year the truck was produced (-1 is considered unspecified)
     @param milage The amount of miles that truck has already racked up (-1 is considered unspecified)
     @param licensePlate The numbers and alphabetical characters on the truck's license plate ("" is considered unspecified or no license plate)
     @param DriveType Drive type describing which set of tires are directly spun (UNSPECIFIED is considered UNSPECIFIED)
     @param numberDoors The number of doors on the truck (0 is considered unspecified)
     @param bedOpen True if the truck bed is open (down) or false if the truck bed is closed (up) (closed by default)
     */
    Truck(std::string make, std::string model = "", short productionYear = -1, int milage = -1, std::string licensePlate = "", DriveType driveType = UNSPECIFIED, short numberDoors = 0, bool bedOpen = false);
    
    /**
     Returns whether the truck bed is open (down) or closed (up)
     
     @return True if the truck bed is open (down) or false if the truck bed is closed (up)
     */
    bool isBedOpen() const;
    
    /**
     Opens (puts down) the truck bed
     */
    void openBed();
    
    /**
     Closes (puts up) the truck bed
     */
    void closeBed();
    
    /**
     Prints each of the items in the bed of the truck in a formatted list to the command line
     */
    void displayBedContents() const;
    
    /**
     Places the item argument in the bed of the truck
     
     @param item The textual description / name of the item to place in the bed of the truck
     */
    void placeInBed(std::string item);
    
    /**
     Removes the item argument from the bed of the true
     
     Throws an invalid argument exception if the item is not in the truck bed with the message "Truck bed does not contain [ITEMNAME]"
     
     @param item The textual description / name of the item to remove from the bed of the truck
     */
    void removeFromBed(std::string item);
    
    /**
     Returns whether the truck contains the item argument or not
     
     @param item The textual description / name of the item to search for in the bed of the truck
     
     @return True if the truck bed contains the item. False if the truck bed does not contain the item
     */
    bool doesBedContain(std::string item);
    
    /**
     Clears all items from the back of the truck, emptying it.
     */
    void emptyBed();
    
    /**
     Prints formatted information about the truck to the command line, including:
     1) The truck's make
     2) The truck's model
     3) The truck's production year
     4) The truck's price
     5) The truck's milage
     6) The truck's license plate
     7) The truck's drive type
     8) The truck's number of doors
     9) Whether the truck bed is open or closed
     */
    virtual void displayWindowSticker() const;
    
    /**
     Print the steps of starting the truck by key to the command line
     */
    virtual void start() const;
    
    virtual ~Truck() = default; // In case Truck later becomes a base class
private:
    bool bedOpen; // Whether the bed is open / down (true) or closed / up (false)
    std::vector<std::string> bedContents; // The names / descriptions of the items in the truck bed
};

#endif /* TRUCK_HPP */
