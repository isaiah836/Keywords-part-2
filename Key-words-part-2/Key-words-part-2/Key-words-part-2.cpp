// Key-words-part-2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

int main()
{
	//setup
	//sets the variable to control the play again loop
	char again = 'n';
	string usersName;
	int simNumber = 1; // Keeps track of the simulation runs

	const int MAX_WRONG = 8; //maximum number of incorrect guesses allowed

	//collection of possible words to guess
	vector<string>words; 
	words.push_back("WALL");
	words.push_back("GLASSES");
	words.push_back("LABORED");
	words.push_back("PERSISTENT");
	words.push_back("SCRAMBLE");
	words.push_back("WELCOME");
	words.push_back("HAPPY");
	words.push_back("LAST");
	words.push_back("LONG");
	words.push_back("TOWEL");

	srand(static_cast<unsigned int>(time(0))); // seed the random generator
	int correct = 0; // number of words correctly guessed
	int missedWords = 0; //number of words missed by the user
	int totalIncorrect = 0; //total number of characters incorrectly guessed

	// Ask the recruit to login using thier name
	cout << "What is your name?\n";
	cin >> usersName;
	system("cls");
	
	// Display an overview of what Keywords II is to the recruit 
	cout << "Welcome " << usersName << " to the KeywordsII program.\n\n";
	cout << "The current automated programs that the CIA uses to decode enemy transmissions have always worked well until recently.\nRecently the enemy is using single scrambled low-tech keywords to signal other enemies\nto start attacks which our current code decryption programs have not been successful against.\n";
	cout << "This program will train you in unscrambling Low-Tech keywords.\n\n";
	
	//Starts the program
	cout << "Press enter to start the simulation.\n\n";
	system("pause");//used to give the user a chance to read the information
	system("cls"); // This is so there isn't to much on screen

	//main loop
	do
	{
		// Display the simulation # is staring to the recruit. 
		cout << usersName << "'s Simulation Run #" << simNumber;
		cout << "\n\nInstructions:\nYou will be given 3 words to guess and you only have 8 incorrect tries per word to guess the letters in the word.\n";
		cout << "You just enter the letter for your guess.\n";
		// Pick new 3 random words from your collection as the secret code word the recruit has to guess
		for (int i = 0; i < 3; ++i)
		{
			const string THE_WORD = words[rand() % 9]; //word to guess
			string soFar(THE_WORD.size(), '-'); //word guessed so far
			string used = ""; //letters already guessed
			int wrong = 0; // number of incorrect guesses
			int wordNumber = ++i; // keeps track of which word the user is on

			// Display an directions to the recruit on how to use Keywords
			
			cout << "If your guess was correct or not it will display on the top left.\n\n";
			cout << "Your on word #" << wordNumber;

			// While recruit hasn’t made too many incorrect guesses and hasn’t guessed the secret word
			while ((wrong < MAX_WRONG) && (soFar != THE_WORD))
			{
				//		Tell recruit how many incorrect guesses he or she has left
				cout << "\nYou have " << (MAX_WRONG - wrong) << " incorrect guesses left.\n";

				//		Show recruit the letters he or she has guessed
				cout << "\nYou've used the following letters:\n" << used << endl;

				//		Show player how much of the secret word he or she has guessed
				cout << "So far, the word is:\n" << soFar << endl;

				//     Get recruit's next guess
				char guess;
				cout << "\n\nEnter your guess: ";
				cin >> guess;
				guess = toupper(guess); // capitalizes the letter inputed by user
				system("cls"); //keeps the screen clean

				//While recruit has entered a letter that he or she has already guessed
				while (used.find(guess) != string::npos)
				{
					//Get recruit ’s guess
					cout << "\nYou've already guessed" << guess << endl;
					cout << "Enter yout guess: ";
					cin >> guess;
					guess = toupper(guess);
					system("cls");
				}

				//Add the new guess to the group of used letters
				used += guess;

				//checks to see if the letter guessed is in the secret word
				if (THE_WORD.find(guess) != string::npos)
				{
					//Tell the recruit the guess is correct
					cout << "That's right! " << guess << " is in the word.\n";

					//Update the word guessed so far with the new letter
					for (int j = 0; j < THE_WORD.length(); ++j)
					{
						if (THE_WORD[j] == guess)
						{
							soFar[j] = guess;
						}
					}
					
				}

				//Tell the recruit the guess is incorrect
				else
				{
					cout << "Sorry, " << guess << " isn't in the word.\n";
					//Increment the number of incorrect guesses the recruit has made
					++wrong;
					++totalIncorrect;
				}
			}
			// If the recruit has made too many incorrect guesses
			if (wrong == MAX_WRONG)
			{
				//Tell the recruit that he or she has failed to guess the word
				cout << "\nDarn! You ran out of guesses for that word.";
				++missedWords;
			}
			//Congratulate the recruit on guessing the secret words
			else
			{
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
				cout << "\n You Guessed it!" << endl;
				++correct;
			}

			cout << "The word was " << THE_WORD << endl;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		}
		cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		cout << usersName << "'s Scores:\n";
		cout << "Words Guessed Correctly: " << correct << endl;
		cout << "Words you missed: " << missedWords << endl;
		cout << "Total Characters guessed incorrectly: " << totalIncorrect << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
		// Ask the recruit if they would like to run the simulation again
		cout << "Would you like to play again?\n";
		cin >> again;
		//If the recruit wants to run the simulation again
		//Increment the number of simiulations ran counter
		++simNumber;
		system("cls"); // Clears screen for another run through

	} while (again == 'y');

	return 0;
}

