#pragma once
#include <string>

class BallGame
{
	std::string m_guess;
	int m_maxTries;
	int m_currentTry;

public:

	BallGame(int maxTries, int currentTry = 0) :
		m_maxTries(maxTries),
		m_currentTry(currentTry)
	{
	}


	static void reset();
	std::string getGuess();
	void setGuess(std::string guess);
	int getMaxTries() const;
	int getCurrentTry() const;
	bool isGameWon();
	bool isGameOver();
	static bool checkGuessValidity(std::string);


private:
	

};
