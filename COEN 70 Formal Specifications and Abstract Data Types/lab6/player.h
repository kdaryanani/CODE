#include <iostream>

using namespace std;

class Player { public:
Player();
virtual ~Player();
virtual int getGuess();
// Returns the players next guess, an integer between
// 0 and 99 (inclusive)
virtual void lastWasTooHigh(bool tooHigh);
// Called to inform the player that their last guess
// was too high (if the tooHigh argument is true) or
// too low (if the tooHigh argument is false)
virtual void opponentsGuess(int guess, bool tooHigh);
// Called to tell the player what the opponent's last
// guess was, and whether it was too high or too low.
virtual void reset();
// Called to reset the player at the end //of the game.
// Any stored state about the last guess //should be cleared
};

class HumanPlayer:virtual public Player{
public:
    HumanPlayer();
    ~HumanPlayer();
    int getGuess();
    void lastWasTooHigh(bool tooHigh);
    void opponentsGuess(int guess, bool tooHigh);
    void reset();
    int count;
	int lastguess;
};

class ComputerPlayer:virtual public Player{
public:
    ComputerPlayer();
    ~ComputerPlayer();
    int getGuess();
    void lastWasTooHigh(bool tooHigh);
    void opponentsGuess(int guess, bool tooHigh);
    int count;
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
    
    count++;
    return(rand() % (max-min) +min);;
}

HumanPlayer::HumanPlayer(){
    count=0;
}
ComputerPlayer::ComputerPlayer(){
    count=0;
    max=99;
    min=0;
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
    if(tooHigh==true){
        max=lastguess;
    }
    else
        min=lastguess;
}

void HumanPlayer::opponentsGuess(int guess, bool tooHigh){
    if(guess==-1)
        cout<<"Your opponent has not guessed yet" << endl;
    if(tooHigh==true){
        cout<<"Your opponent's last guess of " << guess << " was too high." < endl;
    }
    else
        cout<<"Your opponent's last guess of " << guess << " was too low." < endl;
}

void ComputerPlayer::opponentsGuess(int guess, bool tooHigh){
    if(guess=-1)
        return;
    if(tooHigh==true){
        if(lastguess<max)
            max==lastguess;
    }
    else
        if(lastguess>min)
            min==lastguess;
    
}

void HumanPlayer::reset(){
    count=0;
}

void ComputerPlayer::reset(){
    min=0;
    max=99;
    count=0;
}