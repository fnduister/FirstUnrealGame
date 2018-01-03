#pragma once
#include <string>

using FString = std::string;
using int32 = int;

enum class EWordStatus
{
	Invalid_Status,
	OK,
	Not_Long_Enough,
	Not_Isogram,
	Too_Long,
	Not_LowerCase
};

enum class EDifficulty
{
	EASY = 1,
	HARD,
	VERY_HARD,
	IMPOSSIBLE,
	DEFAULT
};

// All values initialised to zero;
struct FBowCowCount
{
	int32 cows = 0;
	int32 bulls = 0;
};

class FBallGame
{
	FString m_guess;
	int32 m_maxTries;
	int32 m_currentTry;
	bool bGameWon;
	FString m_hiddenWord;
	FBowCowCount m_count;

public:
	FString getHiddenWord() const;
	void setHiddenWord(const FString& hiddenWord);

	explicit FBallGame(int maxTries);
	static void showResult(FBowCowCount);
	
	int32 getHiddenWordLenght() const;
	static void reset();
	void getGuess();
	void setGuess(FString);
	int getMaxTries() const;
	void getIntro() const;
	int getCurrentTry() const;
	void setCurrentTry();
	void ShowErrorStatus(EWordStatus) const;
	bool isGameOver() const;
	EWordStatus checkGuessValidity() const;
	FBowCowCount submitGuess();
	static EDifficulty ChooseDifficulty();
	void setDifficulty(EDifficulty);

private:
	bool isIsogram(FString) const;
	bool isLowerCase(FString) const;

};
