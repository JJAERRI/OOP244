//Milestone 2
//Name: Chaerin Yoo
//Seneca Email: cyoo10@myseneca.ca
//ID: 102998234
//Date: 2024-07-08
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SENECA_MENU_H__
#define SENECA_MENU_H__

#include <iostream>

namespace seneca {
    const unsigned int MAX_MENU_ITEMS = 20;

    class Menu; // Forward declaration of Menu class

    class MenuItem {
        char* m_content;
        MenuItem(const char* content = nullptr);
        ~MenuItem();
        MenuItem(const MenuItem&) = delete;
        MenuItem& operator=(const MenuItem&) = delete;
        operator bool() const;
        operator const char* () const;
        std::ostream& display(std::ostream& os) const;
        friend class Menu;
    };

    class Menu {
        MenuItem* m_title;
        MenuItem* m_items[MAX_MENU_ITEMS];
        unsigned int m_numItems;
    public:
        Menu(const char* title = nullptr);
        ~Menu();
        Menu(const Menu&) = delete;
        Menu& operator=(const Menu&) = delete;

        std::ostream& displayTitle(std::ostream& os) const;
        std::ostream& LunchMenu(std::ostream& os) const;
        std::ostream& displayMenu(std::ostream& os) const;
        unsigned int run() const;
        operator bool() const;
        operator int() const;
        operator unsigned int() const;
        const char* operator[](int index) const;
        Menu& operator<<(const char* menuitemContent);
        unsigned int operator~() const; // Definition of the operator~
    };

    std::ostream& operator<<(std::ostream& os, const Menu& menu);
}

#endif // SENECA_MENU_H__
