// FirstUnrealGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"


int main()
{
	std::cout << "Welcome to Bulls and Cows, a fun word game";
	std::cout << "Can you guess the 5 letter isogram I'm thinking of?: " << std::endl;
	char guess[5];
	std::cin >> guess;
    return 0;
}

