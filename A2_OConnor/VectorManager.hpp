// Purpose: Holds a vector consisting of floating-point numbers and provides member functions concerned with the vector's data as a whole
// Created by Joseph Gerard O'Connor III on 08/01/16

// CS231 B1 Programming with C++ (Summer 2 2016)
// Due Date: 07/28/16

/* Edit History:
    08/01/16: Initial version of VectorManager.hpp
    08/04/16: Added extensive commentary
 */

#ifndef VECTOR_MANAGER_HPP
#define VECTOR_MANAGER_HPP

#include <vector>

class VectorManager {
public:
    /**
        Vector instance containing float values the VectorManager object is centered around
     */
    std::vector<float> floatVector;
    
    /**
        Initializes a VectorManager object
     
        Sets the VectorManager's vector instance as a copy of the floatVector argument
     
        @param floatVector The vector containing float values to make a copy of and store inside the VectorManager object (an empty vector to contain float types by default)
     */
    VectorManager(std::vector<float> floatVector = std::vector<float>());
    
    /**
        Computes the average (mean) of floatVector's values and sets the average data member to this average (mean)
     
        Throws a logic error with the message "Average cannot be calculated from an empty vector" if floatVector is empty
     */
    void computeAverage();
    
    /**
        Returns the average of floatVector's values
     
        @param compute If true, calls computeAverage() before returning the value of the average data member. If false, just returns the value of average data member (false by default)
     
        @return The average of floatVector's values (average data member)
     */
    float getAverage(bool compute = false);
    
    /**
        Prints a formatted line displaying the average of floatVector's values on the command-line interface
     
        @param compute If true, calls computeAverage() before displaying the average of floatVector's values. If false, just displays the value of the average data member (false by default)
     
     */
    void printAverage(bool compute  = false);
    
    /**
        Computes the standard deviation of floatVector's values and sets the standardDeviation data member to this result
     
        Throws a logic error with the message "Standard deviation cannot be calculated from an vector of size (vector's size)" if floatVector is empty or contains only one element
     
        @param computeAvg If true, calls computeAverage() before computing the standard deviation of the floatVector's values. If false, just computes the standard deviation of the floatVector's values  with the value of the average data member and sets the standardDeviation data member to this result (false by default)
     */
    void computeStandardDeviation(bool computeAvg = false);
    
    /**
        Returns the standard deviation of floatVector's values
     
        @param computeAvg If true, calls computeAverage() before computing and returning or just returning the value of the standardDeviation data member. If false, just computes and returns or only returns the value of the standardDeviation data member (false by default)
        @param computeSTD If true, calls computeStandardDeviation() before returning the value of the standardDeviation data member. If false, just returns the value of the standardDeviation data member (false by default)
     
        @return The standard deviation of floatVector's values (standardDeviation data member)
     */
    float getStandardDeviation(bool computeAvg, bool computeSTD = false);
    
    /**
        Prints a formatted line displaying the standard deviation of floatVector's values on the command-line interface
     
        @param computeAvg If true, calls computeAverage() before displaying the standard deviation of floatVector's values. If false, just computes and displays or only displays the value of the standardDeviation data member (false by default)
        @param computeSTD If true, calls computeStandardDeviation() before displaying the standard deviation of floatVector's values. If false, just displays the value of the standardDeviation data member (false by default)
     */
    void printStandardDeviation(bool computeAvg, bool computeSTD = false);
    
    /**
        Prints a formatted line displaying all of floatVector's values on the command-line interface
     */
    void printContents() const;
    
private:
    // Holds the latest average calculated from floatVector's values (initialized to 0)
    float average;
    // Holds the lastest standard deviation calculated from floatVector's values (initialized to 0)
    float standardDeviation;
};

#endif /* VECTOR_MANAGER_HPP */
