#include "Planets.h"


Planets::Planets() {
	name = new string("");
	surfaceCondition = new string("");
	temperature = new int(0);
	gravity = new int(0);
	minor = new Events();
	goodEventProbability = new int(0);
	planetArt = new asciiArt();
}

Planets::Planets(string planetName, string condition, int temp, int grav, int prob) {
	name = new string(planetName);
	surfaceCondition = new string(condition);
	temperature = new int(temp);
	gravity = new int(grav);
	minor = new Events();
	goodEventProbability = new int(prob);
	planetArt = new asciiArt();
}

void Planets::setName(string planetName) {
	*name = planetName;
}

string Planets::getSurfaceCondition() {
	return *surfaceCondition;
}

Planets::~Planets() {
	if (planetArt != nullptr) {
		delete planetArt;
	}
	if (minor != nullptr) {
		delete minor;
	}
	if (name != nullptr) {
		delete name;
	}
	if (surfaceCondition != nullptr) {
		delete surfaceCondition;
	}
	if (temperature != nullptr) {
		delete temperature;
	}
	if (gravity != nullptr) {
		delete gravity;
	}
	if (goodEventProbability != nullptr) {
		delete goodEventProbability;
	}
}

void Planets::determineProbability(Rocketship rocketObj) {

	/* Probability will default to 50 (50%) but depending on the type of planet the
	player lands on and the type of rocketship they have, probability will change */

	if (*temperature == 145) { // hot planet. Fire rocket favors chances
		if (rocketObj.getType() == "fireRocket") {
			*goodEventProbability = 75;
		}
		else {
			*goodEventProbability = 25;
		}

	}
	else if (*temperature == 75) { // neutral planet. No rocket favors
		*goodEventProbability = 50;

	}

	else { // cold planet. Ice rocket favors chances
		if (rocketObj.getType() == "iceRocket") {
			*goodEventProbability = 75;
		}
		else {
			*goodEventProbability = 25;
		}

	}

	if (*goodEventProbability >= 75) {
		cout << "Your rocketship has resistance to the temperature of this planet so your ";
		cout << "chances of having a successful exploration on the planet is \033[32mhigher\033[0m than usual. ";
		cout << "You proceed to exit your space craft with high hopes." << endl << endl;
	}
	else if (*goodEventProbability <= 25) {
		cout << "Your rocketship is weak to the temperature of this planet so your chances of ";
		cout << "having a successful exploration on the planet is \033[33mlower\033[0m than usual. But regardless ";
		cout << "you continue on with your mission." << endl << endl;
	}



}

void Planets::generateEvent(int& crew, int& fuel, int& foodStorage, int& homesickness, string& specialArtifactFound, int planetsExplored) {
	/* gravity determines how many random events the player encounters.
	The larger the gravity the more events */
	switch (*gravity) {
	case 150:
		for (int i = 0; i < 3; i++) {
			minor->minorEventProbability(crew, fuel, foodStorage, *goodEventProbability, homesickness, specialArtifactFound);
		}
		break;
	case 75:
		for (int i = 0; i < 2; i++) {
			minor->minorEventProbability(crew, fuel, foodStorage, *goodEventProbability, homesickness, specialArtifactFound);
		}
		break;
	default:
		for (int i = 0; i < 1; i++) {
			minor->minorEventProbability(crew, fuel, foodStorage, *goodEventProbability, homesickness, specialArtifactFound);
		}
		break;
	}

	if (planetsExplored == 5) { // calls last major event if on last planet
		minor->majorEvent(crew, fuel, foodStorage, *goodEventProbability, specialArtifactFound);
	}


}

void Planets::createPlanet() { 
	int randNum;

	// else if to decide surface condition
	randNum = rand() % 3;

	if (randNum == 0) {
		*surfaceCondition = "gassy";
	}
	else if (randNum == 1) {
		*surfaceCondition = "wet";
	}
	else if (randNum == 2) {
		*surfaceCondition = "rocky";
	}

	checkMinorEventPointer();

	// else if to decide temperature
	randNum = rand() % 3; // regenerates rand number

	if (randNum == 0) { // cold
		*temperature = -10;
	}
	else if (randNum == 1) { // neutral
		*temperature = 75;
	}
	else if (randNum == 2) { // hot
		*temperature = 145;
	}

	// else if to decide gravity

	randNum = rand() % 3; // regenerates rand number

	if (randNum == 0) { // Large
		*gravity = 150;
	}
	else if (randNum == 1) { // Medium
		*gravity = 75;
	}
	else if (randNum == 2) { // tiny
		*gravity = 5;
	}

	cout << "You begin to see in the distance a new planet. As your get closer your computer monitor observes the planet ";
	cout << "temperature is " << *temperature << " degrees fahrenheit, the planet is very " << *surfaceCondition << ", and you can feel the effects of the " << *gravity;
	cout << "% gravity." << endl;


	// Call for ascii art whenever planet is generated
	if (*temperature == -10) {
		planetArt->icePlanetShape();
	}

	else if (*temperature == 75) {
		planetArt->neutralPlanetShape();
	}

	else {
		planetArt->firePlanetShape();
	}


}

void Planets::checkMinorEventPointer(){

	if (*surfaceCondition == "wet") {
		// Check if minor has been previously allocated memory and delete it if it has
		if (minor != nullptr) {
			delete minor;
		}
		// Allocate memory for the new Events object
		minor = new wetEvents();
	}
	else if (*surfaceCondition == "gassy") {
		// Check if minor has been previously allocated memory and delete it if it has
		if (minor != nullptr) {
			delete minor;
		}
		// Allocate memory for the new Events object
		minor = new gasEvents();
	}
}