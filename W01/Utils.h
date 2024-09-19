#define _CRT_SECURE_NO_WARNINGS
#ifndef SENECA_UTILS_H // replace with relevant names
#define SENECA_UTILS_H

// Your header file content goes here

namespace seneca
{

    void flushkeys();
    bool ValidYesResponse(char ch);
    bool yes();
    void readCstr(char cstr[], int len);
    int readInt(int min, int max);
}
#endif 
