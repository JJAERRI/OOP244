//Workshop9
//Name: Chaerin Yoo
//Seneca Email: cyoo10@myseneca.ca
//ID: 102998234
//Date: 2024-07-24
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <cstring>
#include "Text.h"

using namespace std;

namespace seneca {
    int Text::getFileLength() const {
        int len = 0;
        ifstream fin(m_filename);
        while (fin) {
            fin.get();
            len += !!fin;
        }
        return len;
    }

    const char& Text::operator[](int index)const {
        return m_content[index];
    }

    Text::Text(const char* filename) : m_filename(nullptr), m_content(nullptr) {
        if (filename) {
            m_filename = new char[strlen(filename) + 1];
            strcpy(m_filename, filename);
            read();
        }
    }

    Text::Text(const Text& src) : m_filename(nullptr), m_content(nullptr) {
        if (src.m_filename) {
            m_filename = new char[strlen(src.m_filename) + 1];
            strcpy(m_filename, src.m_filename);
            read();
        }
    }

    Text& Text::operator=(const Text& src) {
        if (this != &src) {
            delete[] m_filename;
            delete[] m_content;
            m_filename = nullptr;
            m_content = nullptr;
            if (src.m_filename) {
                m_filename = new char[strlen(src.m_filename) + 1];
                strcpy(m_filename, src.m_filename);
                read();
            }
        }
        return *this;
    }

    Text::~Text() {
        delete[] m_filename;
        delete[] m_content;
    }

    void Text::read() {
        delete[] m_content;
        m_content = nullptr;
        int length = getFileLength();
        if (length > 0) {
            m_content = new char[length + 1];
            ifstream fin(m_filename);
            fin.read(m_content, length);
            m_content[length] = '\0';
        }
    }

    void Text::write(std::ostream& os)const {
        if (m_content) {
            os << m_content;
        }
    }

    std::ostream& operator<<(std::ostream& os, const Text& text) {
        text.write(os);
        return os;
    }
}
