#pragma once
#include <iostream>		// To display output and read input on the screen
#include <fstream>		// Reading, writing or both Data type files
#include <string> 		// Required for the string class.
#include <vector>    	// Required for the vector type
#include <cctype>		// For character function (tolower, toupper, isupper, isprint ect.)
#include "Student.h"
class menu
{
private:
	vector<student> vStudent;		// define a vertor object.

public:
	menu();

	void moveContent(ifstream &file);
	void creatFile(ifstream &file, string name);
	void addStudents();
	void Display();
	void Modify(string);
	void DisplayT();
	void SaveFiles();									
	bool openFileIn(ifstream &file, string name);
	bool isEmpty();
	char mainMenu();
	int open_or_not();
	int studentsexpectations();
	int searchM(string name);
	void SearchTeacher(int);
	~menu();
};