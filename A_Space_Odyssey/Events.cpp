#include "Events.h"


Events::Events() {
	response = "";
	probability = 0;
}


void Events::minorEventProbability(int& crew, int& fuel, int& foodStorage, int probability, int& homesickness, string& specialArtifactFound) {

	/* probability by default will be 50/50 chance of good event or bad event.
	but probability will change depending on the type of planet the player lands on */

	int randomProbability = rand() % 101; // randomly chooses probability from 0-100

	// probability is the likelihood of a good event
	// for example, if if randomProbability is 10 and probability = 25, good event will call
	// if randomProbability is less than argument probability, call goodEvent function.
	// else, call badEvent function
	if (randomProbability < probability) {
		eventNumber = rand() % 7; // randomly selects good minor event number
		goodMinorEvent(crew, fuel, foodStorage, eventNumber, homesickness, specialArtifactFound);
	}
	else {
		eventNumber = rand() % 8; // randomly selects bad minor event number
		badMinorEvent(crew, fuel, foodStorage, eventNumber, homesickness, specialArtifactFound);
	}
}

void Events::badMinorEvent(int& crew, int& fuel, int& foodStorage, int eventNumber, int& homesickness, string& specialArtifactFound) {
	// randomizer chooses which bad random event
	// randomly chooses events 0-8
	


	switch (eventNumber) // BAD EVENTS
	{
	case 0:  // pick up bad luck charm
		cout << "You see a strange object on the ground, it has resemblance of a charm. It's hard to not to notice it due to its ";
		cout << "ominous glow. You wonder if it'll bring you fortune if you pick it up or maybe if it's an omen." << endl;
		cout << "Do you want to pick it up? " << endl;
		cout << "\033[35m";
		cout << setw(10) << left << "" << setw(63) << right << endl << "Type 'yes' or 'no'. " << endl << ">> ";
		cout << "\033[0m";
		cin >> response;
		while (response != "yes" && response != "no") {
			cout << "[ Invalid response. Please re-enter. ]" << endl;
			cout << "\033[35m>> \033[0m";
			cin >> response;
		}
		if (response == "yes") {
			fuel -= 10;
			cout << endl << "You decide to pick up the strange item. You get a bad feeling from it.." << endl << endl;
			cout << endl << "\033[33m" << "[FUEL -10]" << "\033[0m" << endl;
		}
		else if (response == "no") {
			cout << endl << "You decide to leave the strange object alone. Guess you'll never know.." << endl << endl;
		}
		break;

	case 1:
		// damage to ship
		cout << "While exploring this planet, you hear what sounds like an earthquake in the background. What could that be? You turn around and you ";
		cout << "see asteroids falling in the area where you left the rocketship..." << endl;
		cout << "\033[33m" << "[ FUEL -15 ]" << "\033[0m" << endl << endl;
		fuel -= 15;
		break;
	case 2:
		// losing food
		cout << "You ask your crewmate to hand you a bottle of water. Your crewmate reaches in their bag and realizes there's a hole in it. A really big ";
		cout << "hole. They were carrying all the food for exploring this planet and the bag is empty. Time to head back to the ship to get more food." << endl;
		cout << "\033[33m" << "[ FOOD STORAGE -1 ]" << "\033[0m" << endl;
		foodStorage--;
		break;
	case 3:
		// alien eats crew member
		cout << "You're exploring the planet and turn around to see one of your crewmates being absorbed by a strange, gelatin beast. You attempt ";
		cout << "to try to save your crewmate but the organism takes off in the other direction at the speed of a cheetah." << endl;
		cout << "\033[33m" << "[ CREW -1 ]" << "\033[0m" << endl;
		crew--;
		break;
	case 4:
		// alien eats food
		cout << "You and your crew are exploring a new planet when you accidentally bump into a largeand menacing creature.The creature grabs one ";
		cout << "of your crewmates with its long tongueand eats them, but then spits them back outand rolls away into a ball.Your crewmate is safe ";
		cout << "but the creature ate all of the food they were carrying for the week." << endl;
		cout << "\033[33m" << "[ FOOD STORAGE -1 ]" << "\033[0m" << endl;
		foodStorage--;
		break;
	case 5:
		// lose water
		cout << "Your crew continues on to explore this mysterious planet. Maybe out of exhaustion or carelessness, but one of your crewmates trip ";
		cout << "and fall on to their back. Don't worry, they are okay. But they break a large supply of drinking water that was intended to keep the ";
		cout << "crew hydrated on your mission. " << endl;
		cout << "\033[33m" << "[ FOOD STORAGE -1 ]" << "\033[0m";
		foodStorage--;
		break;
	case 6:
		// avalanche
		cout << "You come across a mountain and decide to climb it to scavenge for more supplies. While climbing, you hear a loud rumble. You look up ";
		cout << "And see boulders of all sizes rolling towards you and your crew. You take cover behind a large enough rock and come out unscathe. Once ";
		cout << "the rocks finally stop, you look back and notice you're missing a crewmate." << endl;
		cout << "\033[33m" << "[ CREW -1 ]" << "\033[0m";
		crew--;
		break;
	case 7:
		// broken oxygen tank
		cout << "You're wandering this new planet and suddenly your crewmate collapses on the ground. You rush to your mate. What could possibly be wrong? ";
		cout << "You look over at the gauge on your crewmate's oxygen tank. It says 'EMPTY'. You observe further and notice they're tank has a large crack ";
		cout << "in it. In a panic you try to offer your own oxygen but it's already too late." << endl;
		cout << "\033[33m" << "[ CREW - 1]" << "\033[0m" << endl;
		crew--;
		break;
	}

	cout << "\033[35m"; // color change
	cout << setw(10) << left << "" << setw(62) << right << endl << "Type 'x' to continue" << endl << endl;
	cout << ">> ";
	cout << "\033[0m"; // default color
	cin >> response;
}

void Events::goodMinorEvent(int& crew, int& fuel, int& foodStorage, int eventNumber, int& homesickness, string& specialArtifactFound) { // GOOD EVENTS
	// randomizer chooses which good random event

	switch (eventNumber) // GOOD EVENTS
	{
	case 0:
		// increasing morale of crew members
		cout << "While traversing the planet, you turn around to your crew and you can tell they are tired and discouraged. You remind them how you ";
		cout << "are the first of humanity to set foot on this type of mission. And no matter the outcome, you will be the group that first that came ";
		cout << "close to the secrets of the universe. You notice this speech gives your crew an increase in morale." << endl;
		cout << "\033[32m" << "[ HOMESICKNESS -1 ] " << "\033[0m" << endl;
		homesickness--;
		break;
	case 1:
		// alien magic increases crew
		cout << "You feel a strange, slimy movement around your neck. You quickly slap at your neck and a strange octopus-like being slithers down your arm. ";
		cout << "You're stunned because an alien is on your arm. Does it want to harm you? It begins to glow and a long lost friend appears before you." << endl;
		cout << "\033[32m" << "[ CREW +1 ] " << "\033[0m" << endl;
		crew++;
		break;
	case 2:
		// sunset increases morale
		cout << "As the time continues to past, you and your crew see the sunsetting. The alien, unreal colors is one of the most beautiful things you have ever ";
		cout << "seen. You know it's just a feeling, but you feel you can endure this mission longer than you thought." << endl;
		cout << "\033[32m" << "[FOOD STORAGE + 1]" << "\033[0m" << endl;
		foodStorage++;
		break;
	case 3:
		// morale of crew increases length of food supply
		cout << "As the time continues to past, you and your crew see the sunsetting. The alien, unreal colors is one of the most beautiful things you have ever ";
		cout << "seen. You know it's just a feeling, but you can feel the morale of your crewmates increase." << endl;
		cout << "\033[32m" << "[FOOD STORAGE + 1]" << "\033[0m" << endl;
		foodStorage++;
		break;
	case 4:
		// make a wish on a shooting start
		cout << "You see a shooting star. What a rare and beatiful sighting. You make a wish." << endl;
		cout << "Do you want a more boutiful crew or do you want something that will help your current crew?" << endl;
		cout << "\033[35m";
		cout << setw(10) << left << "" << setw(63) << right << endl << "Type '1' for more crew or '2' for more resources. " << endl << ">> ";
		cout << "\033[0m";
		response = "";
		cin >> response;
		while (response != "1" && response != "2") {

			cout << "[ Invalid response. Please re-enter. ]" << endl;
			cout << "\033[35m>> \033[0m";
			cin >> response;
		}
		if (response == "1") {
			cout << endl << "\033[32m" << "[ CREW +2 ] " << "\033[0m";
			crew += 2;
		}
		else if (response == "2") {
			cout << "\033[32m" << endl << "[ FOOD STORAGE +2 ]" << "\033[0m";
			foodStorage += 2;
		}

		break;
	case 5:
		// good luck charm
		cout << "You see a strange object on the ground, it has resemblance of a charm. It's hard to not to notice it due to its ";
		cout << "ominous glow. You wonder if it'll bring you fortune if you pick it up or maybe if it's an omen." << endl;
		cout << "Do you want to pick it up? " << endl;
		cout << "\033[35m";
		cout << setw(10) << left << "" << setw(63) << right << endl << "Type 'yes' or 'no'. " << endl << ">> ";
		cout << "\033[0m";

		cin >> response;
		while (response != "yes" && response != "no") {

			cout << "[ Invalid response. Please re-enter. ]" << endl;
			cout << "\033[35m>> \033[0m";
			cin >> response;
		}
		if (response == "yes") {
			fuel += 10;
			cout << endl << "You decide to pick up the strange item. You get a good feeling from it.." << endl << endl;
			cout << "\033[32m" << endl << "[ FUEL +10]" << "\033[0m";
		}
		else if (response == "no") {
			cout << endl << "You decide to leave the strange object alone. Guess you'll never know.." << endl << endl;
		}
		break;
	case 6:
		// find artifact that helps at end of game
		cout << "You find a strange looking artifact. Does it do anything? No it is useless to you. You ";
		cout << "decide to keep it anyway because it looks cool." << endl;
		cout << "[ COOL ARTIFACT+ ]" << endl << endl;
		specialArtifactFound = "true";
		break;

	}
	cout << "\033[35m"; // color change
	cout << setw(10) << left << "" << setw(62) << right << endl << "Type 'x' to continue" << endl << endl;
	cout << ">> ";
	cout << "\033[0m"; // default color
	cin >> response;
}

void Events::majorEvent(int& crew, int& fuel, int& foodStorage, int& homesickness, string specialArtifactFound) {

	cout << "You're about to aboard your ship, but see a giant mushroom-like plant next to your ship. You did not notice it when you landed. ";
	cout << "You wonder if maybe it could be edible. You attempt to pull one of its roots but then the mushroom begins to glow." << endl;

	artObj.alienKing();

	cout << "\033[35m";
	cout << setw(10) << left << "" << setw(63) << right << endl << "Type 'x' to continue" << endl << ">> ";
	cout << "\033[0m";
	cin >> response;

	cout << "The mushroom begins to speak. 'Small being, I am the alien king of this universe. I have been watching carefully as you have travelled far ";
	cout << "from your home in pursuit of finding the end of the universe. There are billions of planets in the universe. Do you think you will reach ";
	cout << "your goal by simply travelling from planet to planet?' " << endl;

	cout << "\033[35m";
	cout << setw(10) << left << "" << setw(63) << right << endl << "Type 'x' to continue" << endl << ">> ";
	cout << "\033[0m";
	cin >> response;

	cout << "'I will test your resilience. If you are able to pass my test, I will give your guidance to the end of the universe. If you fail, you may ";
	cout << "never reach your goal. ' Your journey has led you to here. You are ready to prove your ability." << endl;

	cout << "\033[35m";
	cout << setw(10) << left << "" << setw(63) << right << endl << "Type 'x' to continue" << endl << ">> ";
	cout << "\033[0m";
	cin >> response;

	cout << "Alien king transports you into a dark, dungeon like maze. 'You must find the end of the maze in an alotted amount of time. If you are unable ";
	cout << "to find your way in the required amount of time, you lose.'" << endl;

	cout << "\033[35m";
	cout << setw(10) << left << "" << setw(63) << right << endl << "Type 'x' to continue" << endl << ">> ";
	cout << "\033[0m";
	cin >> response;


	int turnsCorrect = 0;
	int correctPath = rand() % 2; // randomly generate the correct path
	int i = 0; // total number of turns player gets for while loop. Will loop 10 times unless they win.
	bool win = false;

	if (specialArtifactFound == "true") {
		cout << "You hear the useless artifact that you've been carrying been to make noise from your pocket. ";
		cout << "What is it saying? You hear it say 'left...right'. Is it telling you the future?" << endl << endl;
	}

	cout << "You begin to try to escape from the maze. Which way first? Left or right?" << endl;

	cout << "\033[35m";
	cout << setw(10) << left << "" << setw(63) << right << endl << "Type 'x' to continue" << endl << ">> ";
	cout << "\033[0m";
	cin >> response;
	
	while (turnsCorrect < 7 && i < 10) {
		string response;
		string nextPath;

		// randomly generates the next path
		int randomNum = rand() % 2;
		switch (randomNum)
		{
		case 0:
			nextPath = "left";
			break;
		case 1:
			nextPath = "right";
			break;
		}

		if (specialArtifactFound == "true") {
			switch (randomNum)
			{
			case 0:
				cout << "'correct path is left...' you hear a whisper coming from the artifact" << endl;
				break;
			case 1:
				cout << "'correct path is right...' you hear a whisper coming from the artifact" << endl;
				break;
			}

		}

		cout << "\033[35m";
		cout << setw(10) << left << "" << setw(66) << right << endl << "Enter 'left' or 'right': " << endl << ">> ";
		cout << "\033[0m";
		cin >> response;

		// creates error message while invalid input
		while (response != "left" && response != "right") {
			cout << "[ Invalid response. Please re-enter. ]" << endl;
			cout << "\033[35m";
			cout << ">> ";
			cout << "\033[0m";
			cin >> response;

		}

		// conditional depending on if players selected path is correct or not.
		if (response == "left" && nextPath == "left") {
			cout << "Correct path! You move on.\n";
			turnsCorrect++;
		}
		else if (response == "right" && nextPath == "right") {
			cout << "Correct path! You move on.\n";
			turnsCorrect++;
		}
		else {
			cout << "You found a dead end. You retrace your steps so you can try again." << endl;
		}

		i++;

	}

	if (turnsCorrect == 7) {
		cout << "You found the exit! " << endl;

		cout << "\033[35m";
		cout << setw(10) << left << "" << setw(63) << right << endl << "Type 'x' to continue" << endl << ">> ";
		cout << "\033[0m";
		cin >> response;

		cout << " 'I doubted you from the beginning.' the alien king began to speak. 'I've been watching you and "; 
		cout << "your crew since you've managed to leave Earth. I never thought you would have made it this far. ";
		cout << "You have not only impressed me but also earned my respect. '" << endl;

		cout << "\033[35m";
		cout << setw(10) << left << "" << setw(63) << right << endl << "Type 'x' to continue" << endl << ">> ";
		cout << "\033[0m";
		cin >> response;

		cout << "\033[94m[ CREW +3, FUEL +20, FOODSTORAGE +3] \033[0m" << endl;

		crew += 3;
		fuel += 20;
		foodStorage += 3;

		cout << "\033[35m";
		cout << setw(10) << left << "" << setw(63) << right << endl << "Type 'x' to continue" << endl << ">> ";
		cout << "\033[0m";
		cin >> response;

	}

	else{
		cout << "You did not find the exit in time..." << endl;

		cout << "\033[35m";
		cout << setw(10) << left << "" << setw(63) << right << endl << "Type 'x' to continue" << endl << ">> ";
		cout << "\033[0m";
		cin >> response;

		cout << "The alien king scoffs at you. 'Why do you think you're worthy to reach the end of the universe when " << endl;
		cout << "You can't solve a simple puzzle.' The alien king takes no pity on you then continues with their speech. " << endl;
		cout << "I'll make a deal with you, I want and offering. And if you're still able to make it to the end of the universe " << endl;
		cout << "with what you have left, I'll direct you on how to get there. " << endl << endl;

		cout << "What could the alien king mean... " << endl;

		cout << "\033[35m";
		cout << setw(10) << left << "" << setw(63) << right << endl << "Type 'x' to continue" << endl << ">> ";
		cout << "\033[0m";
		cin >> response;

		cout << "\033[31m[ CREW -3, FUEL -40, FOODSTORAGE -3] \033[31m" << endl;

		crew -= 3;
		fuel -= 40;
		foodStorage -= 3;

		cout << "\033[35m";
		cout << setw(10) << left << "" << setw(63) << right << endl << "Type 'x' to continue" << endl << ">> ";
		cout << "\033[0m";
		cin >> response;
	}

	
}
