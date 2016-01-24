#include <iostream>
#include <string>

using namespace std;

//introduce the game
void PrintIntro()
{
	constexpr auto WORD_LENGTH = 9;

	cout << "Welcome to Bulls and Cows, a fun word game.\n";
	cout << "Can you guess the " << WORD_LENGTH;
	cout << " letter isogram I'm thinking of?\n";
	cout << endl;
}

string GetGess()
{
	// get a guess from the player
	cout << "Enter your guess: ";
	string Guess;
	getline(cin, Guess);

	return Guess;
}

void PrintGuess(string Guess)
{
	cout << "Your guess was " << Guess << endl;
	cout << endl;
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
	PrintIntro();
	
	PlayGame();
	
	return 0;
}