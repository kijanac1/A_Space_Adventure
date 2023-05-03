#include <string>
#include <fstream>
#include <iostream>

using namespace std;

#include "createSaveSession.h"

string createSaveSession::getFilename() {
	return filename;
}

int createSaveSession::saveOrNew(int& crew, int& explored, int& fuel, int& foodStorage, int& homesickness, string& rocketType, string& specialArtifactFound) {  // this function runs at beginning of game to open new or saved game

	// if else statement that asks user if they want to open a saved game or new game

	cout << "Do you want to open a saved game or new game? Type 'new' or 'saved'. " << endl;
	cout << ">> ";
	cin >> newOrSaved;
	while (newOrSaved != "new" && newOrSaved != "saved") {
		// has user re-enter into they enter valid input
		cout << "You did not enter a valid response. Please re-enter." << endl;
		cout << "Do you want to open a saved game or new game? Type 'new' or 'saved'. " << endl;
		cout << ">> ";
		cin >> newOrSaved;
	}
	if (newOrSaved == "new") { // initialized values will be the default values. 
		// will ask user to name this file session
		cout << "Enter your name" << endl;
		cout << ">> ";
		cin >> filename;
		filename += ".txt";

		ofstream sessionName(filename); // this will create a saved file
		crew = 6; // starting crew members. Will need to pass to pass by reference to Planets function
		explored = 0; // total number of planets explored. 6 total planets to explore.
		fuel = 100; // starting fuel. Starts at 100
		foodStorage = 8; // 8 weeks worth of food

		/* will save our game variables to the newly created file
		these variables will be used to open the data from a previously saved session */
		sessionName << crew << " " << explored << " " << fuel << " " << foodStorage << " " << homesickness << " " << rocketType << " " << specialArtifactFound;

		cout << "A new session called " << filename << " has been created" << endl;
	}

	else if (newOrSaved == "saved") {  // initialized values will be values saved in a file
		// we will ask user for a file name

		cout << "Enter the name of your saved session" << endl;
		cout << ">> ";
		cin >> filename;
		ifstream sessionName(filename);
		sessionName >> crew >> explored >> fuel >> foodStorage >> homesickness >> rocketType >> specialArtifactFound;
		while (crew == 0 && explored == 0 && fuel == 0 && foodStorage == 0) { // checks for non-existent file name. Loops until valid saved file
			cout << "Save file name does not exist. Re-enter name." << endl << ">> " << endl;
			cin >> filename;
			ifstream sessionName(filename);
			sessionName >> crew >> explored >> fuel >> foodStorage >> homesickness >> rocketType >> specialArtifactFound;
		}
		if (rocketType == "iceRocket") {
			asciiObj.iceRocketShape();
		}
		else {
			asciiObj.fireRocketShape();
		}

	}
	cout << endl << "\033[0m\033[35m  ~ You have [" << "\033[1;35m" << crew << "\033[0m\033[35m" << "] crew members, [" << "\033[1;35m" << explored << "\033[0m\033[35m";
	cout << "] explored planets, [" << "\033[1;35m" << fuel << "\033[0m\033[35m" << "]% fuel, and [" << "\033[1;35m" << foodStorage << "\033[0m\033[35m" << "] weeks of food";
	cout << " and " << "\033[1;35m" << homesickness << "\033[0m\033[35m" << "/3 homesickness ~ \033[0m" << endl;
	cout << "Do you want to continue?" << endl;  // confirms with user if correct session has been selected
	cout << ">> ";
	cin >> response;

	if (response == "yes") {
		return 0;
	}
	else {
		// ask for game file again
		return 1;
	}

}

void createSaveSession::saveCurrentGame(int& crew, int& explored, int& fuel, int& foodStorage, int& homesickness, Rocketship& rocketObj, string& specialArtifactFound) {
	cout << endl;
	cout << "\033[31m************************* SAVE GAME ************************\033[0m" << endl;
	cout << "You want to save your current game session? Type 'yes' or 'no'. " << endl << ">> ";
	cin >> response;
	if (response == "yes") {  // current values will be saved into current filename
		ofstream sessionName(filename);
		sessionName << crew << " " << explored << " " << fuel << " " << foodStorage << " " << homesickness << " " << rocketObj.getType() << " " << specialArtifactFound;
		cout << "Your game has been saved to the " << filename << " file.";
		cout << "Type 'x' to continue." << endl << ">> ";
		cin >> response;

		while (response != "x" && response != "e" && response != "exit") { // repeats until user wants to continue
			cout << endl << ">> ";
			cin >> response;
		}
		if (response == "e" || response == "exit") {
		cout << endl << "Thank you for playing!";
		exit(0);
		}
		cout << "\033[31m************************************************************\033[0m" << endl << endl;

	}
	else {
		cout << endl;
		cout << "\033[31m************************************************************\033[0m" << endl << endl;
	}
}