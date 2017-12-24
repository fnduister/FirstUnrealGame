#include "stdafx.h"
#include "BallGame.h"
#include <iostream>


bool BallGame::isGameWon()
{
	return true;
}

bool BallGame::isGameOver()
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

std::string BallGame::getGuess()
{
	std::cout << "enter your guess: ";
	char guess[5];
	std::cin >> guess;
	std::cout << "your guess was : " << guess << std::endl;
	setGuess(guess);
	m_maxTries = 5;
	return guess;
}

void BallGame::setGuess(std::string guess)
{
	m_guess = guess;
}

int BallGame::getCurrentTry() const
{
	return m_currentTry;
}

int BallGame::getMaxTries() const
{
	return m_maxTries;
}
