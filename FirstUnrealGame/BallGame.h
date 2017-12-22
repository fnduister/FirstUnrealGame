#pragma once
#include <string>

class BallGame
{
	std::string m_guess;
	int m_maxTries;
	int m_currentTries;
	std::string m_name;
	std::string m_base;

public:

	BallGame(const std::string& guess, int maxTries, int currentTries, std::string name) :
		m_guess(guess),
		m_maxTries(maxTries),
		m_currentTries(currentTries),
		m_name(name)
	{
	}

	void reset();

	std::string getGuess() const
	{
		return m_guess;
	}

	int getMaxTries() const
	{
		return m_maxTries;
	}

	int getCurrentTries() const  
	{
		return m_currentTries;
	}
	
	std::string getName() const
	{
		return m_name;
	}

	void setName(const std::string& name)
	{
		m_name = name;
	}

private:
	

};
