
"""
    Created by Karan Daryanani on 2/1/2015
    This is the class layout to solve the N queens problem. With this class setup, we can simulate using the python command line an NxN board and find the solutions. My results are below.
    
    1x1 resulted in 1 solution
    2x2 resulted in 0 solution
    3x3 resulted in 0 solution
    4x4 resulted in 2 solution
    5x5 resulted in 10 solution
    6x6 resulted in 4 solution
    7x7 resulted in 40 solution
    8x8 resulted in 92 solution
    9x9 resulted in 352 solution
    10x10 resulted in 742 solution
    
"""
#Below is class Piece. It is a generic piece and if the requrements were to have not changed, It would be used more in depth so Amazon and Rook could inherit properties from it.
class Piece():
    
    def __init__(self):
        self.row = 0
        self.col = 0
    def getRow(self):
        return self.row
    def getColumn(self):
        return self.col
    def place(self,row,column):
        self.row = row
        self.column = column

# This is the Queen class that inherits from the Piece class. The containing function, Menace, checks if the current piece would be able to pounce on another piece.
class Queen(Piece):
    
    def menaces(self,pieces):
        row_dist = abs(self.row - piece.row)
        column_dist = abs(self.col - piece.col)
                
        if self.row == p.row and self.col == piece.col:
            return True
        if row_distance == 0 or col_distance == 0 or row_distance == col_distance:
            return True
        return False

