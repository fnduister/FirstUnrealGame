#include "stdafx.h"
#include "BallGame.h"
#include <iostream>


BallGame::BallGame(const std::string& guess, int maxTries, int currentTry) :
	m_guess(guess),
	m_maxTries(maxTries),
	m_currentTry(currentTry)
{
	reset();
}

bool BallGame::isGameWon()
{
	return true;
}

bool BallGame::checkGuessValidity(std::string)
{
	return true;
}

std::string BallGame::getGuess() const
{
	return m_guess;
}

void BallGame::setGuess(const std::string& guess)
{
	m_guess = guess;
}

void BallGame::reset()
{
	std::cout << "alors que veux tu faire ce soir?";
}

int BallGame::getMaxTries() const
{
	return m_maxTries;
}
