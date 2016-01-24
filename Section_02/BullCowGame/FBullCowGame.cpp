#include "FBullCowGame.h"

FBullCowGame::FBullCowGame()
{
	Reset();
}

void FBullCowGame::Reset()
{
	MaxTries = 8;
	CurrentTry = 1;
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
