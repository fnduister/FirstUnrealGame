// FirstUnrealGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "FBallGame.h"

using FString = std::string;
using int32 = int;

int32 main()
{
	constexpr int32 MAXTRIES = 5;

	bool continuePlaying = true;
	while (continuePlaying) {
		FBallGame myGame(MAXTRIES);
		myGame.getIntro();

		EDifficulty const Difficulty = myGame.ChooseDifficulty();
		myGame.setDifficulty(Difficulty);

		std::cout << "\nCan you guess the " << myGame.getHiddenWordLenght() << " letter isogram I'm thinking of?: " << std::endl;
		std::cout << "You have " << myGame.getMaxTries() << " tries.\n\n";

		EWordStatus Status = EWordStatus::Invalid_Status;
		do {
			myGame.getGuess();
			Status = myGame.checkGuessValidity();
			if (Status == EWordStatus::OK)
			{
				FBowCowCount const myCountResult = myGame.submitGuess();
				myGame.showResult(myCountResult);
				myGame.setCurrentTry();
			}
			else 
				myGame.ShowErrorStatus(Status);		

		} while (!myGame.isGameOver());
		std::cout << std::endl << "Do you wanna replay?: ";
		char ctn = 'y';
		std::cin >> ctn;
		if (ctn == 'n')
			continuePlaying = false;
	}

    return 0;
}

