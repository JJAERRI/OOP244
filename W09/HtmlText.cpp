//Workshop9
//Name: Chaerin Yoo
//Seneca Email: cyoo10@myseneca.ca
//ID: 102998234
//Date: 2024-07-24
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "HtmlText.h"

using namespace std;

namespace seneca {

    HtmlText::HtmlText(const char* filename, const char* title) : Text(filename), m_title(nullptr) {
        if (title) {
            m_title = new char[strlen(title) + 1];
            strcpy(m_title, title);
        }
    }

    HtmlText::HtmlText(const HtmlText& src) : Text(src), m_title(nullptr) {
        if (src.m_title) {
            m_title = new char[strlen(src.m_title) + 1];
            strcpy(m_title, src.m_title);
        }
    }

    HtmlText& HtmlText::operator=(const HtmlText& src) {
        if (this != &src) {
            Text::operator=(src);
            delete[] m_title;
            m_title = nullptr;
            if (src.m_title) {
                m_title = new char[strlen(src.m_title) + 1];
                strcpy(m_title, src.m_title);
            }
        }
        return *this;
    }

    HtmlText::~HtmlText() {
        delete[] m_title;
    }

    void HtmlText::write(std::ostream& os)const {
        bool MS = false;
        os << "<html><head><title>";
        if (m_title) {
            os << m_title;
        }
        else {
            os << "No Title";
        }
        os << "</title></head>\n<body>\n";
        if (m_title) {
            os << "<h1>" << m_title << "</h1>\n";
        }
        for (int i = 0; m_content[i]; i++) {
            switch (m_content[i]) {
            case ' ':
                if (MS) {
                    os << "&nbsp;";
                }
                else {
                    MS = true;
                    os << ' ';
                }
                break;
            case '<':
                os << "&lt;";
                MS = false;
                break;
            case '>':
                os << "&gt;";
                MS = false;
                break;
            case '\n':
                os << "<br />\n";
                MS = false;
                break;
            default:
                MS = false;
                os << m_content[i];
                break;
            }
        }
        os << "</body>\n</html>";
    }
}
