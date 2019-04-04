// Purpose: Abstract class for derived classes that share commonality of being vehicles
// Created by Joseph Gerard O'Connor III on 08/10/16

// CS231 B1 Programming with C++ (Summer 2 2016)
// Due Date: 08/12/16

/* Edit History:
    08/10/16: Initial version of Vehicle.hpp
    08/12/16: Added extensive documentation
    08/12/16: Removed unnecessary standard library #include s
 */

#ifndef VEHICLE_HPP
#define VEHICLE_HPP

#include <string>

class Vehicle {
public:
    /**
     Initializes a Vehicle object with data members as the given arguments
     
     A price argument value less than -1 will throw an invalid_argument exeception with the message "Price cannot be negative unless it is set to -1 to indicate that it is unspecified"
     A productionYear argument value less than -1 will throw an invalid_argument exeception with the message "Production year cannot be negative unless it is set to -1 to indicate that it is unspecified"
     
     @param price The price of the vehicle (-1 is considered unspecified)
     @param make The make or company making the vehicle ("" is considered unspecified)
     @param make The model or version of the vehicle ("" is considered unspecified)
     @param productionYear The year the vehicle was produced (-1 is considered unspecified)
     */
    Vehicle(float price = -1, std::string make = "", std::string model = "", short productionYear = -1);
    
    /**
     Initializes a Vehicle object with data members as the given arguments
     
     A productionYear argument value less than -1 will throw an invalid_argument exeception with the message "Production year cannot be negative unless it is set to -1 to indicate that it is unspecified"
     Sets the price of the vehicle as unspecified (price = -1)
     
     @param make The make or company of the vehicle ("" is considered unspecified)
     @param make The model or version of the vehicle ("" is considered unspecified)
     @param productionYear The year the vehicle was produced (-1 is considered unspecified)
     */
    Vehicle(std::string make, std::string model = "", short productionYear = -1);
    
    /**
     Returns the vehicle's price
     
     @return The price of the vehicle (an unspecified price will be returned as -1)
     */
    float getPrice() const;
    
    /**
     Sets the vehicle's price to the argument value
     
     An argument value less than -1 will throw an invalid_argument exeception with the message "Price cannot be negative unless it is set to -1 to indicate that it is unspecified"
     
     @param price The value to which to set the vehicle (price = -1 is considered unspecified)
     */
    void setPrice(float price);
    
    /**
     Returns the vehicle's year in which it was produced
     
     @return The vehicle's production year (an unspecified production year will be returned as -1)
     */
    short getProductionYear() const;
    
    /**
     Sets the vehicle's production year to the argument value
     
     An argument value less than -1 will throw an invalid_argument exeception with the message "Production year cannot be negative unless it is set to -1 to indicate that it is unspecified"
     
     @param year The year of production  to which to set the vehicle (year = -1 is considered unspecified)
     */
    void setProductionYear(short year);
    
    /**
     Returns the make or company making the vehicle
     
     @return The make or company of the vehicle (an unspecified make will be returned as "")
     */
    std::string getMake() const;
    
    /**
     Sets the vehicle's make to the argument value
     
     @param make The name of the make to which to set the vehicle (make = "" is considered unspecified)
     */
    void setMake(std::string make);
    
    /**
     Returns the model or version of the vehicle
     
     @return The model or version of the vehicle (an unspecified make will be returned as "")
     */
    std::string getModel() const;
    
    /**
     Sets the vehicle's model to the argument value
     
     @param model The name of the model to which to set the vehicle (model = "" is considered unspecified)
     */
    void setModel(std::string model);
    
    /**
     Prints formatted information about the vehicle to the command line, including:
     1) The vehicle's make
     2) The vehicle's model
     3) The vehicle's production year
     4) The vehicle's price
     */
    virtual void displayWindowSticker() const;
    
    /**
     Function to be overriden by base classes that should print the steps of starting the base class's more-specialized vehicle to the command line
     */
    virtual void start() const = 0;
    
    /*
     Virtual destructor acts to ensure derived classes' destructors are initialized
     */
    virtual ~Vehicle() = default;
private:
    float price; // price of the vehicle
    short productionYear; // year of the vehicle's production/
    std::string make; // name of the make or company / brand of company producing the vehicle
    std::string model; // name of the version of the vehicle
};

#endif /* VEHICLE_HPP */
