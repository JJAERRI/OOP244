//Milestone3
//Name: Chaerin Yoo
//Seneca Email: cyoo10@myseneca.ca
//ID: 102998234
//Date: 2024-07-17
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include "Streamable.h"

using namespace std;

namespace seneca {
	std::ostream& operator<<(std::ostream& os, const Streamable& stream) {
		if (stream) {
			stream.write(os);
		}
		return os;
	}

	std::istream& operator>>(std::istream& is, Streamable& stream) {
		stream.read(is);
		return is;
	}
}


