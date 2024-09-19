//Workshop6
//Name: Chaerin Yoo
//Seneca Email: cyoo10@myseneca.ca
//ID: 102998234
//Date: 2024-07-03
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "TextFile.h"

using namespace std;

namespace seneca {

    // strLen: Calculate the length of the C-String in characters
    int strLen(const char* s) {
        int length = 0;
        while (s[length]) {
            length++;
        }
        return length;
    }

    // strCpy: Copies the source character string into the destination
    void strCpy(char* des, const char* src) {
        int i = 0;
        while (src[i]) {
            des[i] = src[i];
            i++;
        }
        des[i] = '\0';
    }

    // strCat: Concatenates "src" C-string to the end of "des"
    void strCat(char* des, const char* src) {
        int des_len = strLen(des);
        int counter = 0;
        while (src[counter]) {
            des[des_len] = src[counter];
            des_len++;
            counter++;
        }
        des[des_len] = '\0';
    }

    // Line class implementation
    Line::operator const char* () const {
        return m_value;
    }

    Line& Line::operator=(const char* lineValue) {
        delete[] m_value;
        m_value = new char[strLen(lineValue) + 1];
        strCpy(m_value, lineValue);
        return *this;
    }

    Line::~Line() {
        delete[] m_value;
    }

    // TextFile class implementation
    void TextFile::setEmpty() {
        delete[] m_textLines;
        m_textLines = nullptr;
        delete[] m_filename;
        m_filename = nullptr;
        m_noOfLines = 0;
    }

    void TextFile::setFilename(const char* fname, bool isCopy) {
        delete[] m_filename;
        if (fname) {
            m_filename = new char[strLen(fname) + (isCopy ? 3 : 1)];
            if (isCopy) {
                strCpy(m_filename, "C_");
                strCat(m_filename, fname);
            }
            else {
                strCpy(m_filename, fname);
            }
        }
        else {
            m_filename = nullptr;
        }
    }

    void TextFile::setNoOfLines() {
        if (m_filename) {
            ifstream file(m_filename);
            if (!file) {
                setEmpty();
                return;
            }
            m_noOfLines = 0;
            string line;
            while (getline(file, line)) {
                m_noOfLines++;
            }
            if (!file.eof() && file.fail()) {
                setEmpty();
            }
            file.close();
        }
    }

    void TextFile::loadText() {
        if (m_filename != nullptr) {
            // Make sure m_textLine is deleted before this to prevent memory leak
            if (m_textLines != nullptr) {
                delete[] m_textLines;
                m_textLines = nullptr;
            }

            // Set the number of lines
            setNoOfLines();

            // Check if there are lines to read
            if (m_noOfLines > 0) {
                // Dynamically allocate an array of Lines with the size kept in m_noOfLines
                m_textLines = new Line[m_noOfLines];

                // ifstream using the file name m_filename to read the lines of the text file
                ifstream readfile(m_filename);
                string _eachLine;
                unsigned count = 0;

                if (readfile.is_open()) {
                    // In a loop reads each line into the string object
                    while (getline(readfile, _eachLine) && count < m_noOfLines) {
                        m_textLines[count].m_value = new char[strLen(_eachLine.c_str()) + 1];
                        strCpy(m_textLines[count].m_value, _eachLine.c_str());
                        count++;
                    }
                    // Update m_noOfLines in case the file has fewer lines than expected
                    m_noOfLines = count;
                    readfile.close();
                }
                else {
                    setEmpty(); // If the file can't be opened, set to empty state
                }
            }
            else {
                setEmpty(); // If no lines are set, ensure empty state
            }
        }
    }


    void TextFile::saveAs(const char* fileName) const
    {
        // Saves the content of the TextFile under a new name
        ofstream out(fileName);

        // write them in the opened file adding a new line to the end of each line
        for (unsigned i = 0; i < m_noOfLines; i++)
            out << m_textLines[i] << endl;
    }

    TextFile::TextFile(unsigned pageSize) : m_textLines(nullptr), m_filename(nullptr), m_noOfLines(0), m_pageSize(pageSize) {}

    TextFile::TextFile(const char* filename, unsigned pageSize) : TextFile(pageSize) {
        if (filename) {
            setFilename(filename);
            loadText();
        }
    }

    //Copy Constructor
    TextFile::TextFile(const TextFile& other) : TextFile(other.m_pageSize) {
        if (other) {
            setFilename(other.m_filename, true);
            other.saveAs(m_filename); // Ensure the other file's content is saved
            loadText();
        }
    }

    //Copy Assignment
    TextFile& TextFile::operator=(const TextFile& other) {
        if (this != &other) {
            if (m_textLines != nullptr) {
                delete[] m_textLines;
                m_textLines = nullptr;
            }

            if (other.m_textLines && other.m_noOfLines > 0) {
                this->m_noOfLines = other.m_noOfLines;
                m_textLines = new Line[m_noOfLines];

                unsigned i = 0;
                while (i < m_noOfLines) {
                    m_textLines[i].m_value = new char[strLen(other.m_textLines[i].m_value) + 1];
                    strCpy(m_textLines[i].m_value, other.m_textLines[i].m_value);
                    i++;
                }

                saveAs(m_filename);
            }
        }

        return *this;
    }

    //destructor
    TextFile::~TextFile() {
        setEmpty();
    }

    unsigned TextFile::lines() const {
        return m_noOfLines;
    }

    std::ostream& TextFile::view(std::ostream& ostr) const {
        if (m_filename != nullptr && m_filename[0] != '\0') {
            ostr << m_filename << endl;

            ostr.fill('=');
            ostr.width(strLen(m_filename));
            ostr << '=' << endl;

            unsigned i = 0;

            // loops through the lines and print them one by one
            while (i < m_noOfLines && i < m_pageSize) {
                ostr << m_textLines[i] << endl;
                i++;
            }

            if (i < m_noOfLines) {
                do {
                    ostr << "Hit ENTER to continue...";
                    char x;
                    cin.get(x);

                    for (unsigned j = 0; j < m_pageSize && i < m_noOfLines; j++) {
                        ostr << m_textLines[i] << endl;
                        i++;
                    }
                } while (i < m_noOfLines);
            }
        }

        return ostr;
    }

    std::istream& TextFile::getFile(std::istream& istr) {
        string _input;
        // Receives a filename from istr to set the file name of the TextFile
        istr >> _input;

        delete[] m_filename;
        m_filename = new char[strLen(_input.c_str()) + 1];
        strCpy(m_filename, _input.c_str());
        istr.ignore(32767, '\n');

        // sets the number of lines and loads the Text
        setNoOfLines();
        loadText();

        return istr;
    }


    const char* TextFile::operator[](unsigned index) const {
        if (!*this || m_noOfLines == 0) return nullptr;
        return m_textLines[index % m_noOfLines];
    }

    TextFile::operator bool() const {
        return m_filename != nullptr && m_filename[0] != '\0';
    }

    const char* TextFile::name() const {
        return m_filename;
    }


    std::ostream& operator<<(std::ostream& ostr, const TextFile& text) {
        return text.view(ostr);
    }

    std::istream& operator>>(std::istream& istr, TextFile& text) {
        return text.getFile(istr);
    }
}
