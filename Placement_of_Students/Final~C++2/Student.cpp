#include "Student.h"	// For access to student class

using namespace std;

//default student constructor
student::student()
{ 
	Which_Teacher();
	setplacementGrade();
	setFirstName();
	setLastName();
}

// student constructor
student::student(string i, string j, int t) 
{	
	Which_Teacher(t);
	setplacementGrade(t);
	setFirstName(i);
	setLastName(j);
}
//default constructor for Placement grade
void student::setplacementGrade()
{
	placementGrade = 0;
}

// default constructor for Which_Teacher
void student::Which_Teacher()
{
	whichTeacher = 0;
}

// set whichTeacher
void student::Which_Teacher(int t)
{
	whichTeacher = t;
}

// sets Placement grade
void student::setplacementGrade(int t) 
{ 
	placementGrade = t;
}

// default constructor for first name
void student::setFirstName() 
{
	firstName = "";
}

// Default constructor for Last name
void student::setLastName() 
{
	lastName = "";
}

// Set the first name
void student::setFirstName(string i) 
{
	firstName = i;
}

// Sets the last name
void student::setLastName(string j) 
{
	lastName = j;
}

// get first, last name and the placement grade from Class Students and returns it. 
string student::display() 
{
	return " " + to_string(placementGrade) + "\t\t\t" + firstName + " " + lastName;
}
// get all student information including which teacher the student will have.
string student::displayT()
{
	return " " + to_string(placementGrade) + "\t\t  " + to_string(whichTeacher) + "\t\t\t" + firstName + " " + lastName;
}
// get all the students information to be saved, with a single space between the different data.
string student::save()
{
	return lastName + " " + firstName + " " + to_string(placementGrade) + " " + to_string(whichTeacher);
}

bool student::search(string name) 
{ 
	return (lastName == name);
}

void student::modify(int which)		// Modify the incorrect students information
{
	string name;
	int score;
	switch (which)
	{
	case 1:
		cout << student::lastName << "Enter the correct Last name: ";
		cin >> name;
		setLastName(name);
		break;
	case 2:
		cout << "Enter the correct First name: ";
		cin >> name;
		setFirstName(name);
		break;
	case 3:
		cout << "Please enter\n1 for does not meet expectations\n2 for Meets expectations\n3 exceeds expectations\n\t\t: ";
		cin >> score;
		setplacementGrade(score);
		break;
	}
}

// To check to see if a sutdent has been added to a classroom if not then assign to appropriate class room
bool student::checkTeacher_availability(int placement, int teacher)			
{
	if (placementGrade == placement && whichTeacher == 0)
	{
		Which_Teacher(teacher);
		cout << student::firstName << " " << student::lastName << " was added to teacher # " << student::whichTeacher << endl;
		return true;
	}
	else
		return false;
}