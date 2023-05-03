#pragma once

#ifndef EVENTS_H
#define EVENTS_H

#include <string>
#include <iostream>
#include <iomanip>
#include "Rocketship.h"
#include "asciiArt.h"

using namespace std;


/* This class is called from the Planets class. Events class was placed
in it's own separate class simply to help with organization */

class Events {
protected:
	int eventNumber;
	string response;
	asciiArt artObj;

private:
	Rocketship playerShip; // generates rocket obj so can determine probability of events
	int probability; // probability of good or bad events

public:
	Events();
	virtual void minorEventProbability(int& crew, int& fuel, int& foodStorage, int p, int& homesickness, string& specialArtifactFound);
	void goodMinorEvent(int& crew, int& fuel, int& foodStorage, int eventNumber, int& homesickness, string& specialArtifactFound);
	void badMinorEvent(int& crew, int& fuel, int& foodStorage, int eventNumber, int& homesickness, string& specialArtifactFound);
	void majorEvent(int& crew, int& fuel, int& foodStorage, int& homesickness, string specialArtifactFound);

};

#endif