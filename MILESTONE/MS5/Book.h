//Milestone4
//Name: Chaerin Yoo
//Seneca Email: cyoo10@myseneca.ca
//ID: 102998234
//Date: 2024-07-26
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SENECA_BOOK_H__
#define SENECA_BOOK_H__

#include "Publication.h"
#include "Streamable.h"
#include <cstring>

namespace seneca {
    class Book : public Publication {
        char* m_author; // Pointer to dynamically hold the author's name
    public:
        // Default constructor
        Book();

        // Rule of three: Destructor
        ~Book();

        // Rule of three: Copy constructor
        Book(const Book& other);

        // Rule of three: Copy assignment operator
        Book& operator=(const Book& other);


        char type() const;
        std::ostream& write(std::ostream& os) const;
        std::istream& read(std::istream& is);

        void set(int member_id);

        operator bool() const;
    };
}

#endif // SENECA_BOOK_H__
