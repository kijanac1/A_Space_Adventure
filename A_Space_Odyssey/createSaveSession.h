
#pragma once

#ifndef CREATESAVESESSION_H
#define CREATESAVESESSION_H

#include <string>
#include <iostream>
#include <fstream>
#include "Rocketship.h"
#include "asciiArt.h"

using namespace std;

class createSaveSession {
private:
	string newOrSaved = "";
	string filename;
	string response = "";
	asciiArt asciiObj;


public:
	string getFilename();
	int saveOrNew(int& crew, int& explored, int& fuel, int& foodStorage, int& homesickness, string& rocketType, string& specialArtifactFound);
	void saveCurrentGame(int& crew, int& explored, int& fuel, int& foodStorage, int& homesickness, Rocketship&, string& specialArtifactFound);


};

#endif CREATESAVESESSION