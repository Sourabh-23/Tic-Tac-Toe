#include <iostream>
using namespace std;

char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char turn = 'X';

void displayBoard() {
    cout << "Tic Tac Toe Game" << "\n";
    cout << "Player 1 [X] - Player 2 [O]" << "\n\n";

    for (int i = 0; i < 3; ++i) {
        cout << " ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "---|---|---" << "\n";
    }
}

void playerTurn() {
    int choice;
    cout << "\n";
    if (turn == 'X')
        cout << "Player 1's turn [X]: ";
    else
        cout << "Player 2's turn [O]: ";

    cin >> choice;

    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if (choice < 1 || choice > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
        cout << "Invalid move! Please try again." << "\n";
        playerTurn();
    } else {
        board[row][col] = turn;
        turn = (turn == 'X') ? 'O' : 'X';
    }
}

char checkWin() {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
            return board[i][0];
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
            return board[0][i];
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
        return board[0][0];
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
        return board[0][2];

    return '\0'; // No winner yet
}

bool checkDraw() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false; // There's still an empty cell

    return true; // All cells are filled
}

int main() {
    while (true) {
        displayBoard();
        playerTurn();

        char winner = checkWin();
        if (winner != '\0') {
            displayBoard();
            cout << "Player " << winner << " wins!" << "\n";
            break;
        }

        if (checkDraw()) {
            displayBoard();
            cout << "It's a draw!" << "\n";
            break;
        }
    }

    return 0;
}
