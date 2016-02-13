#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EWordStatus
{
	Invalid,
	OK,
	Not_Isogram,
	Wrong_Lenght,
	Not_Lowercase
};

class FBullCowGame
{
public:
	FBullCowGame();

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	EWordStatus CheckGuessValidity(FString Guess) const;

	void Reset();
	FBullCowCount SubmitValidGuess(FString Guess);


private:
	int32 CurrentTry;
	int32 MaxTries;
	FString HiddenWord;
	bool bGameIsWon;

	bool IsIsogram(FString Word) const;
	bool IsLowerCase(FString Word) const;

};
