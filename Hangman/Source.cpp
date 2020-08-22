#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <stdlib.h>
#include <cctype>
using namespace std;

void lower(string& userword);

int main() {

	system("Color 0B"); // change color

	int numLetter = 0;
	int numWrong = 0;

	bool oneWord = false;
	char guess;
	string word;
	vector<char> guessedLet;

	bool win = false;

	cout << "Welcome to Hangman!" << endl;
	
	while (oneWord == false) {
		oneWord = true;
		cout << "Please enter the word you'd like to choose." << endl;
		cin >> word;
		for (int i = 0; i < word.length(); i++) {
			if (word.at(i) == ' ') {
				oneWord = false;
			}
		}
		if (oneWord == false) {
			cout << "Please do not enter more than one word." << endl;
		}
	}

	lower(word);
	//cout << word << endl;
	system("cls"); //clear screen

	while ((win == false) && (numWrong < 5)) {
		int count = 0;
		bool found = false;
		bool exists = false;

		cout << "Guess your letter" << endl;
		cin >> guess;
		guess = tolower(guess);

		for (char& x : guessedLet) {
			if (guess == x) {
				exists = true;
			}
		}

		if (exists == false) {
			guessedLet.push_back(guess);

			for (int i = 0; i < word.length(); i++) {
				if (word.at(i) == guess) {
					count++;
					found = true;
				}
			}

			if (found == true) {
				cout << "Correct!" << endl;
				numLetter += count;
				if (numLetter == word.length()) {
					win = true;
				}
			}
			else {
				cout << "Incorrect!" << endl;
				numWrong++;
				//cout << "NumWrong: " << numWrong << endl;
			}
			cout << endl;
		}
		else {
			cout << "You have already guessed that letter." << endl;
		}
	}

	if (win == true) {
		cout << "Congratulations! You won!" << endl;
	}
	else {
		cout << "Oh no! You lost!" << endl;
		cout << "The correct answer was: " << word << endl;
	}

	return 0;
}

void lower(string& userword) {
	for (char& x: userword) {
		x = tolower(x);
	}
}




