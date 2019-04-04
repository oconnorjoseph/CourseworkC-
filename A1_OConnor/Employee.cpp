// Purpose: Implementation of the Employee class (gives functionality to members of & usability of Employee class)
// Created by Joseph Gerard O'Connor III on 07/16/16

// CS231 B1 Programming with C++ (Summer 2 2016)
// Due Date: 07/19/16

/* Edit History:
    07/18/16: Initial version of Employee.cpp
    07/19/16: Implemented additional constructor enabling optional specifying of firstName
    07/19/16: Implemented inline removeSpaces member function
    07/19/16: Added SalaryType enum to expand functionality of viewing and manipulating salaries
    07/19/16: Carried reworded function comments from Employee.hpp
    07/26/16: Fixed displayInfo() member function to actually utilize its salaryType parameter
 */

#include "Employee.hpp"
#include <iostream>
#include <iomanip>

/* Initializes an Employee object
 
 Sets the employee's last name as the lastName argument with the argument's spaces removed
 Sets the employee's first name as an empty string
 Sets the employee's salary data as 0
 
 @param lastName the last name to give the employee
 */
Employee::Employee(std::string lastName) :
    firstName(""), oneThirdHourlySalary(0)
{
    setLastName(lastName);
}

/* Initializes an Employee object
 
 Sets the employee's last name as the lastName argument with the argument's spaces removed
 Sets the employee's first name as the firstName argument with the argument's spaces removed
 Sets the employee's salary data converted from the salary argument and salaryType argument
 
 @param lastName the last name to give the employee
 @param firstName the first name to give the employee (empty string by default)
 @param salary the salary the employee will recieve over the time period salaryType (0 by default)
 @param salaryType the time period over which the employee recieves the salary (MONTHLY by default)
 */
Employee::Employee(std::string lastName, std::string firstName, double salary, SalaryType salaryType)
{
    setLastName(lastName);
    setFirstName(firstName);
    setSalary(salary, salaryType);
}

/* Initializes an Employee object
 
 Sets the employee's last name as the lastName argument with the argument's spaces removed
 Sets the employee's first name as an empty string
 Sets the employee's salary data converted from the salary argument and salaryType argument
 
 @param lastName the last name to give the employee
 @param salary the salary the employee will recieve over the time period salaryType
 @param salaryType the time period over which the employee recieves the salary (MONTHLY by default)
 */
Employee::Employee(std::string lastName, double salary, SalaryType salaryType) :
    firstName("")
{
    setLastName(lastName);
    setSalary(salary, salaryType);
}

/* Sets the employee's last name as the lastName argument with the argument's spaces removed
 
 Guards against passing an empty string as the lastName argument
 
 @param lastName the last name to give the employee
 */
void Employee::setLastName(std::string lastName)
{
    removeSpaces(lastName);
    if (lastName == "") // Guards against passing an empty strings to the employee's last name
    {
        throw std::invalid_argument("An Employee object cannot be initialized without a last name.\n");
    }
    this->lastName = lastName;
}

/* Sets the employee's first name as the firstName argument with the argument's spaces removed
 
 @param firstName the first name to give the employee
 */
void Employee::setFirstName(std::string firstName)
{
    removeSpaces(firstName);
    this->firstName = firstName;
}

/* Sets the employee's salary data converted from the salary argument and salaryType argument
 
 Guards against passsing a negative value as the salary argument
 
 @param salary the salary the employee will recieve over the time period salaryType
 @param salaryType the time period over which the employee recieves the salary (MONTHLY by default)
 */
void Employee::setSalary(double salary, SalaryType salaryType)
{
    if (salary < 0) // Guards against passing a negative value to the employee's monthly salary
    {
        std::string exceptionMsg = getFirstName();
        if (exceptionMsg != "")
        {
            exceptionMsg += " ";
        }
        exceptionMsg += getLastName() + " cannot have a negative salary.";
        throw std::invalid_argument(exceptionMsg);
    }
    oneThirdHourlySalary = salary / salaryType;
}

/* Prints the employee's first & last name separated by a space
 
 Does not print on a new line
 Does not end the line it prints
 */
void Employee::displayFullName() const
{
    std::cout << getFirstName() << " " << getLastName();
}

/* Formats & prints the employee's salary over the time period of the salaryType argument to two place values after the decimal
 
 Does not print on a new line
 Does not end the line it prints
 
 @param salaryType the time period over which the employee recieves the displayed salary (MONTHLY by default)
 */
void Employee::displaySalary(SalaryType salaryType) const
{
    std::cout << std::setprecision(2) << std::fixed << "$" << getSalary(salaryType) << " (" << SalaryNames.at(salaryType) << ")"; // Changes & fixes number of place values after the decimal to 2 before formatting the salary data and also providing the string description of the salaryType's time period
}

/* Formats & prints the employee's full name and salary over the time period of the salaryType argument to two place values after the decimal
 
 Does not print on a new line
 Does not end the line it prints
 
 @param salaryType the time period over which the employee recieves the displayed salary (MONTHLY by default)
 */
void Employee::displayInfo(SalaryType salaryType) const
{
    displayFullName();
    std::cout << "'s salary: ";
    displaySalary(salaryType);
}

/* Increases the employee's salary over the salaryType argument's time period
 
 @param increment the amoung to add the employee's salary over the time period salaryType
 @param salaryType the time period over which the employee recieves the salary (MONTHLY by default)
 */
void Employee::incrementSalary(double increment, SalaryType salaryType)
{
    oneThirdHourlySalary += increment / salaryType;
}

/* Raises the employee's salary by the percent argument
 
 @param percent the percentage the employee's salary should be increased by (e.g. a value of 100 will double the employee's salary)
 */
void Employee::raiseSalary(double percent)
{
    oneThirdHourlySalary *= 1 + percent / 100;
}

/* Returns the employee's last name
 
 @return the employee's last name
 */
std::string Employee::getLastName() const
{
    return lastName;
}

/* Returns the employee's first name
 
 @return the employee's first name
 */
std::string Employee::getFirstName() const
{
    return firstName;
}

/* Returns the employee's salary over the salaryType argument's time period
 
 @param salaryType the time period over which the employee recieves the salary to be returned (MONTHLY by default)
 @return the salary over the time period salaryType
 */
double Employee::getSalary(SalaryType salaryType) const
{
    return oneThirdHourlySalary * salaryType;
}

/* Removes all space characters from the provided str argument
 
 Will alter the string passed as the argument
 
 @param str the string that is modified directly, whereby all space character are removed
 */
inline void Employee::removeSpaces(std::string& str)
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end()); // Erases the set of empty characters located in the string
}
