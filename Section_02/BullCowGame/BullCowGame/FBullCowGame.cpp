#include "FBullCowGame.h"

using FString = std::string;
using int32 = int;

FbullCowGame::FbullCowGame()
{
	Reset();
}

void FbullCowGame::Reset()
{
	constexpr int32 Max_Tries = 8;
	MyMaxTry = Max_Tries;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	return;
}

int32 FbullCowGame::GetMaxTries() const
{
	return MyMaxTry;
}

int32 FbullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

int32 FbullCowGame::GetHiddenWordLength() const
{
	return MyHiddenWord.length();
}

bool FbullCowGame::IsGameWon() const
{
	return false;
}

EGeussStatus FbullCowGame::checkGuessValidity(FString)
{
	if (false)
	{
		return EGeussStatus::Not_Isogram;
	}
	else if (false)
	{
		return EGeussStatus::Not_LowerCase;
	}
	else if (false)
	{
		return EGeussStatus::Wrong_Length;
	}
	else { return EGeussStatus::OK; }
}

FBullCowCount FbullCowGame::SubmitGuess(FString Guess)
{
	// increase number of tries
	MyCurrentTry++;

	// setup return variable
	FBullCowCount BullCowGame;

	//Iterate through the Geuss and hidden word
	int32 HiddenWordLength = MyHiddenWord.length();
	for (int32 i = 0; i < HiddenWordLength; i++)
	{
		for (int32 j = 0; j < HiddenWordLength; j++)
		{
			if (Guess[i] == MyHiddenWord[j])
			{
				if (i == j)
				{
					BullCowGame.Bulls++;
				}
				else
				{
					BullCowGame.Cows++;
				}
			}
		}
	}

	return BullCowGame;
}
