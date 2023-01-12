class Solution:
    def __init__(self, api):
        self.api = api
        print("Press run code to see this in the console!")
        # You can initiate and calculate things here

    def level_1_middle_square(self, board):
        """
        Return the string for the middle square; "X", "O" or "". The input
        'board' parameter represent all nine squares, the current board state,
        in a list with the first index, zero, in the bottom left (x=0, y=0).
        Index 1 is (x=1, y=0), index 2 is (x=2, y=0), index 3 is (x=0, y=1)
        and so forth. See the Description for a visual reference.
        
        :type board: List[string]
        
        :rtype: string
        """
        # Write your code here
        sz = len(board)
        return board[sz//2]

    def level_2_number_of_o(self, board):
        """
        Level 2 - Return the number of circles / "O" which are on the board.
        The input 'board' parameter represent all nine squares, the current
        board state, in a list with the first index, zero, in the bottom left
        (x=0, y=0). Index 1 is (x=1, y=0), index 2 is (x=2, y=0), index 3 is
        (x=0, y=1) and so forth. See the Description for a visual reference.
        
        :type board: List[string]
        
        :rtype: int
        """
        # Write your code here
        return len([x for x in board if x=="O"])

    def level_3_does_o_have_3_in_a_row(self, board):
        """
        Level 3 - Does circles / "O" have three in a row? The input 'board'
        parameter represent all nine squares, the current board state, in a
        list with the first index, zero, in the bottom left (x=0, y=0). Index
        1 is (x=1, y=0), index 2 is (x=2, y=0), index 3 is (x=0, y=1) and so
        forth. See the Description for a visual reference.
        
        :type board: List[string]
        
        :rtype: bool
        """
        # Write your code here
        inRow = [(0,1+3,2+6),(2,1+3,6)]
        for i in range(3):
            inRow.append((i,i+3,i+6))
            inRow.append((i*3,i*3+1,i*3+2))
        for x in inRow:
            if board[x[0]] == "O" and board[x[1]] == "O" and board[x[2]] == "O":
                return True
                
        return False
