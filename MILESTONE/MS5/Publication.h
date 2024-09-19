//Milestone3
//Name: Chaerin Yoo
//Seneca Email: cyoo10@myseneca.ca
//ID: 102998234
//Date: 2024-07-17
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SENECA_PUBLICATION_H__
#define SENECA_PUBLICATION_H__
#include "Streamable.h"
#include "Date.h"
#include "Lib.h"
#include <iostream>
#include <cstring>

namespace seneca {
    class Publication : public Streamable {
    private:
        char* m_title;
        char m_shelfId[SENECA_SHELF_ID_LEN + 1];
        int m_membership;
        int m_libRef;
        Date m_date;
    public:
        Publication();
        virtual ~Publication();
        virtual void set(int member_id);
        void setRef(int value);
        void resetDate();
        virtual char type() const;
        bool onLoan() const;
        Date checkoutDate() const;
        bool operator==(const char* title) const;
        operator const char* () const;
        int getRef() const;

        bool conIO(std::ios& io) const override;
        std::ostream& write(std::ostream& os) const override;
        std::istream& read(std::istream& is) override;
        operator bool() const override;

        Publication(const Publication& other);
        Publication& operator=(const Publication& other);

        //virtual void set(int member_id); // Declaration in the base class
    };
}

#endif // SENECA_PUBLICATION_H__
