//Karan Daryanani
#include "player.h"

int answer;
bool High;
int guess;
void Play(Player*, Player*);
Player *p1;
Player *p2;


int main(){
    int x=0;
    srand (time(NULL));
    
	while(1){
        cout<< "Who would you like to play. Enter 1 for human vs human, enter 2 for human vs computer, or enter 3 for computer vs computer. enter anything else to quit" << endl;
        cin >> x;
        answer=rand()%100;
		guess=-1;
        
        switch(x){
                
            case 1: //each case has localized initializations and the cases are easily read. 
            {   HumanPlayer human1;
                HumanPlayer human2;
                cout << " You've chosen Human vs Human." << endl;
                p1=&human1;
                p2=&human2;
                Play(p1, p2);
				break; }
                
            case 2:
            {   HumanPlayer human1;
                ComputerPlayer computer2;
                cout << " You've chosen Human vs Computer." << endl;
                p1=&human1;
                p2=&computer2;
				Play(p1, p2);
                break; }
                
            case 3:
            {   ComputerPlayer computer1;
                ComputerPlayer computer2;
                cout << " You've chosen Computer vs Computer." << endl;
                p1=&computer1;
                p2=&computer2;
				Play(p1, p2);
                break; }
                
            default:
				cout << " Goodbye!" << endl;
                return 0;
        }
    }
	return 1;
}


void Play(Player *player1, Player *player2){ //Function Play initiates gameplay sequence from any order
    while(1){
        p1->opponentsGuess(guess, High); //by using pointers we are able to basically create a template
        guess=p1->getGuess();
        if(guess==answer){
            cout<<"Player 1 has won the game with the correct guess of "<< guess << endl;
            cout<<"Player 1 took "<< p1->count <<" guesses to guess the right answer!"<< endl;
            p1->reset();
            p2->reset();
            return;
        }
        
        if(guess>answer)
            High=true;
        else
            High=false;
        p1->lastWasTooHigh(High);
        
        p2->opponentsGuess(guess, High);
        guess=p2->getGuess();
        if(guess==answer){
            cout<<"Player 2 has won the game with the correct guess of "<< guess << endl;
            cout<<"Player 2 took "<< p2->count <<" guesses to guess the right answer!"<< endl;
            p1->reset();
            p2->reset();
            return;
        }
        
        if(guess>answer)
            High=true;
        else if (guess<answer)
            High=false;
        p2->lastWasTooHigh(High);
        
    }
}
/*
void hvc(){
    while(1){
        human1.opponentsGuess(guess, High);
        guess=human1.getGuess();
        if(guess==answer){
            cout<<"Human 1 has won the game with the correct guess of "<< guess << endl;
            cout<<"Human 1 took "<< human1.count <<" guesses to guess the right answer!"<< endl;
            human1.reset();
            computer2.reset();
            return;
        }
        
        if(guess>answer)
            High=true;
        else
            High=false;
        human1.lastWasTooHigh(High);
        
        computer2.opponentsGuess(guess, High);
        guess=computer2.getGuess();
        if(guess==answer){
            cout<<"Computer 2 has won the game with the correct guess of "<< guess << endl;
            cout<<"Computer 2 took "<< computer2.count <<" guesses to guess the right answer!"<< endl;
            human1.reset();
            computer2.reset();
            return;
        }
        
        if(guess>answer)
            High=true;
        else
            High=false;
        computer2.lastWasTooHigh(High);
        
    }
}

void cvc(){
    while(1){
        computer1.opponentsGuess(guess, High);
        guess=computer1.getGuess();
        if(guess==answer){
            cout<<"Computer 1 has won the game with the correct guess of "<< guess << endl;
            cout<<"Computer 1 took "<< computer1.count <<" guesses to guess the right answer!"<< endl;
            computer1.reset();
            computer2.reset();
            return;
        }
        
        if(guess>answer)
            High=true;
        else
            High=false;
        computer1.lastWasTooHigh(High);
        
        computer2.opponentsGuess(guess, High);
        guess=computer2.getGuess();
        if(guess==answer){
            cout<<"Computer 2 has won the game with the correct guess of "<< guess << endl;
            cout<<"Computer 2 took "<< computer2.count <<" guesses to guess the right answer!"<< endl;
            computer1.reset();
            computer2.reset();
            return;
        }
        
        if(guess>answer)
            High=true;
        else
            High=false;
        computer2.lastWasTooHigh(High);
        
    }
}
*/
