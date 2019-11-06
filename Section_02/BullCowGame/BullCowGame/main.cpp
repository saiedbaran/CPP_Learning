#include <iostream>
#include <string>
#include "main.h"
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void GetValidGuess();
void PrintIntro();
void PrintGuess();
bool PlayAgain();
void PlayGame();

constexpr int32 WORD_LENGTH = 5;
constexpr int32 Number_Of_Turns = 5;
FText Guess = "";

FbullCowGame BCGame; // Instantiate a new game


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
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	std::cout << "MaxTries: " << MaxTries << std::endl;
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
	{
		GetValidGuess();
		PrintGuess();

		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << " Cows = " << BullCowCount.Cows;
		std::cout << std::endl;
	}

	//FBullCowCount bullCowCount = BCGame.SubmitGuess();
	return;
}

// Introduce the Game
void PrintIntro()
{
	std::cout << "Welcome to Bulls and Cows Game, a fun word game!" << std::endl;
	std::cout << "Can you guess " << BCGame.GetHiddenWordLength() << " letter isogram Im thinking of?" << std::endl;
	std::cout << std::endl;
	return;
}

// Get input from User
void GetValidGuess()
{
	int32 CurrentTry = BCGame.GetCurrentTry();
	FText inputGuess;
	do
	{
		std::cout << "Try " << CurrentTry << "." << " Please Enter your guess: ";
		std::getline(std::cin, inputGuess);

		EGeussStatus GuessStatus = BCGame.checkGuessValidity(inputGuess);

		if (GuessStatus == EGeussStatus::Wrong_Length)
		{
			std::cout << "Please Enter " << BCGame.GetHiddenWordLength() << " isogram!\n\n";
		}
		else if (GuessStatus == EGeussStatus::Not_Isogram)
		{
			std::cout << "Please Enter Isogram!\n\n";
		}
		else if (GuessStatus == EGeussStatus::Not_LowerCase)
		{
			std::cout << "Please Enter Lower Case Isogram!\n\n";
		}
		else
		{
			Guess = inputGuess;
			return;
		}
	} while (true);
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
	FText Responce = "";
	std::getline(std::cin, Responce);

	if (Responce[0] == 'y' || Responce[0] == 'Y')
	{
		return true;
		std::cout << "Lets try Again!!!" << std::endl;
		std::cout << std::endl;
	}
	else
	{
		std::cout << "See you Later!" << std::endl;
		std::cout << std::endl;
		return false;
	}
}
