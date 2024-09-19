//Workshop4
//Name: Chaerin Yoo
//Seneca Email: cyoo10@myseneca.ca
//ID: 102998234
//Date: 2024-06-12
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace seneca {
    void Account::setEmpty() {
        m_number = -1; // Invalid account
        m_balance = 0.0;
    }
    // New account
    Account::Account() {
        m_number = 0;
        m_balance = 0.0;
    }
    Account::Account(int number, double balance) {
        setEmpty();
        if (number >= 10000 && number <= 99999 && balance > 0) {
            m_number = number;
            m_balance = balance;
        }
    }
    std::ostream& Account::display() const {
        if (*this) {
            cout << " ";
            cout << m_number;
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << m_balance;
            cout.unsetf(ios::right);
            cout << " ";
        }
        else if (~*this) {
            cout << "  NEW  |         0.00 ";
        }
        else {
            cout << "  BAD  |    ACCOUNT   ";
        }
        return cout;
    }

    // ====================== Member Operators ====================== operator 많이 나오겠다; 특히 << >> 이거

//Type Conversion Operators
    //Account::operator bool() const
    //{
    //    bool result = false;

    //    if (m_number >= 10000 && m_number <= 99999 && m_balance >= 0.0)
    //        result = true;

    //    return result;
    //}

    //이거 둘다 똑같은걸까 쨌든 밑에가 교수님꺼

    Account::operator bool() const
    {
        return m_number > 0; // it means a valid account
    }


    Account::operator int() const
    {
        return m_number;
    }

    Account::operator double() const
    {
        return m_balance;
    }

    //Unary member operator
    bool Account::operator~() const
    {
        return m_number == 0; // New account check
    }

    // Binary member operators
    Account& Account::operator+=(double value)
    {
        if (*this && value > 0) {
            m_balance += value;
        }

        return *this;
    }

    Account& Account::operator-=(double value)
    {
        if (*this && value > 0 && value <= m_balance) {
            m_balance -= value;
        }
        return *this;
    }

    Account& Account::operator>>(Account& RO) ////
    {

        if (this != &RO && *this && RO)
        {
            RO.m_balance += m_balance;
            m_balance = 0.0;
        }

        return *this;
    }

    Account& Account::operator<<(Account& RO) ///
    {
        if (this != &RO && *this && RO)
        {
            m_balance += RO.m_balance;
            RO.m_balance = 0.0;
        }

        return *this;
    }

    Account& Account::operator=(const int _acc)
    {
        if (~*this) {
            m_number = -1; //invalid state first
            if (_acc >= 10000 && _acc <= 9999) {
                m_number = _acc;
            }
        }

        return *this;
    }

    //Account& Account::operator=(Account& _move)
    //{
    //    if (this->m_number == 0 && _move.m_number > 0) {
    //        this->m_number = _move.m_number;
    //        this->m_balance = _move.m_balance;

    //        _move.m_number = 0;
    //        _move.m_balance = 0;
    //    }

    //    return *this;
    //}

    //위에 두개가 똑같은거? 밑에가 교수님꺼

    Account& Account::operator=(Account& RO)
    {
        if (~(*this) && RO) {
            m_numver=RO.m_numver;
            m_balance = RO.m_balance;
            RO.m_balance = 0.0;
            RO,m_number = 0;
        }

        return *this;
    }

    // ====================== Helper functions ====================== not part of the cl

    double operator+(const Account& _left, const Account& _right)
    {
        double sum = 0.0;

        if (_left && _right)
            sum = (double(_left) + double(_right));
        return sum;
    }

    double operator+=(double& _value, const Account& _add)
    {
        return _value += double(_add);
    }

}