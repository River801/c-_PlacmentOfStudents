#ifndef STUDENT_H_EXISTS
#define STUDENT_H_EXISTS
#include <iostream>		// To display output and read input on the screen
#include <string> 		// Required for the string class.#include <string> 		
#include <vector>    	// Required for the vector type
using namespace std;

class student 
{
private:
	int placementGrade;
	int whichTeacher;
	string firstName;
	string lastName;

public:
	student();
	student(string, string, int);
	void setplacementGrade();
	void setplacementGrade(int);
	void setFirstName();
	void setLastName();
	void setFirstName(string);
	void setLastName(string);
	void modify(int);
	bool search(string);
	bool checkTeacher_availability(int, int);
	string display();
	string displayT();
	string save();
	void Which_Teacher();
	void Which_Teacher(int);
};
#endif 