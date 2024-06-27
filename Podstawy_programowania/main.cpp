#include <iostream>
#include <algorithm>
#include <conio.h>
#include <cstdlib>
#include <vector>
#include <math.h>
#include <cmath>
#include <ctime>
#include <time.h>
using namespace std;

const short N = 50;

string annoucement(int W){
    int counter = 0;
    int Z[N];
    for(int i=0;i<N;i++){
        Z[i] = rand()%10;
        if(Z[i] == W) counter++;
    }
    return counter>N/3 ? "kalibracja nie powiodla sie" : "kalibracja powiodla sie";
}

int main(){
    int W;
    string ans = "T";
    srand(time(NULL));
    cout << "\n\n\t\t+++++++++++++++++++++++++";
    cout << "\n\t\t+ kalibracja urządzenia +";
    cout << "\n\t\t+++++++++++++++++++++++++";

    cout << "\n\n\t\twybierz poziom kalibracji: ";

    do{
        cin >> W;
    }while(W>=0 && W<=9 && int(W)==W && W-int(W)==0);

    cout << annoucement(W);
    getch();
    return 0;
}