/*
Program Name: Tic Tac Toe Game
Tic Tac Toe is a two-player game where players alternately mark a 3x3 grid with "X" or "0", aiming to align three symbols in a row, column, or diagonal

Win: A player wins if they align three of their symbols (X or 0) horizontally, vertically, or diagonally on the 3x3 grid.

Lose: A player loses if the opponent achieves a winning alignment first.

Tie: The game ends in a tie if all grid cells are filled, and no player has achieved a winning alignment.
*/

#include <iostream>
using namespace std;

char space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int row;
int col;
char token = 'X';
string n1 = ""; 
string n2 = "";
bool tie = false;

// Function to initialize/reset the board
void initializeBoard() {
    char start = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            space[i][j] = start++;
        }
    }
    token = 'X'; // Reset token to 'X' for Player 1
    tie = false; // Reset tie flag
}

void functionOne() //display of board
{

    cout << "    |    |    \n";
    cout << " " << space[0][0] << "  | " << space[0][1] << "  | " << space[0][2] << " \n";
    cout << "____|____|____\n";
    cout << "    |    |    \n";
    cout << " " << space[1][0] << "  | " << space[1][1] << "  | " << space[1][2] << " \n";
    cout << "____|____|____\n";
    cout << "    |    |    \n";
    cout << " " << space[2][0] << "  | " << space[2][1] << "  | " << space[2][2] << " \n";
    cout << "    |    |    \n";
}

void functionTwo() //input validation
{

    int digit;

    if(token == 'X')
    {
        cout << n1 << " please enter a number (1-9): ";
        cin >> digit;
    }
    
    if (token == '0')
    {
        cout << n2 <<  " please enter a number (1-9): ";
        cin >> digit;
    }

    if (digit == 1)
    {
        row = 0;
        col = 0;
    }

    if (digit == 2)
    {
        row = 0;
        col = 1;
    }

    if (digit == 3)
    {
        row = 0;
        col = 2;
    }

    if (digit == 4)
    {
        row = 1;
        col = 0;
    }

    if (digit == 5)
    {
        row = 1;
        col = 1;
    }

    if (digit == 6)
    {
        row = 1;
        col = 2;
    }

    if (digit == 7)
    {
        row = 2;
        col = 0;
    }

    if (digit == 8)
    {
        row = 2;
        col = 1;
    }
    
    if (digit == 9)
    {
        row = 2;
        col = 2;
    }

    else if(digit<1 || digit>9)
    {
        cout << "Invalid input! Please enter a number between 1 and 9: " << endl;
    }  

    if (token == 'X' && space[row][col] != 'X' && space[row][col] != '0')
    {
        space[row][col] = 'X';
        token = '0';
    }

    else if (token == '0' && space[row][col] != 'X' && space[row][col] != '0')
    {
        space[row][col] = '0';
        token = 'X';
    }

    else{
        cout << "Cell already occupied! Choose a different cell: " << endl;
        functionTwo();
    }
}

bool functionThree()
{
    for(int i=0; i<3; i++)
    {
        if(space[i][0] == space[i][1] && space[i][0] == space[i][2] || space[0][i] == space[1][i] && space[0][i] == space[2][i]) //condition to check winner in horizontal or vertical way

        return true;
    }
    
    if(space[0][0] == space[1][1] && space[1][1] == space[2][2] || space[0][2] == space[1][1] && space[1][1] == space[2][0]) //condition to check winner in diagonal way
    {
        return true;
    }

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if (space[i][j] != 'X' && space[i][j] !='0') //condition to check if the game is still going on
            {
                return false;
            }
        }
    }

    tie = true;
    return false;
}

int main()
{
    char replay;

    cout << "Enter the name of the First Player: ";
    getline(cin, n1);
    cout << "Enter the name of the Second Player: ";
    getline(cin, n2);

    initializeBoard();

    cout << n1 << " is Player 1 (X), and " << n2 << " is Player 2 (0).\n";
    
    while (!functionThree())
    {
        functionOne();
        functionTwo();
        functionThree();
    }

    // Display the final board
    functionOne();

    // Announcing the Results
    if (token == 'X' && tie == false)
    {
        cout << "Hurray! " << n2 << " Wins!!!" << endl;
    }

    else if (token == '0' && tie == false)
    {
        cout << "Hurray! " << n1 << " Wins!!!" << endl;
    }

    else{
        cout << "It's a Draw!" << endl;
    }

    // Ask for replay
        cout << "Do you want to play again? (Y/N): ";
        cin >> replay;
        cin.ignore(); // Clear the newline character in the input buffer

    while (replay == 'Y' || replay == 'y');

    cout << "Thanks for playing! Goodbye.\n";
    return 0;
}