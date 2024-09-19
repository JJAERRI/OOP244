#define _CRT_SECURE_NO_WARNINGS
#ifndef SENECA_SHOPPINGREC_H // replace with relevant names
#define SENECA_SHOPPINGREC_H

// Your header file content goes here

namespace seneca
{
    // Constant Value
    const int MAX_QUANTITY_VALUE = 50;
    const int MAX_TITLE_LENGTH = 50;

    // Structure
    struct ShoppingRec
    {
        char m_title[MAX_TITLE_LENGTH + 1];
        int m_quantity;
        bool m_bought;
    };

    // Function Prototypes
    ShoppingRec getShoppingRec();
    void displayShoppingRec(const ShoppingRec* shp);
    void toggleBoughtFlag(ShoppingRec* rec);
    bool isShoppingRecEmpty(const ShoppingRec* shp);
}

#endif 
