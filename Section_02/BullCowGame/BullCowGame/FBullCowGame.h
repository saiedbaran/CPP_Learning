#pragma once
#include <string>

class FbullCowGame
{
public:
	void Reset();
	int GetMaxTries();
	int GetCurrentTry();
	bool IsGameWon();
	bool checkGuessValidity(std::string); //TODO make a more rich return value.


private:
	int MyCurrentTry;
	int MyMaxTry;
};
