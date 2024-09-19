//Milestone 2
//Name: Chaerin Yoo
//Seneca Email: cyoo10@myseneca.ca
//ID: 102998234
//Date: 2024-07-08
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SENECA_LIBAPP_H
#define SENECA_LIBAPP_H

#include "Menu.h"

namespace seneca {
    class LibApp {
        bool m_changed;
        Menu m_mainMenu;
        Menu m_exitMenu;

        bool confirm(const char* message);

        void load();
        void save();
        void search();
        void returnPub();
        void newPublication();
        void removePublication();
        void checkOutPub();

    public:
        LibApp();
        void run();
    };
}

#endif // !SENECA_LIBAPP_H
