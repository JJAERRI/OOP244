//Workshop8
//Name: Chaerin Yoo
//Seneca Email: cyoo10@myseneca.ca
//ID: 102998234
//Date: 2024-07-17
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include "LblShape.h"

namespace seneca {

    const char* LblShape::label() const {
        return m_label;
    }

    LblShape::LblShape() : m_label(nullptr) {}

    LblShape::LblShape(const char* label) {
        if (label) {
            m_label = new char[strlen(label) + 1];
            strcpy(m_label, label);
        }
        else {
            m_label = nullptr;
        }
    }

    LblShape::~LblShape() {
        delete[] m_label;
    }


    void LblShape::getSpecs(std::istream& is) {
        delete[] m_label;
        m_label = nullptr;

        char temp[1000];
        is.get(temp, 1000, ',');
        is.ignore(1000, ',');

        if (is) {
            m_label = new char[strlen(temp) + 1];
            strcpy(m_label, temp);
        }
    }
}
