/***************************
OOP244 WORKSHOP3
NAME: Chaerin Yoo
ID: 102998234
Email: cyoo10@myseneca.ca
Section: NCC
Date: 05/29/2024
****************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Item.h"
using namespace std;
namespace seneca 
{
    void Item::setName(const char* name) 
    {
        //TODO :should deallocate and it's looks weird
        if (name[0] != '\0') {
            if (strlen(name) <= 20)
                strcpy(m_itemName, name);
            else {
                strncpy(m_itemName, name, 20);
                m_itemName[20] = '\0';
            }
        }
    }

    void Item::setEmpty() 
    {
        m_price = 0.0;
        m_taxed = false;
        m_itemName[0] = '\0';
        //TODO::check the init
    }

    void Item::set(const char* name, double price, bool taxed) 
    {
        if (price < 0 || name == nullptr) 
        {
            setEmpty();
        }
        else 
        {
            m_price = price;
            m_taxed = taxed;
            setName(name);
        }
    }

    void Item::display()const 
    {
        if (isValid()) 
        {
            cout << "| ";
            cout.setf(ios::left);
            cout.fill('.');
            cout.width(20);
            cout << m_itemName;
            cout.unsetf(ios::left);


            cout << " | ";
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout.precision(2);
            cout.fill(' ');
            cout.width(7);
            cout << m_price;
            cout.unsetf(ios::right);
            cout.unsetf(ios::fixed);

            cout << " | ";
            (m_taxed) ? cout << "Yes" : cout << "No ";
            cout << " |" << endl;
        }
        else 
        {
            cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
        }
    }

    bool Item::isValid()const 
    {
        bool result = true;
        if (m_price == 0.0 && !m_taxed && m_itemName[0] == '\0') {
            result = false;
        }
        return result;
    }

    double Item::price()const 
    {
        return m_price;
    }

    double Item::tax()const 
    {
        double result = 0.0;
        if (m_taxed) 
        {
            result = m_price * 0.13;
        }

        return result;
    }
}