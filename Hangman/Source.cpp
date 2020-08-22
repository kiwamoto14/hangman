#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

int main() {
	int numLetter = 0;
	int numWrong = 0;

	char guess;
	string word;
	vector<char> guessedLet;

	bool win = false;

	cout << "Welcome to Hangman." << endl;
	cout << "Please enter the word you'd like to choose." << endl;
	cin >> word;

	while ((win == false) && (numWrong < 5)) {
		int count = 0;
		char userCont;
		bool found = false;
		bool exists = false;


		cout << "Press 'c' to continue. Press 'q' to quit." << endl << endl;
		cin >> userCont;

		if (userCont == 'c') {
			cout << "Guess your letter" << endl;
			cin >> guess;
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
					cout << "NumWrong: " << numWrong << endl;
				}
				cout << endl;
			}
			else {
				cout << "You have already guessed that letter." << endl;
			}
		}
	}

	if (win == true) {
		cout << "Congratulations! You won!" << endl;
	}
	else {
		cout << "Oh no! You lost!" << endl;
	}

	return 0;
}




