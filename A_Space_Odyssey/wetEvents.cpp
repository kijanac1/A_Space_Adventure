#include "wetEvents.h"

wetEvents::wetEvents() {
	response = "";
	eventNumber = -1;
}

void wetEvents::setEventNumber(int x) {
	eventNumber = x;
}


void wetEvents::minorEventProbability(int& crew, int& fuel, int& foodStorage, int probability, int& homesickness, string& specialArtifactFound) {
	//cout << endl << "WET EVENT FUNCTION CALLED" << endl;

	/* probability by default will be 50/50 chance of good event or bad event.
	but probability will change depending on the type of planet the player lands on */

	int randomProbability = rand() % 101; // randomly chooses probability from 0-100

	// probability is the likelihood of a good event
	// for example, if if randomProbability is 10 and probability = 25, good event will call
	// if randomProbability is less than argument probability, call goodEvent function.
	// else, call badEvent function
	if (randomProbability < probability) {
		eventNumber = rand() % 9; // randomly selects good minor event number
		if (eventNumber <= 6) {
			goodMinorEvent(crew, fuel, foodStorage, eventNumber, homesickness, specialArtifactFound); // calls events from base class
		}
		else {
			wetGoodEvent(crew, fuel, foodStorage, eventNumber, homesickness, specialArtifactFound);
		}
	}
	else {
		eventNumber = rand() % 10; // randomly selects bad minor event number
		if (eventNumber <= 7) {
			badMinorEvent(crew, fuel, foodStorage, eventNumber, homesickness, specialArtifactFound); // calls events from base class
		}
		else {
			wetBadEvent(crew, fuel, foodStorage, eventNumber, homesickness, specialArtifactFound);
		}
	}
}

void wetEvents::wetGoodEvent(int& crew, int& fuel, int& foodStorage, int eventNumber, int& homesickness, string& specialArtifactFound) {
	switch (eventNumber) // BAD EVENTS
	{
	case 7:
		cout << "You can't believe it, but this planet has drinkable water. You load up on H20 for the long road ahead of you" << endl;
		cout << "\033[32m" << "[ FOOD STORAGE +2 ] " << "\033[0m" << endl;
		foodStorage += 2;
		break;
	case 8:
		cout << "You're walking and feel something bounce off your head. You look down and see a strange fruit rolling away from you. ";
		cout << "You look back up to see where it came from and notice the tree is growing some sort of fruit. You use your scanner ";
		cout << "to detect the fruit is edible. You and your crew begin to collect from the tree." << endl;
		cout << "\033[32m" << "[ FOOD STORAGE +2 ] " << "\033[0m" << endl;
		foodStorage += 2;
		break;
	}

	cout << "\033[35m"; // color change
	cout << setw(10) << left << "" << setw(62) << right << endl << "Type 'x' to continue" << endl << endl;
	cout << ">> ";
	cout << "\033[0m"; // default color
	cin >> response;

}

void wetEvents::wetBadEvent(int& crew, int& fuel, int& foodStorage, int eventNumber, int& homesickness, string& specialArtifactFound) {
	switch (eventNumber) // BAD EVENTS
	{
	case 8:
		cout << "It begins to rain on the planet. It doesn't take long to notice this rain has high acidity. You run to take cover but ";
		cout << "its too late. The rain has cut through your crew's backpacks and destroyed a week's supply of food!" << endl;
		cout << "\033[33m" << "[ FOOD STORAGE -1 ] " << "\033[0m" << endl;
		foodStorage--;
		break;
	case 9:
		cout << "You can't believe it, but this planet has drinkable water. At least you thought it was drinkable... ";
		cout << "Your crewmate is sick. Morality decreases as your other crewmates tend the sick mate." << endl;
		cout << "\033[33m" << "[ HOMESICKNESS +1 ] " << "\033[0m" << endl;
		homesickness++;
		break;
	}

	cout << "\033[35m"; // color change
	cout << setw(10) << left << "" << setw(62) << right << endl << "Type 'x' to continue" << endl << endl;
	cout << ">> ";
	cout << "\033[0m"; // default color
	cin >> response;
}