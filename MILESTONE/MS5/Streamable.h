//Milestone3
//Name: Chaerin Yoo
//Seneca Email: cyoo10@myseneca.ca
//ID: 102998234
//Date: 2024-07-17
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SENECA_STREAMABLE_H__
#define SENECA_STREAMABLE_H__
#include <iostream>

namespace seneca
{
	class Streamable {
	public:
		virtual std::ostream& write(std::ostream& os) const = 0;
		virtual std::istream& read(std::istream& is) = 0;
		virtual bool conIO(std::ios& io) const = 0;
		virtual operator bool() const = 0;
		virtual ~Streamable() {}
		friend std::ostream& operator<<(std::ostream& os, const Streamable& stream);
		friend std::istream& operator>>(std::istream& is, Streamable& stream);
	};
}





#endif // SENECA_STREAMABLE_H__
