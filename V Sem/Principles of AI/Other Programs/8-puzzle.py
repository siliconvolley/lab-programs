START = [
    [3, 7, 6],
    [5, 1, 2],
    [4, '', 8]
]

GOAL = [
    [5, 3, 6],
    [7, '', 2],
    [4, 1, 8]
]

matching_numbers = 0

def find_empty_location(board):
    for i in range(len(board)):
        for j in range(len(board[i])):
            if board[i][j] == '':
                return i, j

def move_up (board, empty_location):
    i, j = find_empty_location(board)
    if board[i+1][j]:
        board[i][j], board[i+1][j] = board[i+1][j], board[i][j]
    return board

def move_down(board, empty_location):
    i, j = find_empty_location(board)
    if board[i-1][j]:
        board[i][j], board[i-1][j] = board[i-1][j], board[i][j]
    return board

def move_left(board, empty_location):
    i, j = find_empty_location(board)
    if board[i][j+1]:
        board[i][j], board[i][j+1] = board[i][j+1], board[i][j]
    return board

def move_right(board, empty_location):
    i, j = find_empty_location(board)
    if board[i][j-1]:
        board[i][j], board[i][j-1] = board[i][j-1], board[i][j]
    return board

def check_matchin_numbers(board):
    current_matching_numbers = 0
    for i in range(len(board)):
        for j in range(len(board[i])):
            if board[i][j] == GOAL[i][j]:
                current_matching_numbers += 1
    return current_matching_numbers
    

def solve_board(board):
    check_matchin_numbers()
    

    return

def main():
    board = START
    solve_board()

if __name__ == "__main__":
    main()