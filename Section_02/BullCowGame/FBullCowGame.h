#pragma once
#include <string>

class FBullCowGame
{
public:
	void Reset();
	int GetMaxTries();
	int GetCurrentTry();
	bool IsGameWon();
	bool CheckGuessValidity(std::string Guess);


private:
	int CurrentTry = 1;
	int MaxTries = 5;
	bool IsIsogram(std::string Word);
};
