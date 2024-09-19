//Workshop7
//Name: Chaerin Yoo
//Seneca Email: cyoo10@myseneca.ca
//ID: 102998234
//Date: 2024-07-11
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include "MotorVehicle.h"
#include <cstring>
#include <iomanip>

namespace seneca {

    MotorVehicle::MotorVehicle(const char* plate, int yearBuilt) : year(yearBuilt) {
        strncpy(licensePlate, plate, 8);
        licensePlate[8] = '\0';
        strncpy(address, "Factory", 63);
        address[63] = '\0';
    }

    void MotorVehicle::moveTo(const char* newAddress) {
        if (strcmp(address, newAddress) != 0) {
            std::cout << "|" << std::setw(8) << std::right << licensePlate << "|"
                << " |" << std::setw(20) << std::right << address << " ---> "
                << std::setw(20) << std::left << newAddress << "|" << std::endl;
            strncpy(address, newAddress, 63);
            address[63] = '\0';
        }
    }

    std::ostream& MotorVehicle::write(std::ostream& os) const {
        os << "| " << year << " | " << licensePlate << " | " << address;
        return os;
    }

    std::istream& MotorVehicle::read(std::istream& in) {
        std::cout << "Built year: ";
        in >> year;
        std::cout << "License plate: ";
        in >> licensePlate;
        std::cout << "Current location: ";
        in.ignore();
        in.getline(address, 64);
        return in;
    }

    std::ostream& operator<<(std::ostream& os, const MotorVehicle& mv) {
        return mv.write(os);
    }

    std::istream& operator>>(std::istream& in, MotorVehicle& mv) {
        return mv.read(in);
    }

}
