#pragma once
#include <string>

using FString = std::string;
using int32 = int;

// All values initialised to zero;
struct FBowCowCount
{
	int32 cows = 0;
	int32 bulls = 0;
};

class FBallGame
{
	FString m_guess;
	int m_maxTries;
	int m_currentTry;
	FString m_hiddenWord;
	FBowCowCount m_count;

public:
	FString getHiddenWord() const;
	void setHiddenWord(const FString& hiddenWord);

	explicit FBallGame(int maxTries,FString hiddenWord);
	void showResult() const;
	
	static void reset();
	void getGuess();
	void setGuess(FString guess);
	int getMaxTries() const;

	int getCurrentTry() const;
	void setCurrentTry();

	bool isGameWon();
	bool isGameOver() const;
	bool checkGuessValidity() const;
	FBowCowCount submitGuess(FString);

private:
	

};
