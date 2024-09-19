//Workshop10
//Name: Chaerin Yoo
//Seneca Email: cyoo10@myseneca.ca
//ID: 102998234
//Date: 2024-07-31
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SENECA_SEARCHNLIST_H_
#define SENECA_SEARCHNLIST_H_

#include <iostream>
#include "Collection.h"

using namespace std;

namespace seneca {

	// search function template
	template <typename T1, typename T2>
	bool search(Collection<T1>& collection, const T1 array[], int size, const T2& key) {
		bool found = false;
		for (int i = 0; i < size; ++i) {
			if (array[i] == key) {
				collection.add(array[i]);
				found = true;
			}
		}
		return found;
	}

	// listArrayElements function template
	template <typename T>
	void listArrayElements(const char* title, const T array[], int size) {
		std::cout << title << std::endl;
		for (int i = 0; i < size; ++i) {
			std::cout << (i + 1) << ": " << array[i] << std::endl;
		}
	}
}


#endif // !SENECA_SEARCHNLIST_H_
