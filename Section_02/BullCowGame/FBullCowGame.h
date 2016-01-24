#pragma once
#include <string>

class FBullCowGame
{
public:
	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset();
	bool CheckGuessValidity(std::string Guess);


private:
	int CurrentTry = 1;
	int MaxTries = 5;
	bool IsIsogram(std::string Word) const;
};
