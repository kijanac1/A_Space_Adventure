#pragma once

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#ifndef ASCIIART_H
#define ASCIIART_H

/* This class will be used to draw ascii art that used throughout the game */
class asciiArt {
private:
    string response;
public:
    /*********** drawings for beginning of game */
    void mainMenu();
    void instructions();
    void gameHeader();
    void leavingEarth();
    /*********** drawing rockets */
    void iceRocketShape();
    void fireRocketShape();
    /*********** drawing planets */
    void icePlanetShape();
    void firePlanetShape();
    void neutralPlanetShape();
    /*********** drawing for main event at end of game */
    void alienKing();
    void endOfUniverse();

};

#endif