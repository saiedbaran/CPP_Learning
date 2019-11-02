#pragma once
#include <string>

class FbullCowGame
{
public:
	FbullCowGame(); // constructor

	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset();
	bool checkGuessValidity(std::string); //TODO make a more rich return value.


private:
	int MyMaxTry;
	int MyCurrentTry;
};
