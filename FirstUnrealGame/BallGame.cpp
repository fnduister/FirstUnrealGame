#include "stdafx.h"
#include "BallGame.h"


bool BallGame::isGameWon()
{
	return true;
}

bool BallGame::checkGuessValidity(std::string)
{
	return true;
}

void BallGame::reset()
{
}

std::string BallGame::getGuess() const
{
	return m_guess;
}

int BallGame::getCurrentTry() const
{
	return m_currentTry;
}

int BallGame::getMaxTries() const
{
	return m_maxTries;
}
