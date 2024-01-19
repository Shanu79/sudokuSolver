#include <bits/stdc++.h>
using namespace std;
int BOARD_SIZE=9;

bool validSudoku(int row, int col, int c, vector<vector<int>>& board)
{
   for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i][col] == c)
      return false;

    if (board[row][i] == c)
      return false;

    if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
      return false;
  }
  return true;
}

bool solveSudoku(vector<vector<int>>& sudokuBoard)
{
    for (int i = 0; i<BOARD_SIZE; i++)
    {
        for (int j=0; j<BOARD_SIZE; j++)
        {
            if(sudokuBoard[i][j]==0)
            {
                for(int c=1;c<=9;c++)
                {
                    if(validSudoku(i, j, c, sudokuBoard)){
                        sudokuBoard[i][j]=c;

                        if(solveSudoku(sudokuBoard)){
                            return true;
                        }
                        else sudokuBoard[i][j]=0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void printBoard(const vector<vector<int>>& board) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            cout << board[i][j] << " ";
            if ((j + 1) % 3 == 0 && j < BOARD_SIZE - 1) {
                cout << "| ";
            }
        }
        cout << endl;

        if ((i + 1) % 3 == 0 && i < BOARD_SIZE - 1) {
            cout << "------+-------+------" << endl;
        }
    }
}

int main() {
    vector<vector<int>> sudokuBoard(BOARD_SIZE, vector<int>(BOARD_SIZE, 0));

    cout << "Enter the Sudoku puzzle (use 0 for empty cells):\n";
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            cin >> sudokuBoard[i][j];
        }
    }

    cout << "\nOriginal Sudoku Puzzle:\n";
    printBoard(sudokuBoard);

    // Solve the Sudoku puzzle
    if (solveSudoku(sudokuBoard)) {
        cout << "\nSolved Sudoku Puzzle:\n";
        printBoard(sudokuBoard);
    } else {
        cout << "\nNo solution exists.\n";
    }

    return 0;
}