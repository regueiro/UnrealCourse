#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

FBullCowGame BCGame;


//introduce the game
void PrintIntro()
{
std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
}

FText GetGess()
{
	FText Guess;
	EWordStatus Status;
	do  {
		// get a guess from the player
		std::cout << "Try " << BCGame.GetCurrentTry() << ". Enter your guess: ";
		
		getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status) {
		case EWordStatus::Wrong_Lenght:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word." << std::endl;
			break;
		case EWordStatus::Not_Isogram:
			std::cout << Guess << " is not an isogram. Please enter an isogram." << std::endl;
			break;
		case EWordStatus::Not_Lowercase:
			std::cout << Guess << " is not lowercase. Please enter all lowercase letters." << std::endl;
			break;
		default:
			break;
		}
		std::cout << std::endl;

	} while (Status != EWordStatus::OK);

	return Guess;
}

void PrintBullCowCount(FBullCowCount Count)
{
	std::cout << "Bulls: " << Count.Bulls << ", Cows: " << Count.Cows <<std::endl;
	std::cout << std::endl;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? ";
	FText Response = "";
	getline(std::cin, Response);

	return Response[0] == 'y' || Response[0] == 'Y';
}

void PlayGame()
{
	BCGame.Reset();

	// loop until all turns are exausted
	auto MaxTries = BCGame.GetMaxTries();
	for (auto i = 1; i <= MaxTries; i++) {
		auto Guess = GetGess();
		
		FBullCowCount Count = BCGame.SubmitValidGuess(Guess);
		PrintBullCowCount(Count);
	}
}

int main()
{
	bool KeepPlaying;

	do {
		PrintIntro();
		PlayGame();
		KeepPlaying = AskToPlayAgain();

	}  while (KeepPlaying);
		
	return 0;
}