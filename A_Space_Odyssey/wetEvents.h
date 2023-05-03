#pragma once

#ifndef WETEVENTS_H
#define WETEVENTS_H

#include <string>
#include <iostream>
#include <iomanip>
#include "Events.h"

using namespace std;


class wetEvents : public Events {
private:
	string response;
	int eventNumber;

public:
	wetEvents();
	virtual void minorEventProbability(int& crew, int& fuel, int& foodStorage, int eventNumber, int& homesickness, string& specialArtifactFound); //overrides base class
	void wetBadEvent(int& crew, int& fuel, int& foodStorage, int eventNumber, int& homesickness, string& specialArtifactFound);
	void wetGoodEvent(int& crew, int& fuel, int& foodStorage, int eventNumber, int& homesickness, string& specialArtifactFound);
	void setEventNumber(int);
	//void randomProbability();

};

#endif