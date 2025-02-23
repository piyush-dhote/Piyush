/*
Program Name: Number Guessing Game
(Example of a number guessing game in C++.)
*/

#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main()
{
    srand((unsigned int) time(NULL));
    char playAgain;

    do {
        int number = (rand() % 100) + 1; // Generate a new number for each game
        int guess = 0;
        int attempts = 0;

        cout << "Welcome to the Number Guessing Game!" << endl;

        do {
            cout << "Enter Guess (1-100): ";
            cin >> guess;

            // Input validation
            if (guess < 1 || guess > 100) {
                cout << "Please enter a number between 1 and 100." << endl;
                continue; // Skip the rest of the loop and prompt again
            }

            attempts++;

            if (guess > number) {
                cout << "Guess lower!" << endl;
            } else if (guess < number) {
                cout << "Guess higher!" << endl;
            } else {
                cout << "You won in " << attempts << " attempts!" << endl;
            }

        } while (guess != number);

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing!" << endl;
    return 0;
}