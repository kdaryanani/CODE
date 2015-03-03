//Karan Daryanani

#include <iostream>

using namespace std;

class Player { public:
    int count;
    Player();
    virtual ~Player();
     virtual int getGuess()=0;
    // Returns the players next guess, an integer between
    // 0 and 99 (inclusive)
     virtual void lastWasTooHigh(bool tooHigh)=0;
    // Called to inform the player that their last guess
    // was too high (if the tooHigh argument is true) or
    // too low (if the tooHigh argument is false)
     virtual void opponentsGuess(int guess, bool tooHigh)=0;
    // Called to tell the player what the opponent's last
    // guess was, and whether it was too high or too low.
     virtual void reset()=0;
    // Called to reset the player at the end //of the game.
    // Any stored state about the last guess //should be cleared
protected:
    int lastguess;
};

class HumanPlayer: public Player{
public:
    HumanPlayer();
    ~HumanPlayer();
    int getGuess();
    void lastWasTooHigh(bool tooHigh);
    void opponentsGuess(int guess, bool tooHigh);
    void reset();
   
	
};

class ComputerPlayer: public Player{
public:
    ComputerPlayer();
    ~ComputerPlayer();
    int getGuess();
    void lastWasTooHigh(bool tooHigh);
    void opponentsGuess(int guess, bool tooHigh);
    
    void reset();
private:
    int min;
    int max;
};

int HumanPlayer::getGuess(){
    
    cout<<"Give us your guess between 0 and 99" << endl;
    cin>>lastguess;
    count++;
    return lastguess;
    
}

int ComputerPlayer::getGuess(){
    //cout << "get guess starting" << endl;
    lastguess=rand();
    lastguess=lastguess % (max-min);
    lastguess+=min;
    cout << lastguess << endl;
    count++;
    return lastguess;
}

HumanPlayer::HumanPlayer(){
    count=0;
}
ComputerPlayer::ComputerPlayer(){
    count=0;
    max=99;
    min=0;
}
Player::Player(){
    
}
Player::~Player(){
    
}

HumanPlayer::~HumanPlayer(){}
ComputerPlayer::~ComputerPlayer(){}

void HumanPlayer::lastWasTooHigh(bool tooHigh){
	if(tooHigh==true)
		cout << "Your guess is too high" << endl;
	else
		cout <<"Your guess is too low" << endl;
}
void ComputerPlayer::lastWasTooHigh(bool tooHigh){
   //  cout << "last too high starting" << min << " . " << max << endl;
    if(tooHigh==true){
        cout << "Computers guess is too high" << endl;
        max=lastguess;
    }
    else if(tooHigh==false){
        cout << "Computers guess is too low" << endl;
        min=lastguess;
    }
}

void HumanPlayer::opponentsGuess(int guess, bool tooHigh){
    if(guess==-1)
        cout<<"Your opponent has not guessed yet" << endl;
    else if(tooHigh==true){
        cout<<"Your opponent's last guess of " << guess << " was too high." << endl;
    }
    else
        cout<<"Your opponent's last guess of " << guess << " was too low." << endl;
}

void ComputerPlayer::opponentsGuess(int guess, bool tooHigh){
    // cout << "opponent guess  starting" << min << " . " << max << endl;
    if(guess==-1)
        return;
    if(tooHigh==true){
        if(guess<max)
            max=guess;
    }
    else
        if(guess>min)
            min=guess;
    
}

void HumanPlayer::reset(){
    count=0;
}

void ComputerPlayer::reset(){
    min=0;
    max=99;
    count=0;
}