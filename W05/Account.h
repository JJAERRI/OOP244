//Workshop4
//Name: Chaerin Yoo
//Seneca Email: cyoo10@myseneca.ca
//ID: 102998234
//Date: 2024-06-12
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SENECA_ACCOUNT_H_
#define SENECA_ACCOUNT_H_
#include <iostream>

namespace seneca {
    class Account {
        int m_number;
        double m_balance;
        void setEmpty();
    public:
        Account();
        Account(int number, double balance);
        std::ostream& display()const;

        operator bool() const;

        // Returns the account number
        operator int() const;

        // Returns the balance value
        operator double() const;

        // Unary member operator
        bool operator~() const;

        //Binary member operators
        Account& operator+=(const double _into);

        Account& operator-=(const double _draw);

        Account& operator>>(Account& _move);

        Account& operator<<(Account& _move);

        Account& operator=(const int _acc);

        Account& operator=(Account& _move);

        // ====================== Helper functions ======================
        friend double operator+(const Account& _left, const Account& _right);

        friend double operator+=(double& _value, const Account& _add);

    };


}
#endif // SENECA_ACCOUNT_H_