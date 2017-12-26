#include "stdafx.h"
#include "BallGame.h"
#include <iostream>


BallGame::BallGame(int maxTries) :
	m_maxTries(maxTries)
{
	m_cows = 0;
	m_bulls = 0;
	m_currentTry = 0;
}

void BallGame::showResult()
{

	std::cout << "vous avez " << getCows() <<"cows et " << getBulls() << " bulls" << std::endl;
}


void BallGame::setCurrentTry()
{
	m_currentTry++;
}

bool BallGame::isGameWon()
{
	return true;
}

bool BallGame::isGameOver() const
{
	if (m_currentTry >= m_maxTries)
	{
		std::cout << "desole vous avez depasse le nombre d'essaie";
		return true;
	}
	return false;
}

bool BallGame::checkGuessValidity(std::string)
{
	return true;
}

void BallGame::setGuess(std::string guess)
{
	m_guess = guess;
};

void BallGame::getGuess()
{
	std::cout << "essaie n: "<< getCurrentTry() << std::endl;
	std::cout << "enter your guess: ";
	std::string guess;
	std::cin >> guess;
	setGuess(guess);
}

unsigned BallGame::getCows() const
{
	return m_cows;
}

void BallGame::setCows(unsigned cows)
{
	m_cows = cows;
}

unsigned BallGame::getBulls() const
{
	return m_bulls;
}

void BallGame::setBulls(unsigned bulls)
{
	m_bulls = bulls;
}

void BallGame::reset()
{
	std::cout << "alors que veux tu faire ce soir?";
}

int BallGame::getMaxTries() const
{
	return m_maxTries;
}

int BallGame::getCurrentTry() const
{
	return m_currentTry;
}
