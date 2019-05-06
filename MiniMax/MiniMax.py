class MiniMax:
    def __init__(self, board, max_depth=4):
        self.__listed_indexes = board.segment_indexes
        self.__weights = [1, 8, 128, 99999]
        self.__max_depth = max_depth
        self.__evaluated = {}

    def miniMax(self, board, curr_sign, opponent_sign, depth=0):
        hashed_board = hash(board)

        if hashed_board in self.__evaluated:
            return None, self.__evaluated[hashed_board]

        if depth == self.__max_depth:
            score = self.__evaluate(board.board, curr_sign, opponent_sign)
            self.__evaluated[hashed_board] = score
            return None, score

        best_score = float('-inf')
        best_move = None

        for x in range(1, 8):
            move = x
            move_allowed, row = board.try_place_piece(move, curr_sign)

            if not move_allowed:
                continue

            game_over, winner = board.is_game_over(board.board, curr_sign,
                                                   opponent_sign, (move-1, row))
            if game_over:
                if winner == curr_sign:
                    best_subscore = 9999999999
                elif winner == opponent_sign:
                    best_subscore = -9999999999
                else:
                    best_subscore = 0
            else:
                best_submove, best_subscore = self.miniMax(board,
                                                             opponent_sign,
                                                             curr_sign,
                                                             depth + 1)
                best_subscore *= -1
            board.undo()

            if best_subscore > best_score:
                best_score = best_subscore
                best_move = move

        # Happens when max of depth exceeds number of possible moves
        if best_move is None:
            best_score = self.__evaluate(board.board, curr_sign, opponent_sign)

        self.__evaluated[hashed_board] = best_score

        return best_move, best_score

    def __evaluate(self, board, curr_sign, opponent_sign):

        curr_score = 0
        opp_score = 0

        for indexes in self.__listed_indexes:
            # indexes contains four board indexes as tuples

            curr_count = 0
            opp_count = 0

            for index in indexes:
                v = board[index[0]][index[1]]
                if v == curr_sign:
                    curr_count += 1
                elif v == opponent_sign:
                    opp_count += 1

            if curr_count > 0 and opp_count > 0:
                continue
            elif curr_count > 0:
                curr_score += curr_count * self.__weights[curr_count - 1]
            elif opp_count > 0:
                opp_score += opp_count * self.__weights[opp_count - 1]

        difference = curr_score - opp_score

        return difference

    def calculate_move(self, board, curr_sign, opponent_sign):
        move, score = self.miniMax(board, curr_sign, opponent_sign)
        print (score)
        return move

