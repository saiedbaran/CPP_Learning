#pragma once
#include <string>
#include <map>
#define TMap std::map

using FString = std::string;
using int32 = int;

// All variables initialized to zero
struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGeussStatus
{
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_LowerCase
};

class FbullCowGame
{
public:
	FbullCowGame(); // constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength();
	bool IsGameWon() const;

	EGeussStatus checkGuessValidity(FString); //TODO make a more rich return value.

	void Reset();
	FBullCowCount SubmitValidGuess(FString);


private:
	int32 MyMaxTry;
	int32 MyCurrentTry;
	FString MyHiddenWord;
	bool bGameIsWon;
	
	bool IsIsogram(FString) const;
};
