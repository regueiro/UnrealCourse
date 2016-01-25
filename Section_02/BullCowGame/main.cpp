#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;

FBullCowGame BCGame;


//introduce the game
void PrintIntro()
{
	constexpr auto WORD_LENGTH = 9;

	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORD_LENGTH;
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

void PrintGuess(FText Guess)
{
	std::cout << "Your guess was " << Guess << std::endl;
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
		PrintGuess(Guess);
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