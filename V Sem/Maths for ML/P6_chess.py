#adi - 🍑
import math
def calculate_probability_of_winning():
    white_material_advantage = get_material_advantage('white')
    black_material_advantage = get_material_advantage('black')
    probability_white_wins = 1 / (1 + math.exp(black_material_advantage - white_material_advantage))
    probability_black_wins = 1 - probability_white_wins
    return probability_white_wins * 100, probability_black_wins * 100
def get_material_advantage(player):
    piece_values = {'pawn': 1, 'knight': 3, 'bishop': 3, 'rook': 5, 'queen': 9, 'king': 0}
    pieces = get_pieces(player)
    return sum(piece_values[piece] for piece in pieces)
def get_pieces(player):
    return ['pawn', 'pawn', 'pawn', 'pawn', 'pawn', 'pawn', 'pawn', 'rook', 'knight', 'bishop', 'queen', 'king'] if player == 'white' else ['pawn', 'pawn', 'pawn', 'pawn', 'pawn', 'pawn', 'pawn', 'pawn', 'rook', 'knight', 'bishop', 'king']
probability_white_wins, probability_black_wins = calculate_probability_of_winning()
print(f"Probability of white winning: {probability_white_wins:.2f}%")
print(f"Probability of black winning: {probability_black_wins:.2f}%")