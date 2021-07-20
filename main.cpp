//--------------------------------------------------------------------------------
// Knights Tour Program
// Author: Ian Dudder
//--------------------------------------------------------------------------------
// This program gives a solution to the Knights Tour puzzle. This puzzle requires
// a Knight piece from the game of chess to traverse the board and touch every
// square, but never the same one twice. The user is allowed to choose a square on
// the chessboard for the knight to start from. As the knight traverses the board,
// it will overwrite the empty spaces with a number representing which move it is
// on. Once a solution is found, the chessboard is printed to console along with
// the number of tries taken to complete the puzzle.
//--------------------------------------------------------------------------------

#include <iostream>
#include <iomanip>

using namespace std;

int tries = 0;
bool done = false;
const int BOARDSIZE = 8;
int board[BOARDSIZE][BOARDSIZE] = { { 0, 0, 0, 0, 0, 0, 0, 0 },
                                    { 0, 0, 0, 0, 0, 0, 0, 0 },
                                    { 0, 0, 0, 0, 0, 0, 0, 0 },
                                    { 0, 0, 0, 0, 0, 0, 0, 0 },
                                    { 0, 0, 0, 0, 0, 0, 0, 0 },
                                    { 0, 0, 0, 0, 0, 0, 0, 0 },
                                    { 0, 0, 0, 0, 0, 0, 0, 0 },
                                    { 0, 0, 0, 0, 0, 0, 0, 0 } };


//--------------------------------- outputBoard ----------------------------------
// Prints the chess board to console.
// Pre-condition:  none
// Post-condition: prints the chessboard to console.
void outputBoard()
{
    for (int row = 0; row < BOARDSIZE; row++) {
        for (int col = 0; col < BOARDSIZE; col++) {
            cout << setw(3) << board[row][col];
        }
        cout << endl;
    }
    cout << endl;
}


//-------------------------------- moveKnight ------------------------------------
// This function recursively calls itself to move the knight throughout the chess
// board to find a solution.
// Pre-condition:  Given a start row, start column, and the current move in the
//                 path.
// Post-condition: The chessboard is overwritten with the correct sequence of moves
//                 to solve the puzzle.
bool moveKnight(int row, int col, int moveNum)
{
    // Make sure current coordinates are on the board
    if (row >= 0 && row < BOARDSIZE && col >= 0 && col < BOARDSIZE) {
        board[row][col] = moveNum;                      // Mark the current move
        if (moveNum == 64) {
            done = true;
            return true;
        }
        tries++;                                        // Increment try counter
        bool successfulMove = false;

        // Try next move
        if (row - 1 >= 0 && col - 2 >= 0 && board[row - 1][col - 2] == 0) {
            successfulMove = moveKnight(row - 1,col - 2,moveNum + 1);
            if (!successfulMove) {
                board[row - 1][col - 2] = 0;
            }
        }

        if (row - 2 >= 0 && col - 1 >= 0 && board[row - 2][col - 1] == 0) {
            successfulMove = moveKnight(row - 2, col - 1, moveNum + 1);
            if (!successfulMove) {
                board[row - 2][col - 1] = 0;
            }
        }

        if (row - 2 >= 0 && col + 1 < BOARDSIZE && board[row - 2][col + 1] == 0) {
            successfulMove = moveKnight(row - 2, col + 1, moveNum + 1);
            if (!successfulMove) {
                board[row - 2][col + 1] = 0;
            }
        }

        if (row - 1 >= 0 && col + 2 < BOARDSIZE && board[row-1][col+2] == 0) {
            successfulMove = moveKnight(row - 1, col + 2, moveNum + 1);
            if (!successfulMove) {
                board[row - 1][col + 2] = 0;
            }
        }

        if (row + 1 < BOARDSIZE && col + 2 < BOARDSIZE && board[row + 1][col + 2] == 0) {
            successfulMove = moveKnight(row + 1, col + 2, moveNum + 1);
            if (!successfulMove) {
                board[row + 1][col + 2] = 0;
            }
        }

        if (row + 2 < BOARDSIZE && col + 1 < BOARDSIZE && board[row + 2][col + 1] == 0) {
            successfulMove = moveKnight(row + 2, col + 1, moveNum + 1);
            if (!successfulMove) {
                board[row + 2][col + 1] = 0;
            }
        }

        if (row + 2 < BOARDSIZE && col - 1 >= 0 && board[row + 2][col - 1] == 0) {
            successfulMove = moveKnight(row + 2, col - 1, moveNum + 1);
            if (!successfulMove) {
                board[row + 2][col - 1] = 0;
            }
        }

        if (row + 1 < BOARDSIZE && col - 2 >= 0 && board[row + 1][col - 2] == 0) {
            successfulMove = moveKnight(row + 1, col - 2, moveNum + 1);
            if (!successfulMove) {
                board[row + 1][col - 2] = 0;
            }
        }

        if (done) {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}




int main()
{
    int row = 0, col = 0, movNum = 1;
    outputBoard();
    cout << "Input starting coordinates for an 8 by 8 chessboard:\n";
    cout << "Row: ";
    cin >> row;
    cout << "Column: ";
    cin >> col;

    moveKnight(row, col, movNum);   // Call the function to solve the puzzle.

    cout << "It was solved after " << tries << " tries" << endl;
    cout << "Here's the solution" << endl;
    outputBoard();                  // Output the solution.

    return 0;
}




//======================Program Output=======================
//
// It was solved after 251825407 tries
// Here's the solution
//  1  8 11 16  3 18 13 64
// 10 27  2  7 12 15  4 19
// 53 24  9 28 17  6 63 14
// 26 39 52 23 62 29 20  5
// 43 54 25 38 51 22 33 30
// 40 57 42 61 32 35 48 21
// 55 44 59 50 37 46 31 34
// 58 41 56 45 60 49 36 47
//
// Press any key to continue . . .