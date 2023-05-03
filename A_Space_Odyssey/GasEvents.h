#pragma once

#ifndef GASEVENTS_H
#define GASEVENTS_H

#include <string>
#include <iostream>
#include <iomanip>
#include "Events.h"

using namespace std;


class gasEvents : public Events {
private:
	string response;
	int eventNumber;

public:
	gasEvents();
	virtual void minorEventProbability(int& crew, int& fuel, int& foodStorage, int eventNumber, int& homesickness, string& specialArtifactFound); //overrides base class
	void gasBadEvent(int& crew, int& fuel, int& foodStorage, int eventNumber, int& homesickness, string& specialArtifactFound);
	void gasGoodEvent(int& crew, int& fuel, int& foodStorage, int eventNumber, int& homesickness, string& specialArtifactFound);
	void setEventNumber(int);
	//void randomProbability();

};

#endif