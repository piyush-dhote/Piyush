/*
Program Name: Rock Paper Scissor Game
In the game of rock paper scissors both players make a "throw" of either rock, paper or scissors, and the result of the game is decided with:

rock beats scissors
paper beats rock
scissors beats paper

all other states result in a draw, and the game is played again until there is a winner.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0))); // its for random number generation

    int player_throw, ai_throw;
    string choices[] = {"Rock", "Paper", "Scissors"};
    char play_again;

    do {
        bool game_over = false;

        while (!game_over) {
            // Get player input
            cout << "Choose your throw:\n1) Rock\n2) Paper\n3) Scissors\nEnter your choice: ";
            cin >> player_throw;

            // Validate input
            if (player_throw < 1 || player_throw > 3) {
                cout << "Invalid choice. Please select 1, 2, or 3.\n";
                continue;
            }

            // Generate AI's throw
            ai_throw = (rand() % 3) + 1;

            // Display choices
            cout << "You chose " << choices[player_throw - 1] << ".\n";
            cout << "AI chose " << choices[ai_throw - 1] << ".\n";

            // Determine result
            if (player_throw == ai_throw) {
                cout << "It's a draw! Try again.\n\n";
            } else if ((player_throw == 1 && ai_throw == 3) || 
                       (player_throw == 2 && ai_throw == 1) || 
                       (player_throw == 3 && ai_throw == 2)) {
                cout << "You win!\n";
                game_over = true;
            } else {
                cout << "You lose! Try again.\n\n";
            }
        }

        // Ask if the player wants to play again
        cout << "Do you want to play again? (y/n): ";
        cin >> play_again;
        cout << endl;

    } while (play_again == 'y' || play_again == 'Y');

    cout << "Thank you for playing! Goodbye!\n";

    return 0;
}
