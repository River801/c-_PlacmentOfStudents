#include "menu.h"

student stu;

menu::menu()
{
	vStudent = vector<student>();
	stu = student();

}

void menu::moveContent(ifstream &file)
{		// Accepts an fstream reference as its argument. 
	// Uses a loop to read each name from the file and moves the data to the Vector of Student.
	string line;
	int counter = 1;
	while (file >> line)
	{
		switch (counter)
		{
		case 1:
			stu.setLastName(line);
			counter++;
			break;
		case 2:
			stu.setFirstName(line);
			counter++;
			break;
		case 3:
			stu.setplacementGrade(stoi(line));
			counter++;
			break;
		case 4:
			counter = 1;
			vStudent.push_back(stu);
			break;
		}
	}
}

void menu::creatFile(ifstream & file, string name) 
{
	file.open(name);
}

void menu::addStudents()
{
	string firstN,
		   lastN;
	int score;
	
	cout << "Enter students\nLast name: ";
	cin >> lastN;
	stu.setLastName(lastN);
	cout << "\nFirst name: ";
	cin >> firstN;

	stu.setFirstName(firstN);

	score = menu::studentsexpectations();

	stu.setplacementGrade(score);

	vStudent.push_back(stu);

	char YorN;
	cout << "Enter more students? Y or N:  ";
	cin >> YorN;
	YorN = tolower(YorN);
	while (YorN != 'y' && YorN != 'n')
	{
		system("CLS");
		cout << "**Error**\nOops try again\nEnter more students? Y or N: ";
		cin >> YorN;
	}
	if (YorN == 'y')	 //  I was using the === form javaScript duh.....
	{
		system("CLS");
		addStudents();
	}
}

bool menu::openFileIn(ifstream &file, string name)
{		//	 Accepts a reference  to an fstream object as an argument. The file is opened for input.
	file.open(name, ios::in);
	if (file.fail())
		return false;
	else
		return true;
}

bool menu::isEmpty()
{
	if (vStudent.empty())
		return true;
	else
		return false;
}

char menu::mainMenu()
{	// Menu to inform the user of the opptions. also to verify input/
	char entry;
	system("CLS"); // clearing the screen.
	cout << "Enter your choice\nTo add student(s) information\t\tenter: A\n" <<
		"To modify Sudent(s) information\t\tenter: M\n" << "To move students into next class\tenter: N\n" <<
		"To uploead the data base\t\tenter: U\nSave or To download the data base\tenter: S\n" <<
		"To view student(s) information\t\tenter: V\nTo End the program\t\t\tenter: Q" << "\nEnter your choice: ";
	cin >> entry;
	entry = tolower(entry); // tolower to simplify the validation process..
	
	return entry;
}

int menu::open_or_not()
{
	system("CLS");
	int openOrNot = 0;
	cout << "Do you with to create a file?\nEnter 0 for no\nEnter 1 for yes:\n";
	cin >> openOrNot;
	while (!openOrNot == 'y' || !openOrNot == 'n')
	{
		cout << "*Error* Please try again\nEnter Y or N only: ";
		cin >> openOrNot;
		openOrNot = tolower(openOrNot);
	}
	return openOrNot;
}

int menu::studentsexpectations()
{
	int score;
	cout << "Please enter\n1 for does not meet expectations\n2 for Meets expectations\n3 exceeds expectations\n\t\t:";
	cin >> score;
	if (score < 1 || score > 3) 
	{
		cout << "Error only 1, 2 or 3 are valid please try again\n";
		studentsexpectations();
	}
	else
		return score;
}

int menu::searchM(string name)	// Searching for the student that needs their information modified.
{
	int length = vStudent.size(),
		element = -1,
		count = 0;
	char entry;
	for (int c = 0; c < length; c++)
	{
		if (vStudent[c].search(name))
		{
			element = c;
			count += 1;
			if (count > 1)
			{
				cout << "There are multiple with that Last name\nDo you want to search by both names Y or N: ";
				cin >> entry;
				entry = tolower(entry);

				if (entry == 'n')
					cout << "This is the last element that was found with the last name of " << name;
			}
			cout << "found: " << name << " ";
		}
		if (count == length && element == -1)
			cout << "\nThe name you enter does not match any";
	}
		return element;
}

// To modify the vector of students, incase of an error in typing..
void menu::Modify(string name)
{
	int search,							// min menu option.
		element = searchM(name),		// returns the element.
		score;							// placement score;

	cout << "Which would you like to modify? Please enter\n1 for Last name\n2 for first name\n3 for placement score: ";
	cin >> search;
	while (search < 1 || search > 3)
	{
		system("cls");
		cout << "Oops error..\nPlease enter\n1 for Last name\n2 for first name\n3 for placement score: ";
		cin >> search;
	}

	if (search == 1)
	{
		cout << "Enter correct last name: ";
		cin >> name;
		vStudent[element].setLastName(name);
		
	}
	else if (search == 2)
	{
		cout << "Enter the correct first name: ";
		cin >> name;
		vStudent[element].setFirstName(name);
	}
	else if (search == 3)
	{
		system("cls");
		cout << "Enter the correct placement grade\n";
		cout << "1 for does not meet expectations\n2 for Meets expectations\n3 exceeds expectations\n\t\t:";
		cin >> score;

		while (score < 1 || score > 3)
		{
			system("cls");
			cout << "Oops error..\nPlease enter\n1 for Last name\n2 for first name\n3 for placement score: ";
			cin >> score;
		}
		vStudent[element].setplacementGrade(score);
	}
	else
		cout << "OOPs error. try again\n";
}

/* Prompt the user to enter the number of teacher to move the sudents into their next class room */
void menu::SearchTeacher(int placement)	
{
	int teacher;
		
	cout << "How many teacher are there? Because we all know that can change: ";
	cin >> teacher;
	int which_teacher = teacher,
		counter = 0,
		place = placement,
		size = vStudent.size() - 1;

	while (size >= 0)
	{
		while (counter < vStudent.size())
		{
			if (vStudent[counter].checkTeacher_availability(place, which_teacher))
			{
				which_teacher--;
				if (which_teacher == 0)
				{
					which_teacher = teacher;
				}
				size--;
			}
			else if (counter == vStudent.size() && which_teacher == 0)
			{
				if (!place == 0)
					which_teacher = teacher;

				counter = 0;
				if (place == 0)
					place = placement;
			}
			else
			{
				counter++;
				if (counter > vStudent.size() && place > 0)
					counter = 0;
			}
		}
		place--;
		counter = 0;
	}
}
void menu::Display()		// Displaying student information excluding there new class room.
{
	system("CLS");
	cout << "Displaying the sudents\nPlacment Score\t\tName:\n";

	for (int c = 0; c < vStudent.size(); c++)
		cout << vStudent[c].display() << endl;
	
	system("pause");
}

void menu::DisplayT()		// Displaying stidents information including which new class room they will be going to.
{
	system("CLS");
	cout << "Displaying the sudents\nplacment Score:\t which Teacher\t\tName:\n";

	for (int c = 0; c < vStudent.size(); c++) {
		cout << vStudent[c].displayT() << endl;
	}
	system("pause");
}

void menu::SaveFiles()		// Saving the Vector or student into a text file.
{
	ofstream file_;
	string name = "";
	cout << "Enter the text file name: ";
	cin >> name;
	file_.open(name + ".txt");

	if (file_.is_open())	{
		for (int c = 0; c < vStudent.size(); c++)	{
			file_ << vStudent[c].save() << "\n";
		}	
	}
	file_.close();
}

menu::~menu()
{
}