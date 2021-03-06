/* The game logic (no view code or direct user interaction)
The game is a simple guess the word game based on Mastermind
*/

#pragma once
#include <string>

// to make syntax Unreal friendly
using FString = std::string;
using int32 = int;



// all values intialised to zero
struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus
{
	
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};




class FBullCowGame
{
public:
	FBullCowGame(); // constructor
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(FString Guess) const;
	int32 GetDifficulty();
	void setDifficulty(int s);
	
	
	

	void Reset();
	
	FBullCowCount SubmitValidGuess(FString);


	FString MyHiddenWord;
	//ignore this
private:
	// see constructor
	int32 MyCurrentTry;
	int32 MyMaxTries;
	int32 MyDifficulty;
	
	bool bGameIsWon;
	bool IsIsogram(FString) const;
	bool IsLowerCase(FString) const;;
};
