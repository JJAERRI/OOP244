//Milestone 2
//Name: Chaerin Yoo
//Seneca Email: cyoo10@myseneca.ca
//ID: 102998234
//Date: 2024-07-08
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Menu.h"
#include "Utils.h"

namespace seneca {

    MenuItem::MenuItem(const char* content) {
        m_content = new char[strlen(content) + 1];
        strcpy(m_content, content);
    }


    MenuItem::~MenuItem() {
        delete[] m_content;
    }

    MenuItem::operator bool() const {
        return m_content != nullptr;
    }

    MenuItem::operator const char* () const {
        return m_content;
    }

    std::ostream& MenuItem::display(std::ostream& os) const {
        if (*this) {
            os << m_content;
        }
        return os;
    }

    Menu::Menu(const char* title) : m_numItems(0) {
        if (title) {
            m_title = new MenuItem(title);
        }
        else {
            m_title = nullptr;
        }
        for (unsigned int i = 0; i < MAX_MENU_ITEMS; ++i) {
            m_items[i] = nullptr;
        }
    }

    Menu::~Menu() {
        delete m_title;
        for (unsigned int i = 0; i < m_numItems; ++i) {
            delete m_items[i];
        }
    }

    std::ostream& Menu::displayTitle(std::ostream& os) const {
        if (m_title) {
            m_title->display(os);
            os << "";
        }
        return os;
    }

    std::ostream& Menu::LunchMenu(std::ostream& os) const {
        if (m_title) {
            m_title->display(os);
            os << ":" << std::endl;
        }
        return os;
    }

    std::ostream& Menu::displayMenu(std::ostream& os) const {
        displayTitle(os);
        for (unsigned int i = 0; i < m_numItems; ++i) {
            os << " " << i + 1 << "- ";
            m_items[i]->display(os);
            os << std::endl;
        }
        os << " 0- Exit" << std::endl;
        os << "> ";
        return os;
    }


    unsigned int Menu::run() const {
        unsigned int selection;
        bool validSelection = false;
        do {
            displayMenu(std::cout);
            seneca::read(selection, 0U, m_numItems, "Invalid Selection, try again: ");
            validSelection = selection <= m_numItems;
        } while (!validSelection);
        return selection;
    }

    Menu::operator bool() const {
        return m_numItems > 0;
    }

    Menu::operator int() const {
        return static_cast<int>(m_numItems);
    }

    Menu::operator unsigned int() const {
        return m_numItems;
    }

    const char* Menu::operator[](int index) const {
        if (index >= 0) {
            return *m_items[index % m_numItems];
        }
        return nullptr;
    }

    Menu& Menu::operator<<(const char* menuitemContent) {
        m_items[m_numItems++] = new MenuItem(menuitemContent);
        return *this;
    }

    unsigned int Menu::operator~() const { // Implement the operator~
        return run();
    }

    std::ostream& operator<<(std::ostream& os, const Menu& menu) {
        return menu.displayTitle(os);
    }
}
