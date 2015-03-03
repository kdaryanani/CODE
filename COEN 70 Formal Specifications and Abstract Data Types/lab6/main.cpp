#include "player.h"

void hvh();
void hvc();
void cvc();

int main(){
    int answer;
    int x=0;
    int guess;
    bool High;
    ComputerPlayer computer1;
    ComputerPlayer computer2;
    HumanPlayer computer1;
    HumanPlayer human2;
    
	while(1){
        cout<< "Who would you like to play. Enter 1 for human vs human, enter 2 for human vs computer, or enter 3 for computer vs computer. enter anything else to quit" <, endl;
        cin << x;
		guess=-1;
    
        switch(x){
            
            case 1:
                cout " You've chosen Human vs Human." << endl;
                hvh();
				break;
                
            case 2:
                cout " You've chosen Human vs Computer." << endl;
				hvc();
                break;
                
            case 3:
                cout " You've chosen Computer vs Computer." << endl;
				cvc();
                break;
                
            default:
				cout " Goodbye!" << endl;
                return 0;
        }
    }
	return 1;
}

void hvh(){
        while(1){
            human1.opponentsGuess(guess, High);
            guess=computer1.getGuess;
            if(guess==answer){
				cout<<"Human 1 has won the game with the correct guess of "<< guess << endl;
				cout<<"Human 1 took "<< human1.count <<" guesses to guess the right answer!"<< endl;
				human1.reset;
				human2.reset;
				return;
			}
			
            if(guess>answer)
                High=true;
            else
                High=false;
            human1.lastWasTooHigh(High);
			
			human2.opponentsGuess(guess, High);
            guess=human2.getGuess;
            if(guess==answer){
				cout<<"Human 2 has won the game with the correct guess of "<< guess << endl;
				cout<<"Human 2 took "<< human2.count <<" guesses to guess the right answer!"<< endl;
				human1.reset;
				human2.reset;
				return;
			}
			
			if(guess>answer)
                High=true;
            else
                High=false;
            human2.lastWasTooHigh(High);
			
		}
}

void hvc(){
        while(1){
            human1.opponentsGuess(guess, High);
            guess=human1.getGuess;
            if(guess==answer){
				cout<<"Human 1 has won the game with the correct guess of "<< guess << endl;
				cout<<"Human 1 took "<< human1.count <<" guesses to guess the right answer!"<< endl;
				human1.reset;
				computer2.reset;
				return;
			}
			
            if(guess>answer)
                High=true;
            else
                High=false;
            human1.lastWasTooHigh(High);
			
			computer2.opponentsGuess(guess, High);
            guess=computer2.getGuess;
            if(guess==answer){
				cout<<"Computer 2 has won the game with the correct guess of "<< guess << endl;
				cout<<"Computer 2 took "<< computer2.count <<" guesses to guess the right answer!"<< endl;
				human1.reset;
				computer2.reset;
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
            guess=computer1.getGuess;
            if(guess==answer){
				cout<<"Computer 1 has won the game with the correct guess of "<< guess << endl;
				cout<<"Computer 1 took "<< computer1.count <<" guesses to guess the right answer!"<< endl;
				computer1.reset;
				computer2.reset;
				return;
			}
			
            if(guess>answer)
                High=true;
            else
                High=false;
            computer1.lastWasTooHigh(High);
			
			computer2.opponentsGuess(guess, High);
            guess=computer2.getGuess;
            if(guess==answer){
				cout<<"Computer 2 has won the game with the correct guess of "<< guess << endl;
				cout<<"Computer 2 took "<< computer2.count <<" guesses to guess the right answer!"<< endl;
				computer1.reset;
				computer2.reset;
				return;
			}
			
			if(guess>answer)
                High=true;
            else
                High=false;
            computer2.lastWasTooHigh(High);
			
		}
}