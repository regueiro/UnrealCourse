#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct BullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame
{
public:
	FBullCowGame();

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	bool CheckGuessValidity(FString Guess) const;

	void Reset();
	BullCowCount SubmitGuess(FString Guess);


private:
	int32 CurrentTry;
	int32 MaxTries;
	FString HiddenWord;

	bool IsIsogram(FString Word) const;
};
