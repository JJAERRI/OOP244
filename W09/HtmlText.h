//Workshop9
//Name: Chaerin Yoo
//Seneca Email: cyoo10@myseneca.ca
//ID: 102998234
//Date: 2024-07-24
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SENECA_HTMLTEXT_H__
#define SENECA_HTMLTEXT_H__

#include "Text.h"

namespace seneca {
    class HtmlText : public Text {
        char* m_title;
    public:
        HtmlText(const char* filename = nullptr, const char* title = nullptr);
        HtmlText(const HtmlText& src);
        HtmlText& operator=(const HtmlText& src);
        ~HtmlText();
        virtual void write(std::ostream& os)const override;
    };
}
#endif // !SENECA_HTMLTEXT_H__
