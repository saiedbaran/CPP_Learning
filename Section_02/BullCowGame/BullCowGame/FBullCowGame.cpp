#include "FBullCowGame.h"

FbullCowGame::FbullCowGame()
{
	Reset();
}

void FbullCowGame::Reset()
{
	constexpr int Max_Tries = 8;
	MyMaxTry = Max_Tries;
	MyCurrentTry = 1;
	return;
}

int FbullCowGame::GetMaxTries() const
{
	return MyMaxTry;
}

int FbullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

bool FbullCowGame::IsGameWon() const
{
	return false;
}

bool FbullCowGame::checkGuessValidity(std::string)
{
	return false;
}
