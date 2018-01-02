// FirstUnrealGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "FBallGame.h"

using FString = std::string;
using int32 = int;

void getIntro()
{
	system("cls");
	std::cout << "Welcome to Bulls and Cows, a fun word game" << std::endl;
	std::cout << "Can you guess the 5 letter isogram I'm thinking of?: "<< std::endl;
};


int32 main()
{
	constexpr int32 MAXTRIES = 5;
	const FString HIDDEN_WORD = "plante"; 

	bool continuePlaying = true;
	while (continuePlaying) {
		FBallGame myGame(MAXTRIES,HIDDEN_WORD);
		getIntro();
		do {
			myGame.getGuess();
			myGame.checkGuessValidity();
			myGame.showResult();
			myGame.setCurrentTry();
		} while (!myGame.isGameOver());
		std::cout << std::endl << "Do you wanna replay?: ";
		char ctn = 'y';
		std::cin >> ctn;
		if (ctn == 'n')
			continuePlaying = false;
	}

    return 0;
}

