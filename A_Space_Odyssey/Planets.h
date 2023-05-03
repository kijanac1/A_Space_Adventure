#pragma once

#ifndef PLANETS_H
#define PLANETS_H

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "Events.h"
#include "wetEvents.h"
#include "GasEvents.h"
#include "asciiArt.h"


using namespace std;

class Planets {
private:
	asciiArt* planetArt;
	string* name;
	string* surfaceCondition;
	int* temperature;
	int* gravity;
	int* goodEventProbability;


public:
	Planets();
	Planets(string, string, int, int, int);
	~Planets();

	Events* minor;
	void determineProbability(Rocketship rocketObj);
	void setName(string);
	string getSurfaceCondition();
	void createPlanet();
	void generateEvent(int&, int&, int&, int&, string&, int planetsExplored);
	void checkMinorEventPointer();

};



#endif PLANETS_H;
