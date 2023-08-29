def is_safe(board, row, col, N):
    # Check if it is safe to place a queen at position (row, col)
    # Check for the same column
    for i in range(row):
        if board[i][col] == "Q":
            return False
        
    # Check for the upper left diagonal
    i = row - 1
    j = col - 1
    while i >= 0 and j >= 0:
        if board[i][j] == "Q":
            return False
        i -= 1
        j -= 1
    # Check for the upper right diagonal
    i = row - 1
    j = col + 1
    while i >= 0 and j < N:
        if board[i][j] == "Q":
            return False
        i -= 1
        j += 1
    return True

def solve_n_queens(board, row, N, solutions):
    # Base case: All queens have been placed
    if row == N:
        solutions.append([''.join(row) for row in board])
        return
    for col in range(N):
        if is_safe(board, row, col, N):
            board[row][col] = "Q"
            solve_n_queens(board, row + 1, N, solutions)
            board[row][col] = "."
    return

def n_queens_solver(N):
    board = [["." for _ in range(N)] for _ in range(N)]
    solutions = []
    solve_n_queens(board, 0, N, solutions)
    return solutions

def main():
    # Example usage
    N = 4
    solutions = n_queens_solver(N)
    if len(solutions) == 0:
        print("Not possible")
    else:
        for solution in solutions:
            for row in solution:
                print(row)
            print()

if __name__ == "__main__":
    main()