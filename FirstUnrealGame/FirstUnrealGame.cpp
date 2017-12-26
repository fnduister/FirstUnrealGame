// FirstUnrealGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "BallGame.h"


void getIntro()
{
	system("cls");
	std::cout << "Welcome to Bulls and Cows, a fun word game" << std::endl;
	std::cout << "Can you guess the 5 letter isogram I'm thinking of?: "<< std::endl;
};


int main()
{
	constexpr int MAXTRIES = 5;
	

	bool continuePlaying = true;
	while (continuePlaying) {
		BallGame myGame(MAXTRIES);
		getIntro();
		do {
			myGame.getGuess();
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

