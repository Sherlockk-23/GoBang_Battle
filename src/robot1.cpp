#include "strategy.h"
#include "robot1.h"

#include <iostream>
#include <cstdio>
#include <time.h>
#include <cmath>

using namespace std;


namespace gobang{


#define id_map(x,y)    ( x*size_+y )
#define inmap(x,y) ( x>=0 && y>=0 && x<size_ && y<size_ )
#define all_ij for(int i=0;i<size_;i++) for(int j=0;j<size_;j++)


Bot1::Bot1(){size_=0;}
Bot1::~Bot1(){
    delete[] map_;
    delete[] value_map_;
}

void Bot1::show_map_(const int* a)const {
    for(int i=0;i<size_;i++){
        for(int j=0;j<size_;j++)
            cout<<a[id_map(i,j)]<<' ';
        cout<<endl;
    }
}

void Bot1::init_map_(const Board* board,bool is_black){
    if( board->GetSize()>size_ ){
        size_=board->GetSize();
        value_map_=new int [size_*size_];
        map_=new int [size_*size_];
    }
    size_=board->GetSize();
    all_ij{
        int state=board->GetState(i,j);
        if(state==Board::EMPTY) 
            map_[id_map(i,j)] = EMPTY;
        else if( state== Board::BLACK )
            map_[id_map(i,j)] = is_black ? ALLY : OPON;
        else if( state== Board::WHITE )
            map_[id_map(i,j)] = is_black ? OPON : ALLY;
        }
    
    
    

}

void Bot1::init_value_map_(){          // a lot of code waste
    const int _five [2] =         {(int)1e8,(int)1e7};
    const int _four_free [2] =    {(int)3e6,(int)5e5};
    const int _four_dead [2] =    {10000,5000};
    const int _three_free [2] =   {30000,10000};
    const int _two_free [2] =     {1000,200};


    #define here value_map_[id_map(i,j)]
    


    all_ij
        value_map_[id_map(i,j)]=0;

    

    all_ij if(map_[id_map(i,j)]==EMPTY)
    for(int dir=0;dir<4;dir++)
    for(int side=1;side<=2;side++)
    {
        int lenL,lenR,freeL,freeR;
        lenL=get_len_(i,j,dir,side);
        lenR=get_len_(i,j,dir+4,side);
        freeL=get_free_(i,j,dir,side);
        freeR=get_free_(i,j,dir+4,side);

        if ( lenL+lenR>=4 )
            here += _five[side&1^1];
        if ( lenL+lenR==3 ) {
            if( freeL && freeR )
                here += _four_free[side&1^1];
            else if ( freeL || freeR )
                here += _four_dead[side&1^1];
        }
        if ( lenL+lenR==2 ){
            if( (freeL>=2 && freeR ) || (freeL && freeR >=2) )
                here += _three_free[side&1^1];

        }
        if( lenL || lenR ){
            if( (freeL>=2 && freeR>=3 ) || (freeL>=3 && freeR >=2) )
                here += _two_free[side&1^1];
        }

    }


    int cnt=0;                              //  more random at start
    all_ij cnt+=map_[id_map(i,j)]!=EMPTY;
    if(cnt<=5){
    all_ij{
        here +=
            ( pow (i*(size_-i) , 2 ) + pow( j*(size_-j) ,2) )  /  (size_*size_/4)
            + rand()%(size_*size_/3);
    }
    }


    all_ij{
        if(map_[id_map(i,j)]!=EMPTY)
            here =-1;
    }
    #undef here
}

void Bot1::get_pos(const Board* board,bool is_black,int &x,int &y){
    srand(time(0));
    init_map_(board,is_black);
    init_value_map_();


    // see robot2


    //show_map_(value_map_);

    x=y=0;
    all_ij{
        if(value_map_[id_map(i,j)]>value_map_[id_map(x,y)])
            x=i,y=j;
    }

    x++;y++;

    std::cout<<x<<' '<<y<<std::endl;
}

int Bot1::get_len_(int x,int y,int dir,int is_A)const{
    int len=0;
    while(1){
        x+=move_x[dir];
        y+=move_y[dir];
        if(!inmap(x,y))break;
        if(map_[id_map(x,y)]!=is_A)break;
        len++;
    }
    return len;
}



int Bot1::get_free_(int x,int y,int dir,int is_A)const{  
    int len=0;
    x+=move_x[dir];y+=move_y[dir];
    if( (!inmap(x,y)) || map_[id_map(x,y)]== 3-is_A )
        return 0;
    while( map_[id_map(x,y)]==is_A && inmap(x,y) )
        x+=move_x[dir],y+=move_y[dir];

    while(1){
        if(!inmap(x,y))break;
        if(map_[id_map(x,y)]!=EMPTY)break;
        len++;
        x+=move_x[dir],y+=move_y[dir];
    }

    
    return len;
}


#undef id_map(x,y)
#undef inmap(x,y)
#undef all_ij

}


