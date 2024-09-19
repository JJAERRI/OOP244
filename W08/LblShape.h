//Workshop8
//Name: Chaerin Yoo
//Seneca Email: cyoo10@myseneca.ca
//ID: 102998234
//Date: 2024-07-17
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef LBLSHAPE_H
#define LBLSHAPE_H

#include "Shape.h"
#include <cstring>

namespace seneca {
    class LblShape : public Shape {
        char* m_label;
    protected:
        const char* label() const;
    public:
        LblShape();
        LblShape(const char* label);
        virtual ~LblShape();
        void getSpecs(std::istream& is) override;
        LblShape(const LblShape&) = delete;
        LblShape& operator=(const LblShape&) = delete;
    };
}

#endif // LBLSHAPE_H
