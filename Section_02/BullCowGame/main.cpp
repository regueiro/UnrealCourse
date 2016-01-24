#include <iostream>
#include <string>


//introduce the game
void PrintIntro()
{
	constexpr auto WORD_LENGTH = 9;

	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
}

std::string GetGess()
{
	// get a guess from the player
	std::cout << "Enter your guess: ";
	std::string Guess;
	getline(std::cin, Guess);

	return Guess;
}

void PrintGuess(std::string Guess)
{
	std::cout << "Your guess was " << Guess << std::endl;
	std::cout << std::endl;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? ";
	std::string Response = "";
	getline(std::cin, Response);

	return Response[0] == 'y' || Response[0] == 'Y';
}

void PlayGame()
{
	// loop until all turns are exausted
	constexpr auto TURNS = 5;
	for (auto i = 0; i < TURNS; i++) {
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