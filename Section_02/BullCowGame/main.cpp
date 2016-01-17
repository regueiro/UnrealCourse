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

// get a guess from the player
string GetGess()
{
	cout << "Enter your guess: ";
	string Guess;
	getline(cin, Guess);

	return Guess;
}

int main()
{
	PrintIntro();
	
	auto Guess = GetGess();
	// print the guess back to them
	cout << "Your guess was " << Guess << endl;

	return 0;
}