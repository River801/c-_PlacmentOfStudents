/*		This is a placement program for elementary  teacher for when they need to place the students into the next grade. The user inputs the students
	last name, first name and the placement score. The teacher can view the students that are entered already. If they need to be modified that can
	be done also. The user enters the command that has the program place the students into the corresponding classrooms.	*/

#include"menu.h"		// To access menu class which can access student class.
using namespace std;

int main()
{
	menu men = menu(); 
	ifstream dataFile;
	char userInput;
	char choice = 'e';


	string file = ""; // file name to open and or create a date base to use and or modify.

	while (choice != 'q')			// switched to navigate through the menu options.
	{
		choice = men.mainMenu();	// getting a valid choice inside the while loop.  

		switch (choice) 
		{
		case 'a':									// s add a student and their information.

			cout << "Let's check to make sure the student isn't in the group" << endl;

			if (men.isEmpty())
				cout << "It is empty.." << endl;
			else
				cout << "Students are already in the group!" << endl;

			cout << "continue with entering students information? y or n: ";
			cin >> userInput;
			userInput = tolower(userInput);

			while (userInput != 'y' && userInput != 'n')	// verifying user input.
			{
				system("CLS");
				cout << "*Error*\nTry Again\nContinue with entering students information ? y or n : ";
				cin >> userInput;

				userInput = tolower(userInput);
			}
			if (userInput == 'n')
			{
				cout << "\nGoing to the main menu\n";
				system("pause");						// Pausing the system to look at the screen/console.
			}
			else
				men.addStudents();
			break;

		case 'v':		
									// v View the vector.
			char YorN;
			cout << "With the new classroom assignment Y or N: ";
			cin >> YorN;
			YorN = tolower(YorN); // tolower to simplify the validation process..
			
			if (YorN == 'n')
				men.Display();
			else
				men.DisplayT();
			break;
		case 'n':											// This moves the student to the next grade. 			
			men.SearchTeacher(3);
			men.DisplayT();
			men.mainMenu();
			break;

		case 'm':										// m modify a sudent already entered infomation. 				
		{
			string name;
			cout << "Enter the last name of the student you wish to modify: ";
			cin >> name;
			men.Modify(name);
			break;
		}
		case 'u':									// d download the file and put it into the vector of students.
			
			cout << "what's the name of the file: ";
			cin >> file;
			if (men.openFileIn(dataFile, file))
			{
				cout << "File opened successfully.\n" << "Now reading data from the file.\n\n";
				men.moveContent(dataFile);			// Moving the data that is uploaded into "dataFile" the ifstream variable to the vector of Student.
				cout << "\nDone.\n";
				system("pause");					// Pausing the system to look at the screen/console.
			}
			else
			{
				cout << "File open error!" << endl;
				system("pause");					// Pausing the system to look at the screen/console.
			}
			dataFile.close();
			break;

		case 's':									// u save the information in the vector to a database (file)
			men.SaveFiles();
			break;

		case 'q':									// e to exit the program.
			break;

		default:
			cout << "\n*Error* Try again\n";
			system("Pause");					// Pausing the system to look at the screen/console.
		}
		if (choice == 'q')
			cout << "\n\nGood Bye\n";
	}
	system("pause");						// Pausing the system to look at the screen/console.
	return 0;
}