#include "strategy.h"

#include <termio.h>
#include <iostream>
#include <cstdio>

namespace gobang {

Strategy::Strategy (){ size_=15; }

int scanKeyboard()
{
    int in;
    struct termios new_settings;
    struct termios stored_settings;
    tcgetattr(0,&stored_settings);
    new_settings = stored_settings;
    new_settings.c_lflag &= (~ICANON);
    new_settings.c_cc[VTIME] = 0;
    tcgetattr(0,&stored_settings);
    new_settings.c_cc[VMIN] = 1;
    tcsetattr(0,TCSANOW,&new_settings);
    
    in = getchar();
    
    tcsetattr(0,TCSANOW,&stored_settings);
    return in;
}

// better to use  wasd ?
void Human::get_pos(const Board* board,bool is_black,int &x,int &y){
    size_=board->GetSize();
    x=y=size_/2;
    board->Draw(x-1,y-1),
        std::cout<<"Your Turn, wasd to move, Enter to down"<<std::endl;
    bool _=0;
    while(1){
        int key=scanKeyboard();
        if(key==10){
            int check=board->CheckPos( x-1 , y-1 );
            if ( check==0 ) break;
            if ( check==1 )
                std::cout << "out of bound! " << std::endl;
            if ( check==2 )
                std::cout << " already occupied ! " << std::endl;
        }
        if(key=='f'){
            x=y=0;break;
        }
        switch (key){
            case 'a':if(y>1)y--,_=1;break;
            case 's':if(x<size_)x++,_=1;break;
            case 'w':if(x>1)x--,_=1;break;
            case 'd':if(y<size_)y++,_=1;break;

        }
        if(_)board->Draw(x-1,y-1),
        std::cout<<"Your Turn, wasd to move, Enter to down"<<std::endl;
    }    

}

/*
void Human::get_pos(const Board* board,bool is_black,int &x,int &y){
    size_=board->GetSize();
    while(1){
        std::cout << "enter coordinates (e.g., 1 2), 0 0 to forfeit:" << std::endl;
        std::cin >> x >> y;  
        if( !x && !y )break;
        int check=board->CheckPos( x-1 , y-1 );
        if ( check==0 ) break;
        if ( check==1 )
             std::cout << " x, y out of bound! " << std::endl;
        if ( check==2 )
             std::cout << " x, y already occupied ! " << std::endl;
    }    
}
*/



}