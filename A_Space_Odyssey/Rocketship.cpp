#include "Rocketship.h"

Rocketship::Rocketship() {
    type = "";
    rocketShape = asciiArt();
}

void Rocketship::setType(string t) {
    type = t;
}


void Rocketship::chooseRocketship() { // function called in main for player to decide rocket type
    string response;
    cout << endl << endl << "Choose the rocketship you want to board for your mission" << endl;
    cout << "\033[35m";
    cout << setw(10) << left << "" << setw(63) << right << endl << "Type '1' for ice rocket '2' for fire rocket. " << endl << ">> ";
    cout << "\033[0m";
    cin >> response;
    while (response != "1" && response != "2") {
        cout << "[ Invalid response. Please re-enter ]" << endl;
        cout << "\033[35m";
        cout << setw(10) << left << "" << setw(63) << right << endl << "Type '1' for ice rocket '2' for fire rocket. " << endl << ">> ";
        cout << "\033[0m";
        cin >> response;
    }
    if (response == "1") {
        type = "iceRocket";
        cout << "You have chosen the ice rocketship! Press 'x' to continue" << endl;
        cout << "\033[35m>> \033[0m";
        cin >> response;
    }
    else {
        type = "fireRocket";
        cout << "You have chosen the fire rocketship! Press 'x' to continue" << endl;
        cout << "\033[35m>> \033[0m";
        cin >> response;

    }
}

void Rocketship::getRocketShape() { // prints rocket ascii art
    if (type == "iceRocket") {
        rocketShape.iceRocketShape();
    }
    else {
        rocketShape.fireRocketShape();
    }

}string Rocketship::getType() {
    return type;
}