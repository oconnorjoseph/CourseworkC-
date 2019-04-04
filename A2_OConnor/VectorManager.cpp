// Purpose: Implementation of the VectorManager class (holds a vector consisting of floating-point numbers and provides member functions concerned with the vector's data as a whole)
// Created by Joseph Gerard O'Connor III on 08/01/16

// CS231 B1 Programming with C++ (Summer 2 2016)
// Due Date: 07/28/16

/* Edit History:
    08/01/16: Initial version of VectorManager.cpp
    08/04/16: Added extensive commentary
 */
#include "VectorManager.hpp"
#include <vector>
#include <iostream>
#include <math.h>

/**
    Initializes a VectorManager object
 
    Sets the VectorManager's vector instance as a copy of the floatVector argument
 
    @param floatVector The vector containing float values to make a copy of and store inside the VectorManager object (an empty vector to contain float types by default)
 */
VectorManager::VectorManager(std::vector<float> floatVector)
    : floatVector(floatVector), average(0), standardDeviation(0) {}

/**
    Computes the average (mean) of floatVector's values and sets the average data member to this average (mean)
 
    Throws a logic error with the message "Average cannot be calculated from an empty vector" if floatVector is empty
 */
void VectorManager::computeAverage() {
    unsigned long size = floatVector.size();
    if (size == 0) { // guards against dividing by zero
        throw std::logic_error("Average cannot be calculated from an empty vector");
    } else if (size == 1) { // if floatVector only contains one value, sets average to this value
        average = floatVector.at(0);
    } else {
        double total = 0; // total is of type double to avoid overflow errors
        for (float value : floatVector) {
            total += value;
        }
        average = total / size;
    }
}

/**
    Returns the average of floatVector's values
 
    @param compute If true, calls computeAverage() before returning the value of the average data member. If false, just returns the value of average data member (false by default)
 
    @return The average of floatVector's values (average data member)
 */
float VectorManager::getAverage(bool compute) {
    if (compute) {
        computeAverage();
    }
    return average;
}

/**
    Prints a formatted line displaying the average of floatVector's values on the command-line interface
 
    @param compute If true, calls computeAverage() before displaying the average of floatVector's values. If false, just displays the value of the average data member (false by default)
 
 */
void VectorManager::printAverage(bool compute) {
    std::cout << "The set's average is: " << getAverage(compute) << std::endl;
}

/**
    Computes the standard deviation of floatVector's values and sets the standardDeviation data member to this result
 
    Throws a logic error with the message "Standard deviation cannot be calculated from an vector of size (vector's size)" if floatVector is empty or contains only one element
 
    @param computeAvg If true, calls computeAverage() before computing the standard deviation of the floatVector's values. If false, just computes the standard deviation of the floatVector's values with the value of the average data member and sets the standardDeviation data member to this result (false by default)
 */
void VectorManager::computeStandardDeviation(bool computeAvg) {
    unsigned long size = floatVector.size();
    if (size <= 1) { // Gaurds against diving by zero
        std::string exceptionMsg = "Standard deviation cannot be calculated from an vector of size " + std::to_string(size);
        throw std::logic_error(exceptionMsg);
    } else if (computeAvg) {
        computeAverage();
    } else {
        double sum = 0; // sum is of type double to avoid overflow errors
        for (float value : floatVector) {
            sum += powf(value - average, 2);
        }
        standardDeviation = powf(sum / (size - 1), 0.5);
    }
}

/**
    Returns the standard deviation of floatVector's values
 
    @param computeAvg If true, calls computeAverage() before computing and returning or just returning the value of the standardDeviation data member. If false, just computes and returns or only returns the value of the standardDeviation data member (false by default)
    @param computeSTD If true, calls computeStandardDeviation() before returning the value of the standardDeviation data member. If false, just returns the value of the standardDeviation data member (false by default)
 
    @return The standard deviation of floatVector's values (standardDeviation data member)
 */
float VectorManager::getStandardDeviation(bool computeAvg, bool computeSTD) {
    if (computeAvg) {
        computeAverage();
        computeStandardDeviation();
    } else if (computeSTD) {
        computeStandardDeviation();
    }
    return standardDeviation;
}

/**
    Prints a formatted line displaying the standard deviation of floatVector's values on the command-line interface
 
    @param computeAvg If true, calls computeAverage() before displaying the standard deviation of floatVector's values. If false, just computes and displays or only displays the value of the standardDeviation data member (false by default)
    @param computeSTD If true, calls computeStandardDeviation() before displaying the standard deviation of floatVector's values. If false, just displays the value of the standardDeviation data member (false by default)
 */
void VectorManager::printStandardDeviation(bool computeAvg, bool computeSTD) {
    std::cout << "The set's standard deviation is: " << getStandardDeviation(computeAvg, computeSTD) << std::endl;
}

/**
    Prints a formatted line displaying all of floatVector's values on the command-line interface
 */
void VectorManager::printContents() const {
    std::cout << "The set contains the following " << floatVector.size() << " values:";
    for(float value : floatVector) {
        std::cout << " " << value;
    }
    std::cout << std::endl;
}