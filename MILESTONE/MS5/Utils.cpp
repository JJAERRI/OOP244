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
#include "Utils.h"

namespace seneca {
    int getIntMM(int min, int max) {
        int input = -1;
        do {
            std::cin >> input;
            if (std::cin.fail() || input < min || input > max) {
                std::cout << "Invalid Selection, try again: ";
                input = -1;
            }

            std::cin.clear();
            // clear input buffer
            char ch = 'x';
            while (ch != '\n') {
                ch = std::cin.get();
            }
        } while (std::cin.fail() || input < min || input > max);

        return input;
    }

    char getPubTypeFromNumber(int number) {
        switch (number) {
        case 1:
            return 'B';
        case 2:
            return 'P';
        default:
            return 'X';
        }
    }
}