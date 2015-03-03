# ifndef QUEEN_H
# define QUEEN_H

using namespace std;

class Piece{
    
public:
    Piece();
    int *board;
    int row();
    int column();
    int getCounter();
    void place(const int, const int);// place item on board
    void solve(int );
    virtual bool menaces(const Piece *p) = 0; // is Safe
    ~Piece();
private:
    int r;
    int c;
    int counter;
};


class Queen : public Piece{
    
public:
    virtual bool menaces(const Piece *p);
};

class Rook : public Piece{
    
public:
    virtual bool menaces(const Piece *p);
};

class Amazon : public Piece{
    
public:
    virtual bool menaces(const Piece *p);
    
};


#endif
