// Purpose: Demonstrates the capabilities of the Employee class
// Created by Joseph Gerard O'Connor III on 07/16/16

// CS231 B1 Programming with C++ (Summer 2 2016)
// Due Date: 07/19/16

/* Edit History:
    07/16/16: Initial version of main.cpp
    07/19/16: Tested various aspects of employee class using main()
    07/26/16: Restructured body of main() to follow the programming assignment's format
 */

#include <iostream>
#include "Employee.hpp"

using namespace std;

int main() // Begins program execute & proceeds to test the Employee class
{
    // Following two lines create two Employee objects
    Employee e1("Doe", "John", 12345.67);
    Employee e2("Jones", "Jane", 76543.21);
    
    // Following four lines display each employee object's first name, last name, & annual salary
    e1.displayInfo(Employee::ANNUAL);
    std::cout << std::endl;
    e2.displayInfo(Employee::ANNUAL);
    std::cout << std::endl;
    
    // Following two lines raise each employee's salary by ten percent
    e1.raiseSalary(10);
    e2.raiseSalary(10);
    
    // Following four lines display each employee object's first name, last name, & annual salary (after the previous ten percent raises)
    e1.displayInfo(Employee::ANNUAL);
    std::cout << std::endl;
    e2.displayInfo(Employee::ANNUAL);
    std::cout << std::endl;
    
    // Following line changes Employee e2's last name to Doe
    e2.setLastName("Doe");
    
    // Following line displays Employee e2's first & last name
    e2.displayFullName();
    std::cout << std::endl;
}
