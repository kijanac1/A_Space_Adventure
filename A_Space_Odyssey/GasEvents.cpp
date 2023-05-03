#include "GasEvents.h"


gasEvents::gasEvents() {
	response = "";
	eventNumber = -1;
}

void gasEvents::setEventNumber(int x) {
	eventNumber = x;
}

void gasEvents::minorEventProbability(int& crew, int& fuel, int& foodStorage, int probability, int& homesickness, string& specialArtifactFound) {
	//cout << endl << "GAS EVENT FUNCTION CALLED" << endl;

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
			gasGoodEvent(crew, fuel, foodStorage, eventNumber, homesickness, specialArtifactFound);
		}
	}
	else {
		eventNumber = rand() % 10; // randomly selects bad minor event number
		if (eventNumber <= 7) {
			badMinorEvent(crew, fuel, foodStorage, eventNumber, homesickness, specialArtifactFound); // calls events from base class
		}
		else {
			gasBadEvent(crew, fuel, foodStorage, eventNumber, homesickness, specialArtifactFound);
		}
	}
}


void gasEvents::gasGoodEvent(int& crew, int& fuel, int& foodStorage, int eventNumber, int& homesickness, string& specialArtifactFound) {
	switch (eventNumber) // BAD EVENTS
	{
	case 7:
		cout << "Your scanner goes off. You take notice that the atmosphere of this planet is compose of a material your ship can use as ";
		cout << "as fuel. You and your crew begin to collect what you can." << endl;
		cout << "\033[32m" << "[ FUEL +2 ] " << "\033[0m" << endl;
		fuel += 2;
		break;
	case 8:
		cout << "find black matter" << endl;
		cout << "You walk into a cave because something from this direction is causing your scanner to go off. Is this real black matter? ";
		cout << "This will be able to keep the ship running for weeks." << endl;
		cout << "\033[32m" << "[ FUEL +2 ] " << "\033[0m" << endl;
		fuel += 2;
		break;
	}

	cout << "\033[35m"; // color change
	cout << setw(10) << left << "" << setw(62) << right << endl << "Type 'x' to continue" << endl << endl;
	cout << ">> ";
	cout << "\033[0m"; // default color
	cin >> response;

}

void gasEvents::gasBadEvent(int& crew, int& fuel, int& foodStorage, int eventNumber, int& homesickness, string& specialArtifactFound) {
	switch (eventNumber) // BAD EVENTS
	{
	case 8:
		cout << "You've made a mistake. The air on this planet is compose of an element that conflicts with your fuel source, destroying ";
		cout << "a week's worth of fuel. You scurry to try to get off this planet." << endl;
		cout << "\033[33m" << "[ FUEL -1 ] " << "\033[0m" << endl;
		fuel--;
		break;
	case 9:
		// can't see because of thick mist
		cout << "This gassy planet makes it hard to see. You walk further and the mist gets denser and denser. You and your crew wander through ";
		cout << "the mist for hours trying to find your way back to the ship. It's hard to stay motivated in times like these." << endl;
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