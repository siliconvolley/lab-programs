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



def move_up (board, empty_location):

def move_down(board, empty_location):

def move_left(board, empty_location):

def move_right(board, empty_location:

def main():
    board = START
    empty_location = [(i, row.index('')) for i, row in enumerate(GOAL) if '' in row]
    print(board(empty_location))

if __name__ == "__main__":
    main()