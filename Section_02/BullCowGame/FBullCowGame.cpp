#include "FBullCowGame.h"
#include <map>
#define TMap std::map

using int32 = int;

FBullCowGame::FBullCowGame()
{
	Reset();
}

void FBullCowGame::Reset()
{
	bGameIsWon = false;
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
	return bGameIsWon;
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


FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	CurrentTry++;

	FBullCowCount Count;

	for (int32 GuessChar = 0; GuessChar < Guess.length(); GuessChar++) {
		for (int32 HiddenWordChar = 0; HiddenWordChar < HiddenWord.length(); HiddenWordChar++) {
			if (Guess[GuessChar] == HiddenWord[HiddenWordChar]) {
				if (GuessChar == HiddenWordChar) {
					Count.Bulls++;
				}
				else {
					Count.Cows++;
				}

			}
		}
	}

	if (Count.Bulls == GetHiddenWordLength()) {
		bGameIsWon = true;
	} else {
		bGameIsWon = false;
	}

	return Count;
}

bool FBullCowGame::IsIsogram(FString Word) const
{
	TMap<char, bool> SeenLetter;

	for (char c : Word) {
		c = tolower(c);
		if (SeenLetter[c]) {
			return false;
		}
		else {
			SeenLetter[c] = true;
		}
	}

	return true;
}

bool FBullCowGame::IsLowerCase(FString Word) const
{
	for (char c : Word) {
		if (isupper(c) == true) {
			return false;
		}
	}
	return true;
}
