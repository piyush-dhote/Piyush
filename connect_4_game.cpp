#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// Constants for the game
const int ROWS = 6;         // Number of rows
const int COLS = 7;         // Number of columns
const char EMPTY = ' ';     // Empty cell
const char PLAYER1 = 'X';   // Player 1's token
const char PLAYER2 = 'O';   // Player 2's token

// Function to print the current game board
void printBoard(const vector <vector <char> > & board)
{
    for (int i = 0; i < ROWS; ++i) 
    {
        for (int j = 0; j < COLS; ++j) 
        {
            cout << "| " << board[i][j] << " ";
        }
        cout << "|\n";
    }

    cout << "-----------------------------\n";
    cout << "| 1 | 2 | 3 | 4 | 5 | 6 | 7 |\n";
    cout << "-----------------------------\n";
}

// Function to check if a column is valid for a move
bool isValidMove(const vector <vector <char> > & board, int col) 
{
    return col >= 0 && col < COLS && board[0][col] == EMPTY;
}

// Function to drop a player's token into a column
void makeMove(vector <vector <char> > & board, int col, char player) 
{
    for (int i = ROWS - 1; i >= 0; --i) 
    {
        if (board[i][col] == EMPTY) 
        {
            board[i][col] = player;
            break;
        }
    }
}

// Function to check if the board is full (tie condition)
bool isBoardFull(const vector <vector <char> > & board) 
{
    for (int i = 0; i < COLS; ++i) 
    {
        if (board[0][i] == EMPTY) 
        {
            return false;
        }
    }
    return true;
}

// Function to check if a player has won
bool checkWin(const vector <vector <char> > & board, char player) 
{
    // Check horizontal win
    for (int i = 0; i < ROWS; ++i) 
    {
        for (int j = 0; j <= COLS - 4; ++j) 
        {
            if (board[i][j] == player && board[i][j + 1] == player && board[i][j + 2] == player && board[i][j + 3] == player) 
            {
                return true;
            }
        }
    }

    // Check vertical win
    for (int i = 0; i <= ROWS - 4; ++i) 
    {
        for (int j = 0; j < COLS; ++j) 
        {
            if (board[i][j] == player && board[i + 1][j] == player && board[i + 2][j] == player && board[i + 3][j] == player) 
            {
                return true;
            }
        }
    }

    // Check diagonal win (top-left to bottom-right)
    for (int i = 0; i <= ROWS - 4; ++i) 
    {
        for (int j = 0; j <= COLS - 4; ++j) 
        {
            if (board[i][j] == player && board[i + 1][j + 1] == player && board[i + 2][j + 2] == player && board[i + 3][j + 3] == player) 
            {
                return true;
            }
        }
    }

    // Check diagonal win (bottom-left to top-right)
    for (int i = 3; i < ROWS; ++i) 
    {
        for (int j = 0; j <= COLS - 4; ++j) 
        {
            if (board[i][j] == player && board[i - 1][j + 1] == player && board[i - 2][j + 2] == player && board[i - 3][j + 3] == player) 
            {
                return true;
            }
        }
    }

    return false;
}

// Function to get a valid column input from the user
int getValidInput(const vector <vector <char> > & board) 
{
    int col;
    while (true) 
    {
        cin >> col;
        if (cin.fail() || col < 1 || col > 7 || !isValidMove(board, col - 1)) 
        {
            cin.clear(); // Clear input stream error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input. Please enter a column number (1-7) that is not full: ";
        } 
        else {
            break;
        }
    }
    return col - 1; // Convert 1-based input to 0-based index
}

// Main game function
void playConnectFour() 
{
    char replay;
    int scorePlayer1 = 0;
    int scorePlayer2 = 0;

    do 
    {
        // Initialize the game board
        vector <vector <char> > board(ROWS, vector<char>(COLS, EMPTY));
        bool player1Turn = true;

        cout << "Welcome to Connect Four!\n";
        cout << "Player " << PLAYER1 << " (X) vs. Player " << PLAYER2 << " (O)\n";

        while (true) 
        {
            printBoard(board);
            char currentPlayer = player1Turn ? PLAYER1 : PLAYER2;
            cout << "Player " << currentPlayer << ", enter your move (1-7): ";

            int col = getValidInput(board);
            makeMove(board, col, currentPlayer);

            if (checkWin(board, currentPlayer)) 
            {
                printBoard(board);
                cout << "Player " << currentPlayer << " wins! 🎉\n";
                if (currentPlayer == PLAYER1) 
                {
                    scorePlayer1++;
                } 
                else {
                    scorePlayer2++;
                }
                break;
            }

            if (isBoardFull(board)) 
            {
                printBoard(board);
                cout << "It's a tie!\n";
                break;
            }

            player1Turn = !player1Turn; // Switch turn
        }

        // Display scores
        cout << "Scores:\n";
        cout << "Player " << PLAYER1 << " (X): " << scorePlayer1 << "\n";
        cout << "Player " << PLAYER2 << " (O): " << scorePlayer2 << "\n";

        // Replay prompt
        cout << "Do you want to play again? (Y/N): ";
        cin >> replay;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

    } 
    while (replay == 'Y' || replay == 'y');

    cout << "Thanks for playing! Final Scores:\n";
    cout << "Player " << PLAYER1 << " (X): " << scorePlayer1 << "\n";
    cout << "Player " << PLAYER2 << " (O): " << scorePlayer2 << "\n";
    cout << "Goodbye!\n";
}

// Main function
int main() 
{
    playConnectFour();
    return 0;
}