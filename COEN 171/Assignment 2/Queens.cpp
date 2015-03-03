/*
 
 Created on 2/1/15 by Karan Daryanani
 
 This is my C++ implementation for the Queen, Rook, and Amazon problem solving for an NxN board. The constructiors set introductory values when the instance of the class is first created.The queen inherits from piece, as does rook and amazon, and the only functino that differs is menace. The implementation and explination is below.
 
 */

#include <iostream>
#include "Queens.h"

int N;

int Piece::row(){
    return r;
}

int Piece::column(){
    return c;
}

int Piece::getCounter(){
    return counter;
}

void Piece::place(const int x, const int y){
    r = x;
    c = y;
}

Piece::Piece(){
    board = new int [N];
    counter = 0;
}

Piece::~Piece(){
    delete [] board;
}

//Traverses by row and diagnolly
bool Queen::menaces(const Piece *p){
    
    for(int i = 0; i < column(); i++){
        int position = board[i];
        if(position == row() || position == row() - (column() - i) || position == row() + (column() - i) ){
            return true;
        }
    }
    return false;
}
//Self expanitory. This is Rooks way of seeing if it can attack the piece it is passed in. It traverses through the columnens and compares it with the given position, and returns a boolean based on that.
bool Rook::menaces(const Piece *p){
    
    for(int i = 0; i < column(); i++){
        int position = board[i];
        
        if(position == row())
        return true;
    }
    return false;
}
//Self expanitory. This is Amazons way of seeing if it can attack the piece it is passed in. It traverses through the columnens and compares it against the positions around it, and returns a boolean based on that.

bool Amazon::menaces(const Piece *p){ //Worked with others on comparison logic
    
    
    for(int i = 0; i < column(); i++){
        int position = board[i];
        if(i == column() + 2 && position == row() + 1)
        return true;
        if(i == column() - 2 && position == row() - 1)
        return true;
        if(i == column() - 2 && position == row() + 1)
        return true;
        if(i == column() + 2 && position == row() - 1)
        return true;
        if(i == column() + 1 && position == row() + 2)
        return true;
        if(i == column() -1 && position == row() - 2)
        return true;
        if(i == column() - 1 && position == row() + 2)
        return true;
        if(i == column() + 1 && position == row() - 2)
        return true;
        if(position == row() || position == row() - (column() - i) || position == row() + (column() - i)){
            return true;
        }
    }
    return false;
}

void Piece::solve(int D){ // Function simply solves the problem and places the queen recurively.
    if(D == N){ //Comparing N to columns.
        counter++;
    }else{
        for(int i = 0; i < N; i++){
            place(i, D);
            if(!(menaces(this))){
                board[D] = i;
                solve(D + 1);
            }
        }
    }
}

int main(){
    cout<<"What would you like your board size to be? "<<endl;
    cin>>N;
    
    Queen a;
    a.solve(0);
    cout<<"Queen Solutions : "<<a.getCounter()<<endl;
    
    Rook b;
    b.solve(0);
    cout<<"Rook Solutions: "<<b.getCounter()<<endl;
    
    Amazon c;
    c.solve(0);
    cout<<"Amazon Solutions: "<<c.getCounter()<<endl;
    
    return 0;
    
}
