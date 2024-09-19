//Workshop7
//Name: Chaerin Yoo
//Seneca Email: cyoo10@myseneca.ca
//ID: 102998234
//Date: 2024-07-11
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef TRUCK_H
#define TRUCK_H

#include "MotorVehicle.h"

namespace seneca {

    class Truck : public MotorVehicle {
        double capacity;
        double cargoLoad;

    public:
        Truck(const char* plate, int yearBuilt, double capacity, const char* address);
        bool addCargo(double cargo);
        bool unloadCargo();
        std::ostream& write(std::ostream& os) const;
        std::istream& read(std::istream& in);
    };

    std::ostream& operator<<(std::ostream& os, const Truck& truck);
    std::istream& operator>>(std::istream& in, Truck& truck);

}

#endif
