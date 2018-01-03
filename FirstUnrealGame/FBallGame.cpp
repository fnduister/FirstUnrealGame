#include "stdafx.h"
#include "FBallGame.h"
#include <iostream>
#include <map>
#define TMap std::map

using FString = std::string;
using int32 = int;


FBallGame::FBallGame(int maxTries) :
	m_maxTries(maxTries)
{
	m_currentTry = 0;
	bGameWon = false;
	m_hiddenWord = "";
}

FString FBallGame::getHiddenWord() const
{
	return m_hiddenWord;
}

void FBallGame::setHiddenWord(const FString& hiddenWord)
{
	m_hiddenWord = hiddenWord;
}


void FBallGame::showResult(FBowCowCount count)
{

	std::cout << "you have " << count.cows << " cows and "
		<< count.bulls << " bulls" << std::endl << std::endl;
}


void FBallGame::setCurrentTry()
{
	m_currentTry++;
}


void FBallGame::getIntro() const
{
	system("cls");
	std::cout << "Welcome to Bulls and Cows, a fun word game\n" << std::endl;
};

//Game is over if you've reached the maximum number of tries or if you've found the hidden word
bool FBallGame::isGameOver() const
{
	if (m_currentTry >= m_maxTries)
	{
		std::cout << "desole vous avez depasse le nombre d'essaie" << std::endl;
		return true;
	}
	if(bGameWon)
	{
		std::cout << "Felicitation voua avez gagne!!!" << std::endl;
		return true;
	}
	return false;
}

int32 FBallGame::getHiddenWordLenght() const
{
	return m_hiddenWord.length();
}


EWordStatus FBallGame::checkGuessValidity() const
{
	if (!isLowerCase(m_guess))
		return EWordStatus::Not_LowerCase;

	if (m_guess.length() == m_hiddenWord.length()) {
		if (isIsogram(m_guess))
			return EWordStatus::OK;
		else
			return EWordStatus::Not_Isogram;
	}
	
	if (m_guess.length() < m_hiddenWord.length())
		return EWordStatus::Not_Long_Enough;
	else
		return EWordStatus::Too_Long;

}

FBowCowCount FBallGame::submitGuess()
{
	FBowCowCount count;
	for (unsigned i = 0; i < m_hiddenWord.length(); i++)
	{
		for (unsigned j = 0; j < m_guess.length(); j++)
		{
			if (m_guess[j] == m_hiddenWord[i])
			{
				if (j == i)
					count.cows++;
				else
				{
					count.bulls++;
				}
					
			}
		}
	}
	if (count.cows == getHiddenWordLenght())
		bGameWon = true;
	return count;
}

EDifficulty FBallGame::ChooseDifficulty()
{
	std::cout << "Choose your difficulty:" <<std::endl;
	std::cout << "1 - EASY" << std::endl;
	std::cout << "2 - HARD" << std::endl;
	std::cout << "3 - VERY HARD" << std::endl;
	std::cout << "4 - IMPOSSIBLE" << std::endl;
	int32 difficulty = 0;
	std::cout << "Your Choice: ";
	std::cin >> difficulty;
	std::cin.clear();
	std::cin.ignore(100, '\n');

	switch (difficulty)
	{
		case 1:
			return EDifficulty::EASY;
			break;
		case 2:
			return EDifficulty::HARD;
			break;
		case 3:
			return EDifficulty::VERY_HARD;
			break;
		case 4:
			return EDifficulty::IMPOSSIBLE;
			break;
		default:
			return EDifficulty::DEFAULT;
	}
}

void FBallGame::setDifficulty(EDifficulty difficulty)
{
	switch(difficulty)
	{
	case EDifficulty::EASY:
		m_hiddenWord = "you";
		m_maxTries = 5;
		break;
	case EDifficulty::HARD:
	case EDifficulty::DEFAULT:
		m_hiddenWord = "multi";
		m_maxTries = 10;
		break;
	case EDifficulty::VERY_HARD:
		m_hiddenWord = "portable";
		m_maxTries = 13;
		break;
	case EDifficulty::IMPOSSIBLE:
		m_hiddenWord = "compatible";
		m_maxTries = 10;
		break;
	default:
		break;
	}
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



void FBallGame::ShowErrorStatus(EWordStatus Status) const
{
	std::cout << "Statut Error: ";
	switch (Status)
	{
	case EWordStatus::Not_Long_Enough:
		std::cout << "Please enter a " << getHiddenWordLenght() << " letter word." << std::endl;
		break;
	case EWordStatus::Not_Isogram:
		std::cout << "This is not an isogram word." << std::endl;
		break;
	case EWordStatus::Too_Long:
		std::cout << "The word is too long. Please enter a " << getHiddenWordLenght() << " letter word." << std::endl;
		break;
	case EWordStatus::Not_LowerCase:
		std::cout << "All letters must be lowercase" << std::endl;
	default:
		break;
	}
	std::cout << std::endl;
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

bool FBallGame::isIsogram(FString Word) const
{
	if (Word.length() <= 1)
		return true;

	TMap<char, bool> LetterSeen;

	for(auto Letter: Word)
	{
		Letter = tolower(Letter);
		if (LetterSeen[Letter])
			return false;
		else
			LetterSeen[Letter] = true;
	}
	return true;
}

bool FBallGame::isLowerCase(FString Word) const
{
	for(auto Letter: Word)
		if (!islower(Letter))
			return false;
	return true;
}
