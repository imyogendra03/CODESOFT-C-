#include <iostream>
#include <vector>

using namespace std;

class TicTacToe {
public:
    TicTacToe() {
        board = vector<vector<char>>(3, vector<char>(3, ' '));
        currentPlayer = 'X';
        gameWon = false;
    }

    void playGame() {
        while (true) {
            displayBoard();
            playerInput();
            updateBoard();
            if (checkForWin()) {
                displayBoard();
                cout << "Player " << currentPlayer << " wins!" << endl;
                break;
            }
            if (checkForDraw()) {
                displayBoard();
                cout << "The game is a draw!" << endl;
                break;
            }
            switchPlayers();
        }
        if (playAgain()) {
            resetGame();
            playGame();
        }
    }

private:
    vector<vector<char>> board;
    char currentPlayer;
    bool gameWon;

    void displayBoard() {
        cout << "Current board state:" << endl;
        for (const auto &row : board) {
            for (const auto &cell : row) {
                cout << (cell == ' ' ? '.' : cell) << " ";
            }
            cout << endl;
        }
    }

    void playerInput() {
        int row, col;
        while (true) {
            cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            cin >> row >> col;
            if (row >= 1 && row <= 3 && col >= 1 && col <= 3 && board[row-1][col-1] == ' ') {
                board[row-1][col-1] = currentPlayer;
                break;
            } else {
                cout << "Invalid move. Please try again." << endl;
            }
        }
    }

    void updateBoard() {
        // No additional update logic needed since playerInput updates the board directly
    }

    bool checkForWin() {
        // Check rows
        for (const auto &row : board) {
            if (row[0] == currentPlayer && row[1] == currentPlayer && row[2] == currentPlayer) {
                return true;
            }
        }
        // Check columns
        for (int col = 0; col < 3; ++col) {
            if (board[0][col] == currentPlayer && board[1][col] == currentPlayer && board[2][col] == currentPlayer) {
                return true;
            }
        }
        // Check diagonals
        if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) {
            return true;
        }
        if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) {
            return true;
        }
        return false;
    }

    bool checkForDraw() {
        for (const auto &row : board) {
            for (const auto &cell : row) {
                if (cell == ' ') {
                    return false;
                }
            }
        }
        return true;
    }

    void switchPlayers() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    bool playAgain() {
        char response;
        cout << "Do you want to play again? (y/n): ";
        cin >> response;
        return (response == 'y' || response == 'Y');
    }

    void resetGame() {
        board = vector<vector<char>>(3, vector<char>(3, ' '));
        currentPlayer = 'X';
        gameWon = false;
    }
};

int main() {
    TicTacToe game;
    game.playGame();
    return 0;
}
