/***********************************************************************
// OOP244 Utils Module
// File	Utils.cpp
// Version
// Date
// Author
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include <iostream> 
using namespace std;
#include <cstring>
#include "Utils.h"
namespace seneca
{
    // This function accepts an unsigned integer "value" and validates
    // Validates "value" if its a valid integer, and an integer between min and max values
    void read(unsigned int& value, unsigned int min, unsigned int max, const char* ErrorMess) {
        bool ok = false;
        char newline = 0;

        do {
            cin >> value; // cin value
            newline = cin.get(); // extract the last character 
            if (cin.fail() || newline != '\n') {
                ok = false;
                cin.clear(); // clear state of cin.fail()
                cin.ignore(1000, '\n'); // discard up to 1000 characters, or '\n' delimiter
            }
            else {
                if (value < min || value > max) { // validate the range of "value"
                    ok = false;
                }
                else {
                    ok = true;
                }
            }
        } while (!ok && cout << ErrorMess); // loops back if ok is not true, and displays "ErrorMess"
    }

}