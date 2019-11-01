#pragma once

class FbullCowGame
{
public:
	void Reset();
	int GetMaxTries();

private:
	int MyCurrentTry;
	int MyMaxTry;
};
