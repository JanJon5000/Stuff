#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
int main(){
    srand(time(NULL)); // "picking" a pseudo-random number so the computer can have a "random" choice of hand
    char possibleHand[3] = {'R', 'P', 'S'}; // possible choices
    char computersChoice; // setting up a computers choice
    char playersChoice = 'R'; // it has a default value so it doesnt bug in some way
    char wantToContinue = 'Y'; // of course you want to continue why wouldnt you?
    
    while(wantToContinue == 'Y'){
        // Players choice
        do{
            cout << endl << "You vs the machine. What is it gonna be, a Rock (enter 'R'), a Paper (enter 'P') or Scissors (enter 'S'):" << endl;
            cin >> playersChoice;
            if(int(playersChoice) >= 97){
                playersChoice -= 32;
            }
        }while(playersChoice != possibleHand[0] && playersChoice != possibleHand[1] && playersChoice != possibleHand[2]);

        computersChoice = possibleHand[rand()%3];

        // Figuring out who wins
        if(playersChoice == 'R' && computersChoice == 'P' || playersChoice == 'P' && computersChoice == 'S'){
            cout << "you lose, the computer has chosen " << computersChoice;
        }else if(playersChoice == 'P' && computersChoice == 'R' || playersChoice == 'R' && computersChoice == 'S'){
            cout << "you win, the computer has chosen " << computersChoice;
        }else{
            cout << "its a draw, you both have chosen " << computersChoice;
        }
        
        // Does a player want to continue?
        do{
            cout << endl << "Want to continue? (Y/N): ";
            cin >> wantToContinue;
            if(int(playersChoice) >= 97){
                playersChoice -= 32;
            }             
        }while(wantToContinue != 'Y' && wantToContinue != 'N');

    }
    return 0;
}