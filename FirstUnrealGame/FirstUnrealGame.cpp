// FirstUnrealGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "BallGame.h"


void getIntro()
{
	std::cout << "Welcome to Bulls and Cows, a fun word game" << std::endl;
	std::cout << "Can you guess the 5 letter isogram I'm thinking of?: "<< std::endl;
};

void startGame()
{
	
}


int main()
{
	BallGame myGame(10);

	do{
		getIntro();
		myGame.getGuess();
	} while (myGame.isGameOver());
	
    return 0;
}

