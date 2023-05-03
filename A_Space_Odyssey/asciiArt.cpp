#include "asciiArt.h"

void asciiArt::mainMenu() {

    cout << "\033[35m";
    cout << "             " << "===================================" << endl;
    cout << "             " << "|\033[0m             MENU               \033[35m |" << endl;
    cout << "             " << "===================================" << endl;
    cout << "             " << "|\033[0m Options:                       \033[35m |" << endl;
    cout << "             " << "|\033[0m        1. Start game           \033[35m |" << endl;
    cout << "             " << "|\033[0m        2. Instructions         \033[35m |" << endl;
    cout << "             " << "|\033[0m        3. Exit                 \033[35m |" << endl;
    cout << "             " << "===================================" << endl;
    cout << "             " << "Make a selection: " << endl;
    cout << "             " << ">> " << "\033[0m";
    cin >> response;
    cout << "\033[0m";

    while (response != "1" && response != "2" && response != "3") {
        cout << "             " << "[ Invalid response. Please re-enter selection ]" << endl;
        cout << "\033[35m";
        cout << "             " << ">> ";
        cin >> response;
        cout << "\033[0m";
    }

    if (response == "2") {
        instructions();
    }

    else if (response == "3") {
        cout << endl << "Thank you for playing!";
        exit(0);
    }
    cout << endl << endl << endl;

}

void asciiArt::instructions() {

    cout << endl << endl;
    cout << "\033[35m";
    cout << "             " << "==================================================================                  " << endl;
    cout << "             " << "|                       INSTRUCTIONS                             |                  " << endl;
    cout << "             " << "==================================================================                  " << endl;
    cout << "             " << "| Goal:                                                          |                  " << endl;
    cout << "             " << "|\033[0m   You have been given a mission to explore the galaxies        \033[35m|   " << endl;
    cout << "             " << "|\033[0m   and make it to the end of the universe.You win if            \033[35m|   " << endl;
    cout << "             " << "|\033[0m   you can make it to the end without losing too many           \033[35m|   " << endl;
    cout << "             " << "|\033[0m   crew members, running out of food, or running out of fuel.   \033[35m|   " << endl;
    cout << "             " << "| Rocketships:                                                   |                  " << endl;
    cout << "             " << "|\033[0m   You are to decide between two different types of             \033[35m|   " << endl;
    cout << "             " << "|\033[0m   rocketships.The ice rocketship, and the fire rocketship.     \033[35m|   " << endl;
    cout << "             " << "|\033[0m   Ice is weak to fire plants, and of course fire is weak to    \033[35m|   " << endl;
    cout << "             " << "|\033[0m   ice planets.                                                 \033[35m|   " << endl;
    cout << "             " << "|                                                                |                  " << endl;
    cout << "             " << "| Gameplay :                                                     |                  " << endl;
    cout << "             " << "|\033[0m   You can decide if you want to stop at a planet to explore    \033[35m|   " << endl;
    cout << "             " << "|\033[0m   or continue to the next planet.Keep in mind for each planet, \033[35m|   " << endl;
    cout << "             " << "|\033[0m   regardless if you explore or skip, will drain your fueland   \033[35m|   " << endl;
    cout << "             " << "|\033[0m   reduce your food storage.If you continue to skip planets     \033[35m|   " << endl;
    cout << "             " << "|\033[0m   you'll run out before you can win.                           \033[35m|   " << endl;
    cout << "             " << "|                                                                |                  " << endl;
    cout << "             " << "=================================================================                   " << endl << endl << endl;

    cout << "             Type 'x' to start game" << endl;
    cout << "\033[35m";
    cout << "             " << ">> ";
    cout << "\033[0m";
    cin >> response;
}

void asciiArt::gameHeader() {


    cout << endl << endl;
    cout << "\033[35m  ______     ______   ______     ______     ______" << endl;
    cout << " /\\  ___\\   /\\  == \\ /\\  __ \\   /\\  ___\\   /\\  ___\\" << endl;
    cout << " \\ \\___  \\  \\ \\  _-/ \\ \\  __ \\  \\ \\ \\____  \\ \\  __\\" << endl;
    cout << "  \\/\\____ \\  \\ \\_\\    \\ \\_\\ \\_\\  \\ \\_____\\  \\ \\_____\\ " << endl;
    cout << "   \\/_____/   \\/_/     \\/_/\\/_/   \\/_____/   \\/_____/ " << endl;
    cout << endl;
    cout << "  ______     _____     __  __     ______     ______     ______     __  __" << endl;
    cout << " /\\  __ \\   /\\  __-.  /\\ \\_\\ \\   /\\  ___\\   /\\  ___\\   /\\  ___\\   /\\ \\_\\ \\" << endl;
    cout << " \\ \\ \\/\\ \\  \\ \\ \\/\\ \\ \\ \\____ \\  \\ \\___  \\  \\ \\___  \\  \\ \\  __\\   \\ \\____ \\" << endl;
    cout << "  \\ \\_____\\  \\ \\____-  \\/\\_____\\  \\/\\_____\\  \\/ \\____\\  \\ \\_____\\  \\/\\_____\\" << endl;
    cout << "   \\/_____/   \\/____/   \\/_____/   \\/_____/   \\/_____/   \\/_____/   \\/_____/\033[0m" << endl << endl << endl;

    cout << "             " << "Enter 'x' to continue" << endl << endl;
    cout << "             ";
    cin >> response;

}

void asciiArt::leavingEarth() {


    cout << "\033[36m" << endl;
    cout << "          " << " *    '*" << endl;
    cout << "          " << "          *" << endl;
    cout << "          " << " *" << endl;
    cout << "          " << "                       *" << endl;
    cout << "          " << "               *" << endl;
    cout << "          " << "                     *" << endl;
    cout << "          " << "" << endl;
    cout << "          " << "         .                      ." << endl;
    cout << "          " << "         .                      ;" << endl;
    cout << "          " << "         :                  - --+- -" << endl;
    cout << "          " << "         !           .          !" << endl;
    cout << "          " << "         |        .             ." << endl;
    cout << "          " << "         |_         +" << endl;
    cout << "          " << "      ,  | `." << endl;
    cout << "          " << "--- --+-<#>-+- ---  --  -" << endl;
    cout << "          " << "      `._|_,'" << endl;
    cout << "          " << "         T" << endl;
    cout << "          " << "         |" << endl;
    cout << "          " << "         !" << endl;
    cout << "          " << "         :         . : " << endl;
    cout << "          " << "         .       *" << endl;
    cout << "          " << "\033[0m" << endl;
}

void asciiArt::firePlanetShape() {
    cout << endl << endl;
    cout << "\033[36m" << endl;

    cout << "          " << "                  *       +" << endl;
    cout << "          " << "            '                    |             " << endl;
    cout << "          " << "        ()   \033[31m .-.,='``^=.     \033[36m - o -           " << endl;
    cout << "          " << "             \033[31m '=/_  *#   \\     \033[36m  |            " << endl;
    cout << "          " << "           * \033[31m  ; '=._    ;'  \033[36m                " << endl;
    cout << "          " << "             \033[31m   \\     `=. `, \033[36m        '       " << endl;
    cout << "          " << "            . \033[31m   '=.__.=''`=' \033[36m     *         " << endl;
    cout << "          " << "    +         \033[31m                \033[36m+              " << endl;
    cout << "          " << "         O      *       '       .           " << endl;
    cout << "          " << endl << endl;
    cout << "\033[0m" << endl;

}

void asciiArt::neutralPlanetShape() {
    cout << endl << endl;
    cout << "\033[36m" << endl;

    cout << "          " << "                  *       +" << endl;
    cout << "          " << "            '                    |             " << endl;
    cout << "          " << "        ()   \033[32m .-.,='``^=.     \033[36m - o -           " << endl;
    cout << "          " << "             \033[32m '=/_  *#   \\     \033[36m  |            " << endl;
    cout << "          " << "           * \033[32m  ; '=._    ;'  \033[36m                " << endl;
    cout << "          " << "             \033[32m   \\     `=. `, \033[36m        '       " << endl;
    cout << "          " << "            . \033[32m   '=.__.=''`=' \033[36m     *         " << endl;
    cout << "          " << "    +         \033[32m                \033[36m+              " << endl;
    cout << "          " << "         O      *       '       .           " << endl;
    cout << "          " << endl << endl;
    cout << "\033[0m" << endl;

}

void asciiArt::icePlanetShape() {
    cout << endl << endl;
    cout << "\033[36m" << endl;

    cout << "          " << "                  *       +" << endl;
    cout << "          " << "            '                    |             " << endl;
    cout << "          " << "        ()   \033[34;1m .-.,='``^=.     \033[36m - o -           " << endl;
    cout << "          " << "             \033[34;1m '=/_  *#   \\     \033[36m  |            " << endl;
    cout << "          " << "           * \033[34;1m  ; '=._    ;'  \033[36m                " << endl;
    cout << "          " << "             \033[34;1m   \\     `=. `, \033[36m        '       " << endl;
    cout << "          " << "            . \033[34;1m   '=.__.=''`=' \033[36m     *         " << endl;
    cout << "          " << "    +         \033[34;1m                \033[36m+              " << endl;
    cout << "          " << "         O      *       '       .           " << endl;
    cout << "          " << endl << endl;
    cout << "\033[0m" << endl;

}



void asciiArt::iceRocketShape() {

    cout << endl;
    cout << "\033[36m                  *             .        '";
    cout << endl;
    cout << "         _|\\________" << endl;
    cout << "     \033[33m<<<\033[36m| |      |  \033[0m\\\033[36m       *      . " << endl;
    cout << "     \033[33m<<<\033[36m|_|______ |__/     +                     *" << endl;
    cout << "         |/" << endl;
    cout << "     *                   ~        +                 *" << endl;
    cout << "\033[0m";
}

void asciiArt::fireRocketShape() {

    cout << endl;
    cout << "\033[31m                  *             .        '";
    cout << endl;
    cout << "         _|\\________" << endl;
    cout << "     \033[33m<<<\033[31m| |      |  \033[0m\\\033[31m       *      . " << endl;
    cout << "     \033[33m<<<\033[31m|_|______ |__/     +                     *" << endl;
    cout << "         |/" << endl;
    cout << "     *                   ~        +                 *" << endl;
    cout << "\033[0m";
}

void asciiArt::endOfUniverse() {

    cout << endl << endl;
    cout << "\033[36m" << endl;
    cout << "     .              +   .                .   . .     .  ." << endl;
    cout << "                   .                    .       .     *  " << endl;
    cout << "  .       *                        . . . .  .   .  + .   " << endl;
    cout << "                                      .   .  +  . . .    " << endl;
    cout << ".                               .  .   .    .    . .     " << endl;
    cout << "                              .     .     . +.    +  .   " << endl;
    cout << "                                .       .   . .          " << endl;
    cout << "        . .                  .    * . . .  .  +   .      " << endl;
    cout << "           +      .           .   .      +               " << endl;
    cout << "                            .       . +  .+. .           " << endl;
    cout << "  .                      .     . + .  . .     .      .   " << endl;
    cout << "           .      .    .     . .   . . .        ! /      " << endl;
    cout << "      *             .    . .  +    .  .       - O -      " << endl;
    cout << "          .     .    .  +   . .  *  .       . / |        " << endl;
    cout << "               . + .  .  .  .. +  .                      " << endl;
    cout << ".      .  .  .  *   .  *  . +..  .            *          " << endl;
    cout << " .      .   . .   .   .   . .  +   .    .            +   " << endl;
    cout << endl << endl;
    cout << "\033[0m" << endl;
}


void asciiArt::alienKing() {

    cout << endl << endl;
    cout << " \033[36m         *                        " << endl;
    cout << "       ~                     *            " << endl;
    cout << "\033[1;35m" << endl;
    cout << "       " << "       \033[36m+\033[1;35m     ___..._    " << endl;
    cout << "       " << "    _,--'       '`-.    " << endl;
    cout << "       " << "  ,'.  .            \\  " << endl;
    cout << "       " << ",/:. .     .       .'   " << endl;
    cout << "       " << "|;..  .      _..--'     " << endl;
    cout << "       " << "`--:...-,-'""\\          " << endl;
    cout << "       " << "\033[94m";
    cout << "       " << " |:.    `.                " << endl;
    cout << "       " << "        l;.   l       \033[36m+\033[94m    " << endl;
    cout << "       " << "        `|:.   |        " << endl;
    cout << "       " << "         |:.   `.,      " << endl;
    cout << "       " << "        .l;.    j, ,    " << endl;
    cout << "       " << "\033[36m  *\033[94m   `. \\`;:.   //,/    " << endl;
    cout << "       " << "      .\\\\)`;,|\\'/(      " << endl;
    cout << "       " << "       ` `itz `(,       " << endl;
    cout << endl << endl;
    cout << "\033[0m";
}