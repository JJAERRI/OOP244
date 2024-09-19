/*/////////////////////////////////////////////////////////////////////////
                        Workshop 2 - Part 1
Full Name  : Chaerin Yoo
Student ID#: 102998234
Email      : cyoo10@myseneca.ca
Section    : NCC

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#ifndef SENECA_EMPLOYEE_H_
#define SENECA_EMPLOYEE_H_

#define DATAFILE "employees.csv"
namespace seneca {
    struct Employee {
        char* m_name; //Resource p ointer for dynamic allocation
        int m_empNo;  // static
        double m_salary;  // static
    };
    //sorts the dynamic array of employees based on the GPA of the employees.
    void sort();
    // loads a employee structue with its values from the file
    bool load(Employee& employee);
    // allocates the dyanmic array of employees and loads all the file
    // recoreds into the array
    bool load();

    // TODO: Declare the prototype for the display function that
    // displays a employee record on the screen:
    void display(const Employee& employee);

    // TODO: Declare the prototype for the display function that 
    // first sorts the employees then displays all the employees on the screen
    void display();

    // TODO: Declare the prototype for the deallocateMemory function that
    // first will deallocate all the names in the employee elements
    // then it will deallocate the employee array 
    void deallocateMemory();
}
#endif // SENECA_EMPLOYEE_H_