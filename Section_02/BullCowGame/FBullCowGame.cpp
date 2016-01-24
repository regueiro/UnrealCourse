#include "FBullCowGame.h"

void FBullCowGame::Reset()
{
}

int FBullCowGame::GetMaxTries() const
{
	return MaxTries;
}

int FBullCowGame::GetCurrentTry() const
{
	return CurrentTry;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(std::string Guess)
{
	return false;
}

bool FBullCowGame::IsIsogram(std::string Word) const
{
	return false;
}
