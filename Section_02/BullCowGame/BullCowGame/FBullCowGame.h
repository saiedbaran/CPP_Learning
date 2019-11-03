#pragma once
#include <string>

using FString = std::string;
using int32 = int;

// All variables initialized to zero
struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FbullCowGame
{
public:
	FbullCowGame(); // constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset();
	bool checkGuessValidity(FString); //TODO make a more rich return value.
	FBullCowCount SubmitGuess(FString);


private:
	int32 MyMaxTry;
	int32 MyCurrentTry;
	FString MyHiddenWord;
};
