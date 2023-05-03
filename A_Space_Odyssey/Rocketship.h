#pragma once

#include <iostream>
#include <string>
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "asciiArt.h"

using namespace std;

#ifndef ROCKETSHIP_H
#define ROCKETSHIP_H

/* At the beginning of the game player will be prompted to choose between a fire rocketship or ice rocketship. Each ship will have
its own advantage and disadvantage on cold and hot planets. For example, if player has an ice rocketship and lands on a hot planet
the probability of getting a bad minor event will increase. */
class Rocketship {
private:
    string type; // can choose between fire ship or ice ship
    asciiArt rocketShape;

public:
    void chooseRocketship(); // function called in main for player to decide rocket type
    void getRocketShape(); // prints ascii picture of rocket depending on type
    string getType(); // returns ice or fire type
    void setType(string);
    Rocketship();

};

#endif