#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <fstream>
#include "createSaveSession.h"
#include "Planets.h"
#include "asciiArt.h"
#include "Rocketship.h"

using namespace std;

int main() {


	/****************************************************************************** initializing values to start game */
	asciiArt asciiObj; // calls the calls which holds function that draws ascii pictures
	asciiObj.gameHeader(); // calls for main game header text at top of program

	// default game variables when starting a new game
	srand(time(0));
	int totalCrew = 0;
	int planetsExplored = 0;
	int fuel = 0;
	int foodStorage = 0;
	int homesickness = 0;
	string rocketType;
	string response = "";
	string specialArtifactFound = "true";

	asciiObj.mainMenu(); // calls ascii main menu

	createSaveSession saveObj;
	saveObj.saveOrNew(totalCrew, planetsExplored, fuel, foodStorage, homesickness, rocketType, specialArtifactFound); // calls to create a new save file or load old file


	// this conditional is for selection of rocket.
	Rocketship playerRocket; // creates rocketship obj
	if (totalCrew == 6 && planetsExplored == 0 && fuel == 100 && foodStorage == 8) { // checks if we have a new game file, then will ask for rocket type
		asciiObj.iceRocketShape();
		cout << "\033[36m                     ICE ROCKETSHIP \033[0m" << endl;
		asciiObj.fireRocketShape();
		cout << "\033[31m                    FIRE ROCKETSHIP \033[0m " << endl;
		playerRocket.chooseRocketship(); // calls for player to select ship type
	}
	else { // if choosing saved game, loads previous type selected for rocket

		playerRocket.setType(rocketType);
	}




	cout << "\033[35m~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\033[0m" << endl << endl;

	if (totalCrew == 6 && planetsExplored == 0 && fuel == 100 && foodStorage == 8) { // again checking if player is beginning new game
		cout << "You have always dream about being able to reach the stars, since you were a child. And now technology has finally advanced enough ";
		cout << "to where you can reach beyond the stars. You have been specially chosen in a lottery to man the first rocketship missioned to reach ";
		cout << "the end of the universe. After 2 years of intense training you are moving forward as the captain of this mission.." << endl << endl;

		asciiObj.leavingEarth();

		cout << "Enter 'x' to continue" << endl;
		cout << ">> ";
		cin >> response;

	}

	// if player survives first planet, moves on to the next planet..
	// game loops until either 
	while (planetsExplored != 6 && fuel > 0 && foodStorage > 0 && totalCrew > 0) {
		string userResponse = "";
		string planetName = "";

		Planets* newPlanet = new Planets();  // creates Planets object
		newPlanet->createPlanet(); // creates the type of planet player has found

		// approaching a new planet
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clears error when reading planetName
		cout << "What would you like to name your newly discovered planet?";
		cout << endl << "\033[35m>> \033[0m";

		getline(cin, planetName);
		cout << endl;
		// conditional forcing ship to land vs giving player a choice
		if (homesickness >= 3) { // forces player to land
			homesickness = 0;
			cout << "Your crew is dreaded with homesickness. You have travelled too far from home. You are ";
			cout << "given no choice but to land on this planet to allow your crew time to get themselves together." << endl;
			cout << "Your rocketship proceeds to get closer to " << planetName << "." << endl;
			cout << "\033[35m"; // color change
			cout << setw(10) << left << "" << setw(62) << right << endl << "Type 'x' to continue" << endl << endl;
			cout << ">> ";
			cout << "\033[0m"; // default color
			cin >> response;

			// generate minor event while rocket is on planet
			newPlanet->determineProbability(playerRocket); // generates probabilities for player to get a certain event
			newPlanet->generateEvent(totalCrew, fuel, foodStorage, homesickness, specialArtifactFound, planetsExplored); // generates good or bad event for player while on planet

			// generate major event later

			if (totalCrew != 0) {
				planetsExplored++;
			}
		}
		else { // gives player an option to land
			cout << "Your rocketship proceeds to get closer to " << planetName << "." << endl;
			cout << "Would you like to continue to land or do you want to continue searching for the next planet?" << endl;
			cout << "\033[35m";  // color change
			cout << setw(10) << left << "" << setw(69) << right << endl << "Type '1' to land, '2' to continue." << endl;
			cout << ">> ";
			cout << "\033[0m"; // default color
			cin >> response;
			while (response != "1" && response != "2") {
				cout << "[ Invalid response. Please re-enter ]" << endl;
				cin >> response;
			}

			// conditional if player continues to land onto the planet
			if (response == "1") {
				// generate minor event while rocket is on planet
				newPlanet->determineProbability(playerRocket); // generates probabilities for player to get a certain event
				newPlanet->generateEvent(totalCrew, fuel, foodStorage, homesickness, specialArtifactFound, planetsExplored); // generates good or bad event for player while on planet

				// generate major event later

				if (totalCrew != 0) {
					planetsExplored++;
				}
			}
			else {
				cout << endl << "You decide to avoid this new planet. ";
			}
		}


		// else continues to next planet

		cout << endl << "Your ship continues to travel to its next destination..." << endl;
		playerRocket.getRocketShape();
		cout << endl;
		fuel -= 10; // lose fuel after passing or exploring each planet
		foodStorage--;
		delete newPlanet;
		homesickness++;
	


		// statement is called after each planet is visited
		cout << endl << "\033[0m\033[35m  ~ You have [" << "\033[1;35m" << totalCrew << "\033[0m\033[35m" << "] crew members, [" << "\033[1;35m" << planetsExplored << "\033[0m\033[35m";
		cout << "] explored planets, [" << "\033[1;35m" << fuel << "\033[0m\033[35m" << "]% fuel, and [" << "\033[1;35m" << foodStorage << "\033[0m\033[35m" << "] weeks of food";
		cout << " and " << "\033[1;35m" << homesickness << "\033[0m\033[35m" << "/3 homesickness ~ \033[0m" << endl;
		cout << endl;

		cout << "\033[35m";  // color change
		cout << setw(10) << left << "" << setw(68) << right << "Type 'x' to continue. Type 'save' to save game."<< endl << ">> ";
		cout << "\033[0m"; // default color
		cin >> response;

		if (response == "save") {
			saveObj.saveCurrentGame(totalCrew, planetsExplored, fuel, foodStorage, homesickness, playerRocket, specialArtifactFound);
		}
		else if (response == "e" || response == "exit") {
			cout << endl << "Thank you for playing!";
			exit(0);
		}
	}

	//  End of game. two game outcomes
	if (totalCrew <= 0 || fuel <= 0 or foodStorage <= 0) {
		cout << endl;
		cout << "\033[31m";
		cout << "You did not make it to the end of the universe. :(" << endl;
		cout << "\033[0m";
	}
	else if (planetsExplored == 6) {
		cout << "As you approached the end of the universe, a sense of awe and wonder washed over you. You witness a";
		cout << "spectacular cosmic display, as stars explodedand galaxies collided in light and color. In that moment,";
		cout << "you understood that the end of the universe was not an end at all, but a new beginning. Your crew would ";
		cout << "be written in galaxtic history as the first to reach the end of the universe.";
		cout << endl;

		asciiObj.endOfUniverse();

		cout << "\033[94m";
		cout << "You have explored all 6 planets and made it to the end of universe. You win.  \033[0m" << endl;
	}


	return 0;
}