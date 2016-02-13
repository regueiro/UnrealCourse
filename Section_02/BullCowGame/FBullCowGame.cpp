#include "FBullCowGame.h"

using int32 = int;

FBullCowGame::FBullCowGame()
{
	Reset();
}

void FBullCowGame::Reset()
{
	MaxTries = 8;
	CurrentTry = 1;

	HiddenWord = "planet";
}

int32 FBullCowGame::GetMaxTries() const
{
	return MaxTries;
}

int32 FBullCowGame::GetCurrentTry() const
{
	return CurrentTry;
}

int32 FBullCowGame::GetHiddenWordLength() const
{
	return HiddenWord.length();
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

EWordStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (!IsIsogram(Guess)) {
		return EWordStatus::Not_Isogram;
	}
	if (Guess.length() != GetHiddenWordLength()) {
		return EWordStatus::Wrong_Lenght;
	}
	if (!IsLowerCase(Guess)) {
		return EWordStatus::Not_Lowercase;
	}
	return EWordStatus::OK;
}


FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	CurrentTry++;

	FBullCowCount Count;

	for (int32 i = 0; i < Guess.length(); i++) {
		for (int32 j = 0; j < HiddenWord.length(); j++) {
			if (Guess[i] == HiddenWord[j]) {
				if (i == j) {
					Count.Bulls++;
				} else {
					Count.Cows++;
				}
				
			}
		}
	}

	return Count;
}

bool FBullCowGame::IsIsogram(FString Word) const
{
	return false;
}

bool FBullCowGame::IsLowerCase(FString Word) const
{
	for (int i = 0; i < Word.length(); i++)
	{
		char c = Word[i];
		if (isupper(c) == true)
		{
			return false;
		}
	}
	return true;
}
