from GameBoard import GameBoard
from Player import Human, Computer
import time

def play():
    select_mode()


# Asking for game mode
def select_mode():
    print("Welcome to Connect-4 With AI ")
    print("Please choose your game mode: ")
    print(" 1. Player vs Player")
    print(" 2. Player vs Computer AI")
    option = int(input())
    if option == 1:
        double_player_game()
    elif option == 2:
        single_player_game()


# This function is for Player vs Player
def double_player_game():
    board = GameBoard()
    print("Player 1: Please type in your name: ")
    player_name_1 = input()
    print("Player 2: Please type in your name: ")
    player_name_2 = input()

    player1 = Human('X', player_name_1)
    player2 = Human('O', player_name_2)

    current_player = player1
    other_player = player2
    winner = None
    game_over = False

    while not game_over:
        print(current_player.name, "Please select the column: [1-7]")
        print(board)
        move_allowed = False
        while not move_allowed:
            move = current_player.get_move(board, other_player)
            move_allowed = board.try_place_piece(move, current_player.sign)

        game_over, winner = board.is_game_over(board.board, current_player.sign, other_player.sign)
        current_player, other_player = other_player, current_player

    print(board)
    if winner:
        print("Player", other_player.name, "just won! Game over")
    else:
        print("Tie!")


# This function is for Player vs Computer
def single_player_game():
    board = GameBoard()
    print("Player 1: Please type in your name: ")
    player_name = input()
    player1 = Human('X',player_name)
    player2 = Computer('O', 6)
    print("Please select the column: [1-7]")

    current_player = player1
    other_player = player2

    winner = None
    game_over = False

    while not game_over:
        print(board)
        move_allowed = False
        while not move_allowed:
            start = time.time() # Get the start time
            move = current_player.get_move(board, other_player)
            move_allowed = board.try_place_piece(move, current_player.sign)

        game_over, winner = board.is_game_over(board.board, current_player.sign,
                                               other_player.sign)
        end = time.time() # Testing end time
        difference = end - start # Get the time from start to end
        current_player, other_player = other_player, current_player
        print("Computing Time: ", difference)
    print(board)
    if winner:
        print("Computer Won! Game over")
    else:
        print("Tie!")

play()
