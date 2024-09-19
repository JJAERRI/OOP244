/*/////////////////////////////////////////////////////////////////////////
                        Workshop 2 - Part 1
Full Name  : Chaerin Yoo
Student ID#: 102998234
Email      : cyoo10@myseneca.ca
Section    : NCC

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio> // equivalent of stdio.h
#include "File.h"

namespace seneca {
    FILE* fptr;
    bool openFile(const char filename[]) {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }
    int noOfRecords() {
        int noOfRecs = 0;
        char ch;
        while (fscanf(fptr, "%c", &ch) == 1) {
            noOfRecs += (ch == '\n');
        }
        rewind(fptr);
        return noOfRecs;
    }
    void closeFile() {
        if (fptr) fclose(fptr);
    }
    //TODO: read functions go here
    bool read(char* empName) {
        return fscanf(fptr, "%[^\n]\n", empName) == 1;
    }
    bool read(int& empNumber) {
       return fscanf(fptr, "%d,", &empNumber) == 1;
    }
    bool read(double& empSalary) {
       return fscanf(fptr, "%lf,", &empSalary) == 1;
    }
  
}