// Purpose: Calculates and prints the average, standard deviation, and each number of a set of numbers the user inputs via the command line
// Created by Joseph Gerard O'Connor III on 07/25/16

// CS231 B1 Programming with C++ (Summer 2 2016)
// Due Date: 07/28/16

/* Edit History:
    07/25/16: Initial version of main.cpp
    08/01/16: Replaced functions computing average, computing standard deviation, printing average, printing standard deviation, and printing each number with the use of a VectorManager instance
    08/04/16: Added extensive commentary
 */

#include <iostream>
#include <vector>
#include "VectorManager.hpp"

/**
    Prompts the user to enter 1 to 100 floating-point numbers and then stores these numbers in the vector argument
    
    Replaces any values already in the vector argument
    Prints the error message "Item #(item's place in set) in the set is not a valid floating-point number. It is either not a number, not in decimal notation, too large, or negative and too large." and clears the vector argument if something other than a number in decimal notation is inputted, a number is too large, or a number is negative and too large
    Prints the error message "Comma detected after or within value #(value's place in set). Do not use commas within or to separate floating point numbers" and clears the vector argument if a comma is inputted between or within any of the numbers
    Prints the error message "You must enter a set of at least 1 floating point number" and clears the vector argument if no values are inputted by the user
    Prints the error message "You cannot enter a set of more than 100 floating point numbers" and clears the vector argument if too many values are inputted by the user
    
    @param vector The vector to fill with the floating-point numbers the user inputs
 
    @return True if the user provides input successfully. False if the user fails to provide proper input
 */
bool getUserInput(std::vector<float> &vector);

/**
    Prompts the user to indicate if they would like to retry by pressing the Enter key or exit the program by typing x and then enter
    
    Will exit the program if the user fails to give a valid response three times in a row
    
    @param attemps Which attempt in a row this execution of the function is to get the user to give a valid response
 */
void exitOnRequest(short attempts = 1);

int main() { // Begins program execution
    VectorManager manager;

    while(!getUserInput(manager.floatVector)) { // Gives the user the ability to retry to input data or exit the program upon failing to properly input data
        exitOnRequest();
    }
    manager.printContents();
    manager.printAverage(true);
    manager.printStandardDeviation(false, true);
}

bool getUserInput(std::vector<float> &vector) {
    if (!vector.empty()) { // Removes any previous values in the vector
        vector.clear();
    }
    float temp;
    const float MAX_FLOAT = std::numeric_limits<float>::max(),
        MIN_FLOAT = std::numeric_limits<float>::min();
    std::cout << "Please type as little as 1 to as many as 100 floating-point numbers each separated by a space. Do not use commas within or to separate floating point numbers. Press the Enter key once you have finished: ";
    std::cin.clear();
    for (short count = 0; count < 100 && std::cin.peek() != '\n'; count++) {
        if (std::cin >> temp && temp <= MAX_FLOAT && temp >= MIN_FLOAT) {
            vector.push_back(temp);
        } else if (std::cin.peek() == ',' && count > 0) { // Gaurds against misuse of commas
            std::cerr << "Comma detected after or within value #" << count << ". Do not use commas within or to separate floating point numbers." << std::endl;
            vector.clear();
            return false;
        } else { // Gaurds against mistypes or invalid input
            std::cerr << "Item #" << count + 1 << " in the set is not a valid floating-point number. It is either not a number, not in decimal notation, too large, or negative and too large." << std::endl;
            vector.clear();
            return false;
        }
    }
    if (vector.empty()) { // Guards against inputting an empty set
        std::cerr << "You must enter a set of at least 1 floating point number." << std::endl;
        return false;
    }
    if (std::cin.peek() != '\n') { // Gaurds against inputting too many numbers
        std::cerr << "You cannot enter a set of more than 100 floating point numbers." << std::endl;
        vector.clear();
        return false;
    }
    return true;
}

void exitOnRequest(short attempts) {
    std::cout << "Press the Enter key to retry. Otherwise, press x and then the Enter key to quit: ";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    char input = std::cin.get();
    switch (input) {
        case 'x':
            exit(0);
        case '\n':
            break;
        default:
            std::cout << "Invalid input. ";
            if (attempts == 3) {
                std::cout << "You failed to provide valid input 3 times in a row. Exiting the program." << std::endl;
                exit(0);
            }
            exitOnRequest(++attempts);
    }
}
