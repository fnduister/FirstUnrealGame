#pragma once
#include <string>

class BallGame
{
	std::string m_guess;
	int m_maxTries;
	int m_currentTry;
	unsigned m_cows;
	unsigned m_bulls;

public:

	explicit BallGame(int maxTries);
	void showResult();
	unsigned getCows() const;
	void setCows(unsigned cows);
	unsigned getBulls() const;
	void setBulls(unsigned bulls);
	static void reset();
	void getGuess();
	void setGuess(std::string guess);
	int getMaxTries() const;

	int getCurrentTry() const;
	void setCurrentTry();

	bool isGameWon();
	bool isGameOver() const;
	static bool checkGuessValidity(std::string);


private:
	

};
