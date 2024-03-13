#include <iostream>
#include "Casino.hpp"
#include <vector>
#include <cstdlib>
#include <time.h>
using namespace std;

struct Game
{
    int whenLose;
    int whenWin;
    int maxNum;
};

int main(){
    // types of games
    Game gameTypes[3];
    gameTypes[0].whenLose = 0; gameTypes[0].whenWin = 10; gameTypes[0].maxNum = 2; // this one is for me to test the game and win all the time - losing isnt even possible as there is only one number to guess
    gameTypes[1].whenLose = -10; gameTypes[1].whenWin = 20; gameTypes[1].maxNum = 5;
    gameTypes[2].whenLose = -20; gameTypes[2].whenWin = 50; gameTypes[2].maxNum = 20;
    
    // all variables
    char wantToContinue = 'Y'; // basicly a bool
    char ans = 'X'; // the type of game player wants to play (Easy, Medium or Hard)
    int currentGame = 0; // the game type chosen by the player
    int playerNum, computerNum; // the numbers of the computer and player - they need to be equal in order for a player to win  a game
    string name; // name of the player

    srand(time(NULL)); // start of the randomizing
    cout << "Welcome to the Casino!" << endl; // Welcome!
    cout << "What is your name?" << endl;
    cin >> name;
    Player player = Player(name); // creating a player with a name
    
    do{
        cout << "Which game would you like to play? (E, M, H)" << endl;
        
        do{
            cin >> ans;
            if(int(ans) >= 97){
                ans -= 32;
            }
        }while(ans != 'E' && ans != 'M' && ans != 'H');
        if(ans == 'E'){currentGame = 0;}else if(ans == 'M'){currentGame = 1;}else{currentGame = 2;}
        // by this line the game number should be chosen

        
        cout << "Choose a number beetween 1 and " << gameTypes[currentGame].maxNum << endl;

        do{
            cin >> playerNum;
        }while(playerNum < 1 || playerNum > gameTypes[currentGame].maxNum);
        computerNum = (rand()%gameTypes[currentGame].maxNum) + 1;

        if(computerNum == playerNum){
            cout << "You guessed the number!" << endl;
            player.addScore(gameTypes[currentGame].whenWin);
        }else{
            cout << "You guessed it wrong!" << endl;
            player.addScore(gameTypes[currentGame].whenLose);
        }

        cout << "Your current points: " << player.showPoints() << endl;
        do{
            cout << "Wanna Coninue? (Y/N): ";
            cin >> wantToContinue;
            cout << endl;
        }while(wantToContinue != 'N' && wantToContinue != 'Y');

    }while(wantToContinue == 'Y');
    
    return 0;
}