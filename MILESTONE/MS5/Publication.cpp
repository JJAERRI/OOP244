//Milestone3
//Name: Chaerin Yoo
//Seneca Email: cyoo10@myseneca.ca
//ID: 102998234
//Date: 2024-07-17
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include "Publication.h"
#include "Date.h"
#include "Lib.h"
#include <cstring>
#include <iostream>
#include <iomanip>
#include <string>  

namespace seneca {
    Publication::Publication() : m_title(nullptr), m_membership(0), m_libRef(-1) {
        m_shelfId[0] = '\0';
        resetDate();
    }

    Publication::~Publication() {
        delete[] m_title;
    }

    void Publication::set(int member_id)
    {
        if (member_id > 9999 || member_id == 99999)
            m_membership = member_id;
        else
            m_membership = 0;
    }

    void Publication::setRef(int value)
    {
        if (value < 0)
            m_libRef = 0;
        else
            m_libRef = value;
    }

    void Publication::resetDate() {
        m_date=Date();
    }

    char Publication::type() const {
        return 'P';
    }

    bool Publication::onLoan() const {
        return m_membership != 0;
    }

    Date Publication::checkoutDate() const {
        return m_date;
    }

    bool Publication::operator==(const char* title) const {
        if (strstr(m_title, title))
            return true;
        else
            return false;
    }

    Publication::operator const char* () const {
        return m_title;
    }

    int Publication::getRef() const {
        return m_libRef;
    }

    bool Publication::conIO(std::ios& io) const {

        if (&io == &std::cin || &io == &std::cout) {
            return true;
        }
        else {
            return false;
        }
        return &io == &std::cin || &io == &std::cout;
    }

    std::ostream& Publication::write(std::ostream& os) const
    {
        char oldFill = os.fill();
        if (conIO(os))
        {
            os.setf(std::ios::left);
            os.fill('.');

            os << "| ";
            os.width(SENECA_SHELF_ID_LEN);
            os << m_shelfId;

            os << " | ";
            os.width(SENECA_TITLE_WIDTH);
            std::string title(m_title);
            os << title.substr(0, SENECA_TITLE_WIDTH);

            //os << (m_title ? m_title : "");
            os << " | ";

            if (m_membership != 0)
                os << m_membership;
            else
                os << " N/A ";

            os << " | ";

            if (m_date.errCode() == NO_ERROR)
                os << m_date;
            else
                os << " N/A ";

            os << " |";

            os.fill(oldFill);
            os.unsetf(std::ios::left);

            return os;
        }
        else
        {
            os << type() << "\t";
            os << m_libRef;
            os << "\t";
            os << m_shelfId;
            os << "\t";
            os << (m_title ? m_title : "");
            os << "\t";
            os << m_membership;
            os << "\t";
            os << m_date;

            return os;
        }
    }

    std::istream& Publication::read(std::istream& istr)
    {
        //char title[SENECA_TITLE_WIDTH + 1]{};
        char title[256]{};
        char shelfId[SENECA_SHELF_ID_LEN + 1]{};
        Date date;
        int libRef = -1;
        int membership = 0;

        if (m_title != nullptr)
            delete[] m_title;

        m_title = nullptr;
        m_shelfId[0] = '\0';
        m_membership = 0;
        m_libRef = -1;
        resetDate();

        if (conIO(istr))
        {
            std::cout << "Shelf No: ";
            istr.getline(shelfId, SENECA_SHELF_ID_LEN + 1, '\n');

            if (strlen(shelfId) != SENECA_SHELF_ID_LEN)
            {
                istr.setstate(std::ios::failbit);
            }

            std::cout << "Title: ";
            //istr.getline(title, SENECA_TITLE_WIDTH + 1);
            istr.getline(title, 256);

            std::cout << "Date: ";
            istr >> date;
        }
        else
        {
            istr >> libRef;
            istr.ignore();

            istr.getline(shelfId, SENECA_SHELF_ID_LEN + 1, '\t');

            //istr.getline(title, SENECA_TITLE_WIDTH + 1, '\t');
            istr.getline(title, 256, '\t');

            istr >> membership;
            istr.ignore();

            istr >> date;
        }

        if (!date)
        {
            istr.setstate(std::ios::failbit);
        }

        if (istr)
        {
            //delete[] m_title;
            m_title = new char[strlen(title) + 1];
            strcpy(m_title, title);
            strcpy(m_shelfId, shelfId);
            set(membership);
            m_date = date;
            setRef(libRef);
        }
        return istr;
    }


    Publication::operator bool() const {
        return (m_title != nullptr && m_shelfId[0] != '\0');
    }

    Publication::Publication(const Publication& other) {
        m_title = nullptr;
        *this = other;
    }

    Publication& Publication::operator=(const Publication& other)
    {
        if (this != &other)
        {
            m_membership = other.m_membership;
            m_libRef = other.m_libRef;
            m_date = other.m_date;
            strncpy(m_shelfId, other.m_shelfId, SENECA_SHELF_ID_LEN);
            m_shelfId[4] = '\0';

            if (m_title != nullptr)
                delete[] m_title;

            if (other.m_title != nullptr && other.m_title[0] != '\0')
            {
                m_title = new char[strlen(other.m_title) + 1];
                strcpy(m_title, other.m_title);
            }
            else
                m_title = nullptr;
        }
        return *this;
    }

    //void Publication::set(int member_id) {
    //    // Implementation of the set method in the base class
    //}
}
