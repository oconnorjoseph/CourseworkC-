// Purpose: Enables the creation of planes with a sample of members related to the actions and aspects of planes as well as vehicles as a whole
// Created by Joseph Gerard O'Connor III on 08/10/16

// CS231 B1 Programming with C++ (Summer 2 2016)
// Due Date: 08/12/16

/* Edit History:
    08/10/16: Initial version of Plane.hpp
    08/12/16: Added extensive documentation
 */

#ifndef PLANE_HPP
#define PLANE_HPP

#include <string>
#include "Vehicle.hpp"

class Plane : public Vehicle {
public:
    /**
     Initializes a Plane object with data members as the given arguments
     
     A price argument value less than -1 will throw an invalid_argument exeception with the message "Price cannot be negative unless it is set to -1 to indicate that it is unspecified"
     A productionYear argument value less than -1 will throw an invalid_argument exeception with the message "Production year cannot be negative unless it is set to -1 to indicate that it is unspecified"
     Initializes altitude data member to 0
     Initializes currentlyFlying data member to 0
     
     @param price The price of the vehicle (-1 is considered unspecified)
     @param make The make or company making the vehicle ("" is considered unspecified)
     @param make The model or version of the vehicle ("" is considered unspecified)
     @param productionYear The year the vehicle was produced (-1 is considered unspecified)
     @param wingspanFt The wingspan of the plane in feet (0 is considered unspecified)
     */
    Plane(float price = -1, std::string make = "", std::string model = "", short productionYear = -1, unsigned int wingspanFt = 0);
    
    /**
     Initializes a Plane object with data members as the given arguments
     
     A productionYear argument value less than -1 will throw an invalid_argument exeception with the message "Production year cannot be negative unless it is set to -1 to indicate that it is unspecified"
     Initializes altitude data member to 0
     Initializes currentlyFlying data member to 0
     
     @param make The make or company making the vehicle ("" is considered unspecified)
     @param make The model or version of the vehicle ("" is considered unspecified)
     @param productionYear The year the vehicle was produced (-1 is considered unspecified)
     @param wingspanFt The wingspan of the plane in feet (0 is considered unspecified)
     */
    Plane(std::string make, std::string model = "", short productionYear = -1, unsigned int wingspanFt = 0);
    
    /**
     Returns the altitude of the plane with respect to sea level in feet
     
     @return The plane's altitude above sea level (or below sea level if negative) in feet
     */
    int getAltituteFt() const;
    
    /**
     Sets of the altitude of the plane with respect to sea level to the argument value in feet
     
     @param altitudeFt The number of feet of the plane above sea level (or below sea level if negative) in feet
     */
    void setAltituteFt(int altitudeFt);
    
    /**
     Returns the wingspan of the plane in feet
     
     @return The plane's wingspan in feet
     */
    unsigned int getWingspanFt() const;
    
    /**
     Sets the wingspan of the plane to the argument value in feet
     
     @param wingspanFt the wingspan in feet to set the plane equal to
     */
    void setWingspanFt(unsigned int wingspanFt);
    
    /**
     Returns whether the plane is currently flying or not
     
     @return True if the plane is currently flying or false if the plane is not
     */
    bool isFlying() const;
    
    /**
     Sets the plane to be flying (currentlyFlying = true)
     */
    void fly();
    /**
     Sets the plane to be no longer flying (currentlyFlying = false)
     */
    void land();
    
    /**
     Prints formatted information about the plane to the command line, including:
     1) The car's make
     2) The car's model
     3) The car's production year
     4) The car's price
     5) The car's wingspan
     */
    virtual void displayWindowSticker() const;
    
    /**
     Print the steps of igniting the planes engines to spin at operating speed by first using an electric spin motor
     */
    virtual void start() const;
    
    virtual ~Plane() = default; // In case plane later becomes a base class
private:
    int altitudeFt; // The altitude of the plane in feet with respect to sea level
    unsigned int wingspanFt; // The wingspan of the plane from tip-to-tip of the wings in feet
    bool currentlyFlying; // Whether the airplane is currently in flight (true) or not (false)
};

#endif /* PLANE_HPP */
