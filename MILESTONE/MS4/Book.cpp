//Milestone4
//Name: Chaerin Yoo
//Seneca Email: cyoo10@myseneca.ca
//ID: 102998234
//Date: 2024-07-26
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#define _CRT_SECURE_NO_WARNINGS
#include "Book.h"
#include "Lib.h"
#include <iostream>
#include <iomanip>
#include <cstring>

namespace seneca {
	Book::Book() : m_author(nullptr) {}

	Book::~Book() {
		delete[] m_author;
		m_author = nullptr;
	}

	Book::Book(const Book& other) : Publication(other), m_author(nullptr) {
		*this = other;
	}

	Book& Book::operator=(const Book& other) {
		if (this != &other) {
			Publication::operator=(other);
			delete[] m_author;
			if (other.m_author != nullptr) {
				m_author = new char[strlen(other.m_author) + 1];
				strcpy(m_author, other.m_author);
			}
			else {
				m_author = nullptr;
			}
		}
		return *this;
	}

	char Book::type() const {
		return 'B';
	}

	std::ostream& Book::write(std::ostream& os) const {
		Publication::write(os);
		if (Publication::conIO(os)) {
			os << ' ';
			if (strlen(m_author) > SENECA_AUTHOR_WIDTH) {
				for (int i = 0; i < SENECA_AUTHOR_WIDTH; i++) {
					os << m_author[i];
				}
			}
			else {
				os << std::setw(SENECA_AUTHOR_WIDTH) << std::left << m_author << std::right;
			}
			os << " |";
		}
		else {
			os << '\t' << m_author;
		}
		return os;
	}

	std::istream& Book::read(std::istream& istr) {
		char author[256 + 1]{};
		Publication::read(istr);
		delete[] m_author;
		if (Publication::conIO(istr)) {
			istr.ignore(3000, '\n');
			std::cout << "Author: ";
			istr.getline(author, 256 + 1, '\n');
		}
		else {
			istr.ignore();
			istr.get(author, 256 + 1, '\n');
		}
		if (istr) {
			m_author = new char[strlen(author) + 1];
			strcpy(m_author, author);
		}
		return istr;
	}


	void Book::set(int member_id) {
		Publication::set(member_id); // Call base class set method
		Publication::resetDate(); // Reset the date to the current date
	}

	Book::operator bool() const {
		return (m_author && m_author[0] != '\0') && Publication::operator bool();
	}
}
