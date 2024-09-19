//Workshop9
//Name: Chaerin Yoo
//Seneca Email: cyoo10@myseneca.ca
//ID: 102998234
//Date: 2024-07-24
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SENECA_TEXT_H__
#define SENECA_TEXT_H__

#include <iostream>

namespace seneca {
    class Text {
    protected:
        char* m_filename;
        char* m_content;
        int getFileLength()const;
        const char& operator[](int index)const;
    public:
        Text(const char* filename = nullptr);
        Text(const Text& src);
        Text& operator=(const Text& src);
        ~Text();
        void read();
        virtual void write(std::ostream& os)const;
    };
    std::ostream& operator<<(std::ostream& os, const Text& text);
}
#endif // !SENECA_TEXT_H__
