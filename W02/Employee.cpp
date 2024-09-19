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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Employee.h"
#include "File.h"

using namespace std;

namespace seneca {

    int noOfEmployees;
    Employee* employees;


    void sort() {
        int i, j;
        Employee temp;
        for (i = noOfEmployees - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (employees[j].m_empNo > employees[j + 1].m_empNo) {
                    temp = employees[j];
                    employees[j] = employees[j + 1];
                    employees[j + 1] = temp;
                }
            }
        }
    }

    // TODO: Finish the implementation of the 1 arg load function which
    // reads one employee record from the file and loads it into the employee reference
    // argument
    bool load(Employee& employee) {

        bool ok = false;
        char name[128];

        /* if reading of employee number, salay and name are successful
                allocate memory to the size of the name + 1
                and keep its address in the name of the Employee Reference

                copy the name into the newly allocated memroy

                make sure the "ok" flag is set to true
           end if
        */
        if (read(employee.m_empNo) && read(employee.m_salary) && read(name)) {
            employee.m_name = new char[strlen(name) + 1];
            strcpy(employee.m_name, name);
            ok = true;

        }

        return ok;
    }

    // TODO: Finish the implementation of the 0 arg load function 
    bool load() {

        bool ok = false;
        int i = 0;

        if (openFile(DATAFILE)) {
            
             //Set the noOfEmployees to the number of recoreds in the file.

             noOfEmployees = noOfRecords();

             //dyanamically allocated an array of employees into the global
             //Employee pointer; "employees" to the size of the noOfEmployees.

             employees = new Employee[noOfEmployees];

             //In a loop load the employee records from the file into the dynamic array.

             for (int j = 0; j < noOfEmployees; j++)
             {
                 i += load(employees[j]);
             }

             //If the number of the records does not match the number of reads
             //  print the message
             //  "Error: incorrect number of records read; the data is possibly corrupted"
             // Otherwise
             //    set the ok flag to true
             // End if

             // close the file

             if (i != noOfEmployees)
             {
                 cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
             }
             else
             {
                 ok = true;
             }

             closeFile();
        }
        else
        {
            cout << "Could not open data file: " << DATAFILE << endl;
        }
        return ok;
    }
           

    // TODO: Implementation for the display functions go here
        void display(const Employee& employee) {
            cout << employee.m_empNo << ": " << employee.m_name << ", " << employee.m_salary << endl;
        }

        void display() {
            cout << "Employee Salary report, sorted by employee number" << endl;
            cout << "no- Empno, Name, Salary" << endl;
            cout << "------------------------------------------------" << endl;

            sort();

            for (int i = 0; i < noOfEmployees; i++)
            {
                cout << i + 1 << "- ";
                display(employees[i]);
            }
        }


    // TODO: Implementation for the deallocateMemory function goes here

        void deallocateMemory() {
            for (int i = 0; i < noOfEmployees; i++)
            {
                // Firstly, delete the employee naes of each struct which memory was allocated
                delete[] employees[i].m_name;
            }

            // Lastly, delete the biggest employee struct which memory was allocated
            delete[] employees;
        }

}