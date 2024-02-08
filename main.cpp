#include "board.h"
#include "game.h"
#include "player.h"

#include <cstring>
#include <iostream>
using namespace std;

int char_to_int(char* s){
    if (strcmp(s, "0") == 0)return 0;
    if (strcmp(s, "1") == 0)return 1;
    if (strcmp(s, "2") == 0)return 2;
    if (strcmp(s, "3") == 0)return 3;
    return -1;
}


int main(int argc , char *argv[]) {
    int p1=0,p2=3;

    if(argc>2){
        argv++;
        int x1=char_to_int(*argv);
        argv++;
        int x2=char_to_int(*argv);
        if(x1>=0 && x2>=0)p1=x1,p2=x2;
    }

    gobang::Board board;
    gobang::Player player1(true,p1, "Clever Bob"), player2(false,p2, "Smart Amy");
    gobang::Game game(&player1, &player2, &board,0);
    game.Start();
}
