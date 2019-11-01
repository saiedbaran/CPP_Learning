#include <iostream>
#include <string>
#include "main.h"
using namespace std;

void GetGuess();
void PrintIntro();
void PrintGuess();
bool PlayAgain();
void PlayGame();

constexpr int WORD_LENGTH = 5;
constexpr int Number_Of_Turns = 5;
string Guess = "";


// the entry point our applic
int main()
{
	bool bPlayAgain = false;
	do
	{
		PrintIntro();
		PlayGame();
		bPlayAgain = PlayAgain();
	} while (bPlayAgain);

    return 0; //exit application
}

void PlayGame()
{
	for (int i = 0; i < Number_Of_Turns; i++)
	{
		GetGuess();
		PrintGuess();
	}

	return;
}

// Introduce the Game
void PrintIntro()
{
	cout << "Welcome to Bulls and Cows Game, a fun word game!" << endl;
	std::cout << "Can you guess " << WORD_LENGTH << " letter isogram Im thinking of?" << std::endl;
	std::cout << std::endl;
	return;
}

// Get input from User
void GetGuess()
{
	string inputGuess;
    std::cout << "Please Enter your guess: ";
    std::getline(std::cin, inputGuess);
	Guess = inputGuess;
	return;
}
        
// Show the Output to the user
void PrintGuess()
{
    std::cout << "Your Guess is " << Guess << std::endl;
    std::cout << std::endl;
    return;
}

bool PlayAgain()
{
	std::cout << "Do you want to play again?(Y/N)";
	string Responce = "";
	getline(std::cin, Responce);
	
	if (Responce[0] == 'y' || Responce[0] == 'Y')
	{
		return true;
		std::cout << "Lets try Again!!!" << endl;
		std::cout << std::endl;
	}
	else
	{
		std::cout << "See you Later!" << endl;
		std::cout << std::endl;
		return false;
	}
}
