#pragma once
#include <string>

class BallGame
{
	std::string m_guess;
	int m_maxTries;
	int m_currentTry;

public:

	BallGame(const std::string& guess, int maxTries, int currentTry, std::string name) :
		m_guess(guess),
		m_maxTries(maxTries),
		m_currentTry(currentTry)
	{
	}

	
	void reset();
	std::string getGuess() const;
	int getMaxTries() const;
	int getCurrentTry() const;
	bool isGameWon();
	bool checkGuessValidity(std::string);

private:
	

};
