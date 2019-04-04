// Purpose: Enables an employee's information to be contained in, manipulated within, and retrieved from a single object
// Created by Joseph Gerard O'Connor III on 07/16/16

// CS231 B1 Programming with C++ (Summer 2 2016)
// Due Date: 07/19/16

/* Edit History:
    07/16/16: Initial version of Employee.hpp
    07/19/16: Added additional constructor enabling optional specifying of firstName
    07/19/16: Added inline removeSpaces member function to replace redundant code
    07/19/16: Added SalaryType enum to expand functionality of viewing and manipulating salaries
    07/19/16: Reworded comments to improve clarity
 */

#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include <string>
#include <map>

class Employee
{
public:
    /* SalaryType is used as a parameter's type in a function header in order to:
        1) Enable the user to specify the time period of the salary argument passed into the function
        or
        2) Enable the user to specify the time period into which to format the salary before it is returned, displayed, or manipulated by the function
     The same data member is accessed or mutated regardless of which SalaryType the user chooses
     A month is chosen to consist of 173 1/3 hours
     */
    enum SalaryType {HOURLY = 3, WEEKLY = 120, BIWEEKLY = 240, MONTHLY = 520, ANNUAL = 6240}; // ? how make static
    
    /* Initializes an Employee object
     
     Sets the employee's last name as the lastName argument with the argument's spaces removed
     Sets the employee's first name as an empty string
     Sets the employee's salary data as 0
     
     @param lastName the last name to give the employee
     */
    explicit Employee(std::string lastName);
    
    /* Initializes an Employee object
     
     Sets the employee's last name as the lastName argument with the argument's spaces removed
     Sets the employee's first name as the firstName argument with the argument's spaces removed
     Sets the employee's salary data converted from the salary argument and salaryType argument
     
     @param lastName the last name to give the employee
     @param firstName the first name to give the employee (empty string by default)
     @param salary the salary the employee will recieve over the time period salaryType (0 by default)
     @param salaryType the time period over which the employee recieves the salary (MONTHLY by default)
     */
    Employee(std::string lastName, std::string firstName = "", double salary = 0, SalaryType salaryType = MONTHLY);
    
    /* Initializes an Employee object
     
     Sets the employee's last name as the lastName argument with the argument's spaces removed
     Sets the employee's first name as an empty string
     Sets the employee's salary data converted from the salary argument and salaryType argument
     
     @param lastName the last name to give the employee
     @param salary the salary the employee will recieve over the time period salaryType
     @param salaryType the time period over which the employee recieves the salary (MONTHLY by default)
     */
    Employee(std::string lastName, double salary, SalaryType salaryType = MONTHLY);
    
    /* Sets the employee's last name as the lastName argument with the argument's spaces removed
    
     Guards against passing an empty string as the lastName argument
     
     @param lastName the last name to give the employee
     */
    void setLastName(std::string lastName);
    
    /* Sets the employee's first name as the firstName argument with the argument's spaces removed
     
     @param firstName the first name to give the employee
     */
    void setFirstName(std::string firstName);
    
    /* Sets the employee's salary data converted from the salary argument and salaryType argument
     
     Guards against passsing a negative value as the salary argument
     
     @param salary the salary the employee will recieve over the time period salaryType
     @param salaryType the time period over which the employee recieves the salary (MONTHLY by default)
     */
    void setSalary(double salary, SalaryType salaryType = MONTHLY);
    
    
    /* Prints the employee's first & last name separated by a space
     
     Does not print on a new line
     Does not end the line it prints
     */
    void displayFullName() const;
    
    /* Formats & prints the employee's salary over the time period of the salaryType argument to two place values after the decimal
     
     Does not print on a new line
     Does not end the line it prints
     
     @param salaryType the time period over which the employee recieves the displayed salary (MONTHLY by default)
     */
    void displaySalary(SalaryType salaryType = MONTHLY) const;
    
    /* Formats & prints the employee's full name and salary over the time period of the salaryType argument to two place values after the decimal
     
     Does not print on a new line
     Does not end the line it prints
     
     @param salaryType the time period over which the employee recieves the displayed salary (MONTHLY by default)
     */
    void displayInfo(SalaryType salaryType = MONTHLY) const;
    
    /* Increases the employee's salary over the salaryType argument's time period
     
     @param increment the amoung to add the employee's salary over the time period salaryType
     @param salaryType the time period over which the employee recieves the salary (MONTHLY by default)
     */
    void incrementSalary(double increment, SalaryType salaryType = MONTHLY);
    
    /* Raises the employee's salary by the percent argument
     
     @param percent the percentage the employee's salary should be increased by (e.g. a value of 100 will double the employee's salary)
     */
    void raiseSalary(double percent);
    
    /* Returns the employee's last name
     
     @return the employee's last name
     */
    std::string getLastName() const;
    
    /* Returns the employee's first name
     
     @return the employee's first name
     */
    std::string getFirstName() const;
    
    /* Returns the employee's salary over the salaryType argument's time period
    
     @param salaryType the time period over which the employee recieves the salary to be returned (MONTHLY by default)
     @return the salary over the time period salaryType
     */
    double getSalary(SalaryType salaryType = MONTHLY) const;
    
private:
    // Map used to convert between SalaryType and its string equivalent
    const std::map<SalaryType, const std::string> SalaryNames {
        {HOURLY, "hourly"},
        {WEEKLY, "weekly"},
        {BIWEEKLY, "bi-weekly"},
        {MONTHLY, "monthly"},
        {ANNUAL, "annual"}
    };
    
    /* Removes all space characters from the provided str argument
     
     Will alter the string passed as the argument
     
     @param str the string that is modified directly, whereby all space character are removed
     */
    inline void removeSpaces(std::string &str);
    
    // holds the employee's last name
    std::string lastName;
    
    // holds the employee's first name
    std::string firstName;
    
    // holds a value that gives the employee's salary over 20 minutes (1/3 hour)
    double oneThirdHourlySalary;
};

#endif /* EMPLOYEE_HPP */