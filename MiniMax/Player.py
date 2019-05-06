from MiniMax import MiniMax
class Human:

    def __init__(self, sign,name):
        self.sign = sign
        self.name = name

    def get_move(self, board, opponent):
        while True:
            move = input()
            if self.__is_valid(move, board):
                break
            print('Invalid column, please try again')

        return int(move)

    @staticmethod
    def __is_valid(move, board):
        try:
            move = int(move)
        except ValueError:
            return False

        return 0 < move <= board.width


class Computer:
    def __init__(self, sign, depth):
        self.sign = sign
        self.depth = depth

    def get_move(self, board, opponent):
        n = MiniMax(board, self.depth)
        move = n.calculate_move(board, self.sign, opponent.sign)
        return move
