//Workshop8
//Name: Chaerin Yoo
//Seneca Email: cyoo10@myseneca.ca
//ID: 102998234
//Date: 2024-07-17
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include "LblShape.h"

namespace seneca {
	class Rectangle : public LblShape {
		int m_width = 0;
		int m_height = 0;
	public:
		Rectangle() : LblShape() {}
		Rectangle(const char* label, int width, int height);
		operator bool() const;
		void getSpecs(std::istream& is);
		void draw(std::ostream& os) const;
	};
}
#endif
