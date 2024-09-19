#ifndef SENECA_FILE_H // replace with relevant names
#define SENECA_FILE_H

#include "ShoppingRec.h"

namespace seneca
{
    // Functions
    bool openFileForRead();
    bool openFileForOverwrite();
    void closeFile();
    bool freadShoppingRec(ShoppingRec* rec);
    void fwriteShoppintRec(const ShoppingRec* rec);
}
#endif 