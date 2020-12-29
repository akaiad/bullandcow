/* This is the console executable, that makes use of the BullCow class
This acts as the view in a MVC pattern, and is responsible for all
user interaction. For game logic see the FBullCowGame class.
*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>

#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;
using namespace std;
FBullCowGame BCGame; // instantiate a new game
void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();
void PrintGameSummary();
void setword();
  
int   main()
{
    bool bPlayAgain = false;
    do {
        system("CLS");
        PrintIntro();
        setword();
        PlayGame();
        bPlayAgain = AskToPlayAgain();
    } while (bPlayAgain);
   

    return 0;
}

 void PlayGame()
{
     BCGame.Reset();
    int32 MaxTries = BCGame.GetMaxTries();
    std::cout << "MaxTry = "<<MaxTries << std::endl;
     
     
     
     // loop for the number of turns asking for guesses
    //TODO change form for to while loop once we are validating tries
    // is NOT won and there are still tries remaining
    while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries) {
        FText Guess = GetValidGuess();

        // submit valid guess to the game, and receive counts
        FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
        std::cout << "Bulls = " << BullCowCount.Bulls;
        std::cout << ". Cows = " << BullCowCount.Cows << "\n\n";

      
    }

 //TODO summerise game
    PrintGameSummary();
    return;

}

void PrintIntro()
{

    std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
    std::cout << std::endl;
    std::cout << "          }   {         ___ " << std::endl;
    std::cout << "          (o o)        (o o) " << std::endl;
    std::cout << "   /-------\\ /          \\ /-------\\ " << std::endl;
    std::cout << "  / | BULL |O            O| COW  | \\ " << std::endl;
    std::cout << " *  |-,--- |              |------|  * " << std::endl;
    std::cout << "    ^      ^              ^      ^ " << std::endl;
   
    std::cout << "Easy    = 1\n";
    std::cout << "Medium  = 2\n";
    std::cout << "Hard    = 3\n\n";
    std::cout << "Choose difficulty:\n";
    int32 difficulty;
    std::cin >> difficulty;

    if (difficulty == 1)
    {

        BCGame.setDifficulty(1);
    }
    else if (difficulty == 2)
    {
        BCGame.setDifficulty(2);
    }

    else if (difficulty == 3)
    {
        BCGame.setDifficulty(3);
    }

    else
    {
        std::cout << "Enter Valid Number " << std::endl;

    }

        
 //   std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
 //   std::cout << " letter isogram I'm thinking of?\n";
    std::cout << std::endl;
    //intruduce the game
    
    return;

}



// loop continually until the user gives a valid guess
FText GetValidGuess()
{
    FText Guess = "";
    EGuessStatus Status = EGuessStatus::Invalid_Status;
    do {
        // get a guess from the player
        int32 CurrentTry = BCGame.GetCurrentTry();
        std::cout << "Try " << CurrentTry << " of " << BCGame.GetMaxTries();
        std::cout << ". Enter your guess: ";
        std::getline(std::cin, Guess);

        // check status and give feedback
        Status = BCGame.CheckGuessValidity(Guess);
        switch (Status) {
        case EGuessStatus::Wrong_Length:
            std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n\n";
            break;
        case EGuessStatus::Not_Isogram:
            std::cout << "Please enter a word witout repeating letters.\n\n";
            break;
        case EGuessStatus::Not_Lowercase:
            std::cout << "Please enter all lowercase letters.\n\n";
            break;
        default:
            // assume the guess is valid
            break;
        }
    } while (Status != EGuessStatus::OK); // keep looping until we get no errors
    return Guess;
}



bool AskToPlayAgain()
{
    std::cout << "Do you want to play again with the same hidden word (y/n) ";
    FText Response = "";
    getline(std::cin, Response);
    return (Response[0] == 'y') || (Response[0] == 'Y');

}

void PrintGameSummary()
{
    if (BCGame.IsGameWon())
    {
        std::cout << "WELL DONE - YOU WIN!\n";
    }
    else
    {
        std::cout << "Better luck nect time!\n";
    }
}


void setword()
{

    int32 difficulty = BCGame.GetDifficulty();
    if (difficulty == 1)
    {

        int linetoFind;
        int max_n = 5;
        int min_n = 1;
        int new_n;
        srand((int)time(0));
        new_n = ((rand() % (max_n + 1 - min_n)) + min_n);    //rand() returns random decimal number.

        linetoFind = new_n;

        string line;
        ifstream f("3.txt");
        for (int i = 0; i < linetoFind; i++)
        {
            getline(f, line);
        }
       
        BCGame.MyHiddenWord = line;
       
    }
    else if (difficulty == 2)
    {

        int linetoFind;
        int max_n = 5;
        int min_n = 1;
        int new_n;
        srand((int)time(0));
        new_n = ((rand() % (max_n + 1 - min_n)) + min_n);    //rand() returns random decimal number.

        linetoFind = new_n;

        string line;
        ifstream f("5.txt");
        for (int i = 0; i < linetoFind; i++)
        {
            getline(f, line);
        }

        BCGame.MyHiddenWord = line;
       
    }

    else if (difficulty == 3)
    {
        int linetoFind;
        int max_n = 5;
        int min_n = 1;
        int new_n;
        srand((int)time(0));
        new_n = ((rand() % (max_n + 1 - min_n)) + min_n);    //rand() returns random decimal number.

        linetoFind = new_n;

        string line;
        ifstream f("7.txt");
        for (int i = 0; i < linetoFind; i++)
        {
            getline(f, line);
        }

        BCGame.MyHiddenWord = line;
    }

    else
    {
       // std::cout << "Enter Valid Number " << std::endl;

    }

   

}

