//Workshop8
//Name: Chaerin Yoo
//Seneca Email: cyoo10@myseneca.ca
//ID: 102998234
//Date: 2024-07-17
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include "Line.h"
#include <cstring>

namespace seneca {
    Line::Line() : LblShape(), m_length(0) {}

    Line::Line(const char* label, int length) : LblShape(label), m_length(length) {}

    void Line::draw(std::ostream& os) const {
        if (m_length > 0 && label() != nullptr) {
            os << label() << std::endl;
            for (int i = 0; i < m_length; ++i) {
                os.put('=');
            }
        }
    }

    void Line::getSpecs(std::istream& is) {
        LblShape::getSpecs(is);
        is >> m_length;
        is.ignore(1000, '\n');
    }
}
