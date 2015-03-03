//
//  queen.c
//  
//
//  Created by Karan Daryanani on 1/26/15.
//
//

#include <stdio.h>
#include <stdbool.h>

void create(int chess_board[][8]) //Creates the new basic board before it is filled
{
    int i, j;
    for (i = 0; i < 8; ++i)
    {
        for (j = 0; j < 8; ++j)
        {
            chess_board[i][j] = 0;
        }
    }
}

/*If you are unable to safely place a queen in that column, go back to the previous column, and move that  queen down to the next row where it can safely be placed. Move on to the next column. */

bool verify(int chess_board[][8], int x, int y)
{
    int i, j;
    
    for (i = 0; i < y; i++)
        if (chess_board[x][i]) return 0;
    
    for (i = x, j = y; i > -1 && j >= 0; i--, j--)
        if (chess_board[i][j]) return 0;
    
    for (i = x, j = y; j > -1 && i < 8; i++, j--)
        if (chess_board[i][j]) return 0;
    
    return 1;
}

void print(int chess_board[][8]) // Prints the board with the elts
{
    for (int i = 0; i < 8; ++i){
        printf("\n");
        for (int j = 0; j < 8; ++j)
            printf("--%d--", chess_board[i][j]);
    }
    printf("\n");
}



bool move(int chess_board[][8], int x) // If a move is needed, it first verfies that a change need sto take place then it executed it
{
    if (x >= 8) return 1;
    
    for (int i = 0; i < 8; i++){
        if (verify(chess_board, i, x) ){
            chess_board[i][x] = 1;
            if (move(chess_board, x + 1)) return 1;
            chess_board[i][x] = 0;
        }
    }
    return 0;
}


int main() //runs program
{
    int chess_board[8][8];
    create(chess_board);
    if (!move(chess_board, 0)) printf("Invalid\n");
    print(chess_board);
    return 0;
}
