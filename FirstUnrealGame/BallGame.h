#pragma once
#include <string>

class BallGame
{
	std::string m_guess;
	int m_maxTries;
	int m_currentTry;

public:
	BallGame(const std::string& guess, int maxTries, int currentTry);
	int currentTry() const;
	void currentTry(int currentTry);
	std::string getGuess() const;
	void setGuess(const std::string& guess);
	static void reset();
	int getMaxTries() const;
	bool isGameWon();
	bool checkGuessValidity(std::string);

private:
	

};
