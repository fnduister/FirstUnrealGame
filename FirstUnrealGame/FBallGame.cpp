#include "stdafx.h"
#include "FBallGame.h"
#include <iostream>

using FString = std::string;
using int32 = int;


FBallGame::FBallGame(int maxTries, FString hiddenWord) :
	m_maxTries(maxTries),
	m_hiddenWord(hiddenWord)
{
	m_currentTry = 0;
}

FString FBallGame::getHiddenWord() const
{
	return m_hiddenWord;
}

void FBallGame::setHiddenWord(const FString& hiddenWord)
{
	m_hiddenWord = hiddenWord;
}


void FBallGame::showResult() const
{

	std::cout << "vous avez " << m_count.cows <<"cows et " 
	<< m_count.bulls << " bulls" << std::endl;
}


void FBallGame::setCurrentTry()
{
	m_currentTry++;
}

bool FBallGame::isGameWon()
{
	return true;
}

bool FBallGame::isGameOver() const
{
	if (m_currentTry >= m_maxTries)
	{
		std::cout << "desole vous avez depasse le nombre d'essaie";
		return true;
	}
	return false;
}

bool FBallGame::checkGuessValidity() const
{
	bool ctn = true;
	int32 i = 0;

	while(ctn && i<m_guess.length())
	{
			for (int j = i + 1; j < m_guess.length(); j++)
			{
				if(m_guess[i] == m_guess[j])
				{
					ctn = false;
					break;
				}
			}
			i++;
	}

	return ctn;
}

FBowCowCount FBallGame::submitGuess(FString)
{
	for (int32 i = 0; i < m_hiddenWord.length(); i++)
	{
		for (int32 j = 0; j < m_guess.length(); j++)
		{
			if (m_guess[j] == m_hiddenWord[i])
			{
				if (j == i)
					m_count.cows++;
				m_count.bulls++;
			}
		}
	}
	getCurrentTry();
}

void FBallGame::setGuess(FString guess)
{
	m_guess = guess;
};

void FBallGame::getGuess()
{
	std::cout << "essaie n: "<< getCurrentTry() << std::endl;
	std::cout << "enter your guess: ";
	FString guess;
	std::cin >> guess;
	setGuess(guess);
}


void FBallGame::reset()
{
	std::cout << "alors que veux tu faire ce soir?";
}

int FBallGame::getMaxTries() const
{
	return m_maxTries;
}

int FBallGame::getCurrentTry() const
{
	return m_currentTry;
}
