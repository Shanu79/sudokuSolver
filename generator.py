import random

def print_sudoku(board):
    for row in board:
        print(" ".join(map(str, row)))

def is_valid(board, row, col, num):
    # Check if the number is not present in the current row and column
    if num in board[row] or num in [board[i][col] for i in range(9)]:
        return False

    # Check if the number is not present in the current 3x3 grid
    start_row, start_col = 3 * (row // 3), 3 * (col // 3)
    for i in range(3):
        for j in range(3):
            if board[start_row + i][start_col + j] == num:
                return False

    return True

def solve_sudoku(board):
    for row in range(9):
        for col in range(9):
            if board[row][col] == 0:
                for num in range(1, 10):
                    if is_valid(board, row, col, num):
                        board[row][col] = num
                        if solve_sudoku(board):
                            return True
                        board[row][col] = 0  # Backtrack if the current choice does not lead to a solution
                return False  # No valid number found for this cell
    return True  # The puzzle is solved

def generate_sudoku():
    # Start with an empty 9x9 board
    board = [[0] * 9 for _ in range(9)]

    # Fill the board with a solution
    solve_sudoku(board)

    # Remove a few numbers to create the puzzle
    for _ in range(random.randint(12, 28)):  # Adjust the range for desired difficulty
        row, col = random.randint(0, 8), random.randint(0, 8)
        while board[row][col] == 0:
            row, col = random.randint(0, 8), random.randint(0, 8)
        board[row][col] = 0

    return board

if __name__ == "__main__":
    sudoku_puzzle = generate_sudoku()
    print("Generated Sudoku Puzzle:")
    print_sudoku(sudoku_puzzle)
