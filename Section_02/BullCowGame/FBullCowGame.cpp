#include "FBullCowGame.h"

void FBullCowGame::Reset()
{
}

int FBullCowGame::GetMaxTries()
{
	return MaxTries;
}

int FBullCowGame::GetCurrentTry()
{
	return CurrentTry;
}

bool FBullCowGame::IsGameWon()
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(std::string Guess)
{
	return false;
}

bool FBullCowGame::IsIsogram(std::string Word)
{
	return false;
}
