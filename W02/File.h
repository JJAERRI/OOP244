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

#ifndef SENECA_FILE_H_
#define SENECA_FILE_H_
namespace seneca {
	bool openFile(const char filename[]);
	void closeFile();
	int noOfRecords();
	// TODO: Declare read prototypes
  // Reads the name of the employee | Accepts as a parameter the address of an array of characters
	bool read(char* empName);

	// Reads employee number | Accepts as a parameter a reference to an integer
	bool read(int& empNumber);

	// Reads the employee salary | Acceptes as a parameter a reference to an floating point number
	// in double precision
	bool read(double& empSalary);

}
#endif // !SENECA_FILE_H_
