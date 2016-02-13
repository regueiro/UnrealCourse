#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

FBullCowGame BCGame;


//introduce the game
void PrintIntro()
{
	constexpr auto WORD_LENGTH = 9;

	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
}

FText GetGess()
{
	// get a guess from the player
	std::cout << "Try " << BCGame.GetCurrentTry() << ". Enter your guess: ";
	FText Guess;
	getline(std::cin, Guess);

	return Guess;
}

void PrintBullCowCount(BullCowCount Count)
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

		BullCowCount Count = BCGame.SubmitGuess(Guess);
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