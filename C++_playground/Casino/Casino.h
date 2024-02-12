#include <fstream>
#include <chrono>
#include <ctime>
#include <string>
#include <limits>
#include <vector>
using namespace std;

fstream& GotoLine(fstream& file, unsigned int num){
    file.seekg(ios::beg);
    for(int i=0; i < num - 1; ++i){
        file.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    return file;
}

class Player{
    string namePseudonim; //name of the player
    int score; //in dollars

    public:
        Player(string n){
            namePseudonim = n;
            score = 0;
        }
        ~Player(){
            fstream saveFile; // creating a file variable
            saveFile.open("scores.txt", ios_base::out | ios_base::in); //opening file so i can write and read it

            auto end = chrono::system_clock::now(); // variable storing when does player end playing
            time_t endTime = chrono::system_clock::to_time_t(end); 

            string text; // current line in the scoreboard
            int i = 0; // number of this line
            while(std::getline(saveFile, text)){
                i++; // first line - one
                vector<string> transformedText; // plain tex transformed into a vector with everything partitioned (score, name etc)
                for(int c = 0;c<text.size();c++){ // c (char)
                    if(c == ' '){ // this for basicly creates a list of all the word in the player-line
                        transformedText.push_back(' ');
                    }else{
                        transformedText[transformedText.size()-1] += text[c];
                    }
                }
                if(stoi(transformedText[1]) <= score){
                    break;
                }
            }
            GotoLine(saveFile, i);
            saveFile << '\n' << namePseudonim << ' ' << to_string(score) << ' ' << to_string(endTime);
            saveFile.close();
        }
        void addScore(int a){
            score += a;
        }
};  