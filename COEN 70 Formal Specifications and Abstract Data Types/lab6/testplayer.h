#include <iostream>

using namespace std;

class Player { public:
//bool tooHigh;
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
protected:
    int lastguess;

};

Player::Player() {}
Player::~Player(){}
Player::getGuess() {}
Player::lastWasTooHigh(bool tooHigh){}
Player::opponentsGuess(int guess, bool tooHigh);
Player::reset();

class HumanPlayer:virtual public Player{
public:
    HumanPlayer();
    ~HumanPlayer();
    int getguess();
    void lastWasTooHigh(bool tooHigh);
    void opponentsGuess(int guess, bool tooHigh);
    void reset();
    int count;
};

class ComputerPlayer::virtual public Player{
public:
    ComputerPlayer();
    ~ComputerPlayer();
    int getguess();
    void lastWasTooHigh(bool tooHigh);
    void opponentsGuess(int guess, bool tooHigh);
    int count;
    void reset();
private:
    int min;
    int max;
};

HumanPlayer::getGuess(){
    
    cout<<"Give us your guess between 0 and 99" << endl;
    cin<<lastguess;
    count++;
    return lastguess;
    
}

ComputerPlayer::getGuess(){
    lastguess=(rand() % (max-min) +min);
    count++;
    return lastguess;
}

HumanPlayer::HumanPlayer(){
    count=0;
    lastguess=-1;
    tooHigh=true;
}
ComputerPlayer::ComputerPlayer(){
    count=0;
    max=99;
    min=0;
    lastguess=-1;
    tooHigh=true;
}

HumanPlayer::~HumanPlayer{}
ComputerPlayer::~ComputerPlayer(){}

/*HumanPlayer::getguess(){
	
	if(value==lastguess)
		cout << My God you have won! " << endl;
		reset();
	else if(value<lastguess)
		tooHigh=true;
	else
		tooHigh=false;

	lastWasTooHigh(bool tooHigh);
	
}*/
	
HumanPlayer::lastWasTooHigh(bool tooHigh){
	if(tooHigh==true)
		cout << "Your guess is too high" << endl;
	else
		cout <<"Your guess is too low" << endl;
}
ComputerPlayer::lastWasTooHigh(bool tooHigh){
    if(tooHigh==true){
        max=lastguess;
    }
    else
        min=lastguess;
}

HumanPlayer::opponentsGuess(int guess, bool tooHigh){
    if(lastguess==-1)
        cout<<"Your opponent has not guessed yet" << endl;
    if(tooHigh==true){
        cout<<"Your opponent's last guess of " << guess << " was too high." < endl;
    }
    else
        cout<<"Your opponent's last guess of " << guess << " was too low." < endl;
}

ComputerPlayer::opponentsGuess(int guess, bool tooHigh){
    if(lastguess=-1)
        return;
    if(tooHigh==true){
        if(lastguess<max)
            max==lastguess;
    }
    else
        if(lastguess>min)
            min==lastguess;
    
}

HumanPlayer::reset(){
    lastguess=-1;
    count=0;
    
}

ComputerPlayer::reset(){
    lastguess=-1;
    min=0;
    max=99;
    count=0;
    
}