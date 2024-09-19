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
#include "Bill.h"

using namespace std;

namespace seneca 
{

	void Bill::setEmpty()
	{
		m_title[0] = '\0';
		m_items = nullptr; // NULL

	}

	//bool Bill::isValid() const
	//{
	//	bool result = true;
	//	if (m_title[0] != '\0' && m_items != nullptr) {//means it's true
	//		int i;
	//		//if one of them is invalid it should be false and break
	//		for (i = 0; i < m_noOfItems; i++) {
	//			if (!m_items[i].isValid()) {
	//				result = false;
	//				break;
	//			}
	//		}
	//	}
	//	return result;
	//}

	// À§¾Æ·¡°¡ ¶È°°Àº°Å ¹Ø¿¡²« ±³¼ö´Ô²¨

	bool Bill::isValid() const
	{
		bool valid =
			m_items != nullptr && m_title[0] != char(0);
		for (int i = 0; valid && i < m_noOfItems; i++) {
			valid = m_items[i].isValid();
		}
	}


	double Bill::totalTax()const
	{
		double tax = 0.0;
		for (int i = 0; i < m_noOfItems; i++)
		{
			tax += m_items[i].tax();
		}

		return tax;
	}

	double Bill::totalPrice()const
	{
		double price = 0.0;
		for (int i = 0; i < m_noOfItems; i++)
		{
			price += m_items[i].price();
		}

		return price;
	}

	void Bill::Title()const
	{
		cout << "+--------------------------------------+" << endl;
		if (isValid()) 
		{
			cout << "| ";
			cout.setf(ios::left);
			cout.width(36);
			cout << m_title << " |" << endl;
			cout.unsetf(ios::left);
		}
		else 
		{
			cout << "| Invalid Bill                         |" << endl;
		}

		cout << "+----------------------+---------+-----+" << endl;
		cout << "| Item Name            | Price   + Tax |" << endl;
		cout << "+----------------------+---------+-----+" << endl;
	}


	void Bill::footer() const
	{
		cout << "+----------------------+---------+-----+" << endl;
		if (isValid()) 
		{
			cout << "|                Total Tax: ";
			cout.width(10);
			cout.setf(ios::right);
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << totalTax() << " |" << endl;
			cout.unsetf(ios::right);
			cout.unsetf(ios::fixed);


			cout << "|              Total Price: ";
			cout.width(10);
			cout.setf(ios::right);
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << totalPrice() << " |" << endl;
			cout.unsetf(ios::right);
			cout.unsetf(ios::fixed);


			cout << "|          Total After Tax: ";
			cout.width(10);
			cout.setf(ios::right);
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << (totalTax() + totalPrice()) << " |" << endl;
			cout.unsetf(ios::right);
			cout.unsetf(ios::fixed);
		}
		else 
		{
			cout << "| Invalid Bill                         |" << endl;
		}

		cout << "+--------------------------------------+" << endl;
	}

	void Bill::init(const char* title, int noOfItems)
	{
		if (title == nullptr || noOfItems == 0) 
		{
			setEmpty();
		}
		else 
		{
			m_noOfItems = noOfItems;
			m_itemsAdded = 0;
			strncpy(m_title, title, 36);
			m_title[36] = '\0';
			m_items = new Item[noOfItems];
			int i = 0;
			for (i = 0; i < m_noOfItems; i++) 
			{
				m_items[i].setEmpty();
			}
		}
	}

	//bool Bill::add(const char* item_name, double price, bool taxed)
	//{
	//	bool result = false;

	//	if (m_itemsAdded < m_noOfItems) 
	//	{
	//		m_items[m_itemsAdded].set(item_name, price, taxed);

	//		m_itemsAdded += 1;

	//		result = true;
	//	}

	//	return result;
	//}

	// À§¾Æ·¡ ¶È°°Àº°Å ±Ùµ¥ ¹Ø¿¡²« ±³¼ö´Ô²¨

	bool Bill::add(const char* item_name, double price, bool taxed) {
		bool success = false;
		if (m_itemsAdded < m_noOfItems) {
			m_items[m_itemsAdded++].set(item_name, price, txed);
			success = true;
		}
		return success;
	}

	void Bill::display() const
	{
		Title();

		for (int i = 0; i < m_noOfItems; i++)
		{
			m_items[i].display();
		}

		footer();
	}

	void Bill::deallocate()
	{
		delete[] m_items;
		m_items = nullptr;
	}


}