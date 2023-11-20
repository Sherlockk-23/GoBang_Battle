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

void Bot1::init_value_map_(){
    const static int A_five= 1e8;
    const static int B_five= 1e7;
    const static int A_four_free = 3e6;
    const static int B_four_free = 5e5;

    const static int A_four_dead = 10000;
    const static int B_four_dead = 5000;

    const static int A_three_free = 30000;
    const static int B_three_free = 10000;

    const static int A_two_free = 1000;
    const static int B_two_free = 200;

    #define here value_map_[id_map(i,j)]
    


    all_ij
        value_map_[id_map(i,j)]=0;

    all_ij if(map_[id_map(i,j)]==EMPTY)
    for(int dir=0;dir<4;dir++)
    {
        int AlenL,AlenR,AfreeL,AfreeR;
        AlenL=get_len_(i,j,dir,ALLY);
        AlenR=get_len_(i,j,dir+4,ALLY);
        AfreeL=get_free_(i,j,dir,ALLY);
        AfreeR=get_free_(i,j,dir+4,ALLY);

        if ( AlenL+AlenR>=4 )
            here += A_five;
        if ( AlenL+AlenR==3 ) {
            if( AfreeL && AfreeR )
                here += A_four_free;
            else if ( AfreeL || AfreeR )
                here += A_four_dead;
        }
        if ( AlenL+AlenR==2 ){
            if( (AfreeL>=2 && AfreeR ) || (AfreeL && AfreeR >=2) )
                here += A_three_free;

        }
        if( AlenL || AlenR ){
            if( (AfreeL>=2 && AfreeR>=3 ) || (AfreeL>=3 && AfreeR >=2) )
                here += A_two_free;
        }

        int BlenL,BlenR,BfreeL,BfreeR;
        BlenL=get_len_(i,j,dir,OPON);
        BlenR=get_len_(i,j,dir+4,OPON);
        BfreeL=get_free_(i,j,dir,OPON);
        BfreeR=get_free_(i,j,dir+4,OPON);

        if ( BlenL+BlenR>=4 )
            here += B_five;
        if ( BlenL+BlenR==3 ) {
            if( BfreeL && BfreeR )
                here += B_four_free;
            else if ( BfreeL || BfreeR )
                here += B_four_dead;
        }
        if ( BlenL+BlenR==2 ){
            if( (BfreeL>=2 && BfreeR ) || (BfreeL && BfreeR >=2) )
                here += B_three_free;

        }
        if( BlenL || BlenR ){
            if( (BfreeL>=2 && BfreeR>=3 ) || (BfreeL>=3 && BfreeR >=2) )
                here += B_two_free;
        }



    }

        

    

    all_ij{
        value_map_[id_map(i,j)] +=
            ( pow (i*(size_-i) , 2 ) + pow( j*(size_-j) ,2) )  /  (size_*size_/2)
            + rand()%(size_*size_/2);
    }

    all_ij{
        if(map_[id_map(i,j)]!=EMPTY)
            value_map_[id_map(i,j)]=-1;
    }
    #undef here
}

void Bot1::get_pos(const Board* board,bool is_black,int &x,int &y){
    srand(time(0));
    init_map_(board,is_black);
    init_value_map_();

    //show_map_(value_map_);

    x=y=0;
    all_ij{
        if(value_map_[id_map(i,j)]>value_map_[id_map(x,y)])
            x=i,y=j;
    }

    x++;y++;

    cout<<x<<' '<<y<<endl;
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


