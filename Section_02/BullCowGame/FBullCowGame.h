#pragma once
#include <string>

class FBullCowGame
{
public:
	FBullCowGame();

	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset();
	bool CheckGuessValidity(std::string Guess);


private:
	int CurrentTry;
	int MaxTries;
	bool IsIsogram(std::string Word) const;
};
