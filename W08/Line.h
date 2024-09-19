//Workshop8
//Name: Chaerin Yoo
//Seneca Email: cyoo10@myseneca.ca
//ID: 102998234
//Date: 2024-07-17
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef LINE_H
#define LINE_H

#include "LblShape.h"

namespace seneca {
    class Line : public LblShape {
        int m_length;
    public:
        Line();
        Line(const char* label, int length);
        void draw(std::ostream& os) const override;
        void getSpecs(std::istream& is) override;
    };
}

#endif // LINE_H
