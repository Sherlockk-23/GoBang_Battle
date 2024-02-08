#include "strategy.h"
#include "value_agent.h"

#include <iostream>
#include <cstdio>
#include <time.h>
#include <cmath>
#include <algorithm>

using namespace std;


namespace gobang{


#define id_map(x,y)    ( x*size_+y )
#define inmap(x,y) ( x>=0 && y>=0 && x<size_ && y<size_ )
#define all_ij for(int i=0;i<size_;i++) for(int j=0;j<size_;j++)


VAL_AGENT::VAL_AGENT(){size_=0;}
VAL_AGENT::~VAL_AGENT(){
    delete[] map_;
    delete[] value_map_;
    delete[] mark_[0];
    delete[] mark_[1];
    delete[] sep_val_map_[0];
    delete[] sep_val_map_[0];
}

void VAL_AGENT::show_map_(const int* a)const {
    for(int i=0;i<size_;i++){
        for(int j=0;j<size_;j++)
            cout<<a[id_map(i,j)]<<' ';
        cout<<endl;
    }
}

void VAL_AGENT::init_map_(const Board* board,bool is_black){
    if( board->GetSize()>size_ ){
        size_=board->GetSize();
        value_map_=new int [size_*size_];
        map_=new int [size_*size_];
        mark_[0]=new int[size_*size_];
        mark_[1]=new int[size_*size_];
        sep_val_map_[0]=new int[size_*size_];
        sep_val_map_[1]=new int[size_*size_];
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

void VAL_AGENT::init_value_map_(){          
    // int robot1
    const int _five [2] =         {(int)1e8,(int)1e7};
    const int _four_free [2] =    {(int)3e6,(int)5e5};
    const int _four_dead [2] =    {10000,2000};
    const int _three_free [2] =   {30000,15000};
    const int _three_dead [2] =   {300,50};
    const int _two_free [2] =     {1000,500};
    
    // something new

    const int _one_free [2] =     {300,100};

    // mark some must_win situation: four_dead + three_free

    #define here value_map_[id_map(i,j)]
    #define this_side ((side&1)^1)


    all_ij
        here=0,mark_[0][id_map(i,j)]=mark_[1][id_map(i,j)]=0;

    int cnt=0;                              //  more random at start
    all_ij cnt+=(map_[id_map(i,j)]!=EMPTY);
    if(cnt<3){
        all_ij{                 
            here=0;                    //  more middle
            here +=
                ( pow (i*(size_-i) , 2 ) + pow( j*(size_-j) ,2) )  /  (size_*size_);
            here+=rand()%20;

        }
        all_ij{
            if(map_[id_map(i,j)]!=EMPTY)
                here =-1;
        }
        return;
    }
    
    

    all_ij if(map_[id_map(i,j)]==EMPTY)
    for(int dir=0;dir<4;dir++)
    for(int side=1;side<=2;side++)
    {
        int extL=get_extend_(i,j,dir,side), extR=get_extend_(i,j,dir+4,side);
        int alyL=get_allies_(i,j,dir,side), alyR=get_allies_(i,j,dir+4,side);

        int lenL=get_len_(i,j,dir,side),lenR=get_len_(i,j,dir+4,side);
        int freeL=get_free_(i,j,dir,side),freeR=get_free_(i,j,dir+4,side);


        // useless state
        if( extL + extR <4 )continue;  

        // must goes
        if ( lenL+lenR>=4 )
            here += _five[this_side];
            
        if ( lenL+lenR==3 ) {
            if( freeL && freeR )
                here += _four_free[this_side];
            
        }

        // should be wrong

        if( alyL + alyR ==3 ){
            if( lenL>=2 || lenR>=2 )
                here += _four_dead[this_side],
                mark_[side&1][id_map(i,j)]|=1;
            else if ( alyL==3 || alyR==3 ){
                here += _four_dead[this_side];
                if(mark_[side&1][id_map(i,j)]&1)
                    mark_[side&1][id_map(i,j)]|=2;
                mark_[side&1][id_map(i,j)]|=1;
            }
            else if( ( lenL && freeL ) || ( lenR && freeR) )
                here += _three_free[this_side],
                mark_[side&1][id_map(i,j)]|=2;
                //cout<<"5: "<<i+1<<' '<<j+1<<' '<<lenL<<endl;
        }

        else if( alyL + alyR == 2 ){
            if( alyL == 2 ){
                if( lenL==2 ){
                    if( extL>2 && extR )
                        here += _three_free[this_side],
                        mark_[side&1][id_map(i,j)]|=2;
                        //cout<<"1: "<<i+1<<' '<<j+1<<' '<<lenL<<endl;
                    else if( extL==2 )
                        here += _three_dead[this_side];
                }
                else {
                    if( extL>3 )
                        here += _three_free[this_side]/side-200,
                        mark_[side&1][id_map(i,j)]|=2;
                        //cout<<"2: "<<i+1<<' '<<j+1<<' '<<extL<<endl;
                }
            }
            else if( alyR == 2 ){
                if( lenR==2 ){
                    if( extR>2 && extL )
                        here += _three_free[this_side],
                        mark_[side&1][id_map(i,j)]|=2;
                        //cout<<"1: "<<i+1<<' '<<j+1<<' '<<lenR<<endl;
                    else if( extR==2 )
                        here += _three_dead[this_side];
                }
                else {
                    if( extR>3 )
                        here += _three_free[this_side]/side-200,
                        mark_[side&1][id_map(i,j)]|=2;
                        //cout<<"2: "<<i+1<<' '<<j+1<<' '<<extR<<endl;
                }
            }
            else {
                if( lenL==1 && lenR==1 && freeL && freeR && freeL + freeR > 2)
                    here += _three_free[this_side],
                    mark_[side&1][id_map(i,j)]|=2;
                    //cout<<"4: "<<i+1<<' '<<j+1<<' '<<extR<<endl;
                else if( lenL==1 && freeL && extR >=3 )
                    here += _three_free[this_side],
                    mark_[side&1][id_map(i,j)]|=2;
                    //cout<<"3: "<<i+1<<' '<<j+1<<' '<<extR<<endl;
                else if( lenR==1 && freeR && extL >=3 )
                    here += _three_free[this_side],
                    mark_[side&1][id_map(i,j)]|=2;
                   // cout<<"3: "<<i+1<<' '<<j+1<<' '<<extL<<endl;
            }
            
        }
        else if( alyL + alyR == 1 ){
            if( extL >= 3 && extR >=3 && extL + extR >= 7){
                here += _two_free[this_side];
                if( side == ALLY )
                    mark_[1][id_map(i,j)]|=4;
            }
        }
       
       else if ( alyL + alyR == 0 ){
            if( extL >= 3 && extR >=3 && extL + extR >= 7){
                here += _one_free[this_side] * 
                    ( get_further_allies_(i,j,dir,side) + get_further_allies_(i,j,dir+4,side) );
                if( get_further_allies_(i,j,dir,side) || get_further_allies_(i,j,dir+4,side))
                    mark_[1][id_map(i,j)]|=4;
            }
        }

    }

    all_ij {
        if( mark_[1][id_map(i,j)] & 3 == 3 ){
            here+=_four_free[0];
        }
        if( mark_[0][id_map(i,j)] & 3 == 3 ){
            here+=_four_free[1];
        }
    }



    all_ij{
        if(map_[id_map(i,j)]!=EMPTY)
            here =-1;
    }
    #undef here
}

void VAL_AGENT::go_further_(){
    return;
    all_ij if(value_map_[id_map(i,j)]>1000){
        if(mark_[1][id_map(i,j)]&1)
            value_map_[id_map(i,j)]+=20000;
        bool chk=1;
        for(int dir=1;dir<8;dir+=2){
            int x=i+move_x[dir],y=j+move_y[dir];
            if( !inmap(x,y) || map_[id_map(x,y)]!=EMPTY )
                chk=0;
        }
        for(int dir=1;dir<8;dir+=2){
            int x=i+move_x[dir],y=j+move_y[dir];
            if( !inmap(x,y) || map_[id_map(x,y)]!=EMPTY )
                chk=0;
        }

        if( chk && mark_[1][id_map(i,j)] & 4 )
            value_map_[id_map(i,j)]+=10000;
    }

}

bool VAL_AGENT::cmp1_(pair<int,int>p1,pair<int,int>p2){
    int x1=p1.first,x2=p2.first,y1=p1.second,y2=p2.second;
    if(value_map_[x1*size_+y1]!=value_map_[x2*size_+y2])
        return value_map_[x1*size_+y1]>value_map_[x2*size_+y2];
    if(x1!=x2)
        return x1>x2;
    return y1>y2;
}


vector<pair<int,int> > VAL_AGENT::get_high_positions(const Board* board, bool is_black,int top){
    srand(time(0));
    init_map_(board,is_black);
    init_value_map_();

    vector<pair<int,int>>all,chosen;
    all.clear();
    chosen.clear();

    all_ij{
        if(value_map_[id_map(i,j)]>0)
            all.push_back(make_pair(i,j));
    }

    sort(all.begin(),all.end(),
        [this](const pair<int,int>p1,const pair<int,int>p2){
            int x1=p1.first,x2=p2.first,y1=p1.second,y2=p2.second;
            if(value_map_[x1*size_+y1]!=value_map_[x2*size_+y2])
                return value_map_[x1*size_+y1]>value_map_[x2*size_+y2];
            if(x1!=x2)
                return x1>x2;
            return y1>y2;
        }
    );

    for(int i=0;i<min(top,(int)all.size());i++)
        chosen.push_back(make_pair(all[i].first,all[i].second));
    return chosen;
}

int VAL_AGENT::get_extend_(int x,int y,int dir,int side)const{
    int len=0;
    while(len<=5){
        x+=move_x[dir];
        y+=move_y[dir];
        if(!inmap(x,y))break;
        if(map_[id_map(x,y)]==3-side)break;
        len++;
    }
    return len;
}


// not more than 3
int VAL_AGENT::get_allies_(int x,int y,int dir,int side)const{  
    int cnt=0,len=0;
    int interval=0;
    int cntint=0;
    while(len<=3){
        x+=move_x[dir];
        y+=move_y[dir];
        if(!inmap(x,y))break;
        if(map_[id_map(x,y)]==3-side)break;
        if(map_[id_map(x,y)]==side)cnt++,interval=0;
        else interval++,cntint++;
        if(interval>1||cntint>1)break;
        len++;
    }
    return cnt;
}

// if more than two blocks away, and free
int VAL_AGENT::get_further_allies_(int x,int y,int dir,int side)const{  
    int len=0;

    while(len<=3){
        x+=move_x[dir];
        y+=move_y[dir];
        if(!inmap(x,y))return 0;
        if(map_[id_map(x,y)]==3-side)return 0;
        if(map_[id_map(x,y)]==side){
            if( len<1 ) return 0;
            x+=move_x[dir];
            y+=move_y[dir];
            if( !inmap(x,y) || map_[id_map(x,y)]==3-side)return 0;
            return 1;
        }
        len++;
    }
    return 0;
}

// still useful
int VAL_AGENT::get_len_(int x,int y,int dir,int side)const{
    int len=0;
    while(1){
        x+=move_x[dir];
        y+=move_y[dir];
        if(!inmap(x,y))break;
        if(map_[id_map(x,y)]!=side)break;
        len++;
    }
    return len;
}



int VAL_AGENT::get_free_(int x,int y,int dir,int side)const{  
    int len=0;
    x+=move_x[dir];y+=move_y[dir];
    if( (!inmap(x,y)) || map_[id_map(x,y)]== 3-side )
        return 0;
    while( map_[id_map(x,y)]==side && inmap(x,y) )
        x+=move_x[dir],y+=move_y[dir];

    while(1){
        if(!inmap(x,y))break;
        if(map_[id_map(x,y)]!=EMPTY)break;
        len++;
        x+=move_x[dir],y+=move_y[dir];
    }

    
    return len;
}


int VAL_AGENT::get_value(const Board* board, bool is_black,bool is_me){
    //board->Draw();

    init_map_(board,is_black);

    // check winning or losing
    all_ij
        for(int dir=0;dir<8;dir++)
            if(get_len_(i,j,dir,ALLY)>=5)
                return 1e9;
    all_ij
        for(int dir=0;dir<8;dir++)
            if(get_len_(i,j,dir,OPON)>=5)
                return -1e9;

    // calc vals

    const int _five [2] =         {(int)1e8,(int)1e7};
    const int _four_free [2] =    {(int)3e6,(int)5e5};
    const int _four_dead [2] =    {10000,2000};
    const int _three_free [2] =   {30000,15000};
    const int _three_dead [2] =   {300,50};
    const int _two_free [2] =     {1000,500};
    
    // something new

    const int _one_free [2] =     {300,100};

    // mark some must_win situation: four_dead + three_free

    
    #define this_side ((side&1)^1)
    #define here sep_val_map_[this_side][id_map(i,j)]


    all_ij
      for(int side=1;side<=2;side++)
        here=0,mark_[this_side][id_map(i,j)]=0;
    

    all_ij if(map_[id_map(i,j)]==EMPTY)
    for(int dir=0;dir<4;dir++)
    for(int side=1;side<=2;side++)
    {
        int extL=get_extend_(i,j,dir,side), extR=get_extend_(i,j,dir+4,side);
        int alyL=get_allies_(i,j,dir,side), alyR=get_allies_(i,j,dir+4,side);

        int lenL=get_len_(i,j,dir,side),lenR=get_len_(i,j,dir+4,side);
        int freeL=get_free_(i,j,dir,side),freeR=get_free_(i,j,dir+4,side);


        // useless state
        if( extL + extR <4 )continue;  

        // must goes
        if ( lenL+lenR>=4 )
            here += _five[this_side];
            
        if ( lenL+lenR==3 ) {
            if( freeL && freeR )
                here += _four_free[this_side];
            
        }

        // should be wrong

        if( alyL + alyR ==3 ){
            if( lenL>=2 || lenR>=2 )
                here += _four_dead[this_side],
                mark_[side&1][id_map(i,j)]|=1;
            else if ( alyL==3 || alyR==3 ){
                here += _four_dead[this_side];
                if(mark_[side&1][id_map(i,j)]&1)
                    mark_[side&1][id_map(i,j)]|=2;
                mark_[side&1][id_map(i,j)]|=1;
            }
            else if( ( lenL && freeL ) || ( lenR && freeR) )
                here += _three_free[this_side],
                mark_[side&1][id_map(i,j)]|=2;
                //cout<<"5: "<<i+1<<' '<<j+1<<' '<<lenL<<endl;
        }

        else if( alyL + alyR == 2 ){
            if( alyL == 2 ){
                if( lenL==2 ){
                    if( extL>2 && extR )
                        here += _three_free[this_side],
                        mark_[side&1][id_map(i,j)]|=2;
                        //cout<<"1: "<<i+1<<' '<<j+1<<' '<<lenL<<endl;
                    else if( extL==2 )
                        here += _three_dead[this_side];
                }
                else {
                    if( extL>3 )
                        here += _three_free[this_side]/side-200,
                        mark_[side&1][id_map(i,j)]|=2;
                        //cout<<"2: "<<i+1<<' '<<j+1<<' '<<extL<<endl;
                }
            }
            else if( alyR == 2 ){
                if( lenR==2 ){
                    if( extR>2 && extL )
                        here += _three_free[this_side],
                        mark_[side&1][id_map(i,j)]|=2;
                        //cout<<"1: "<<i+1<<' '<<j+1<<' '<<lenR<<endl;
                    else if( extR==2 )
                        here += _three_dead[this_side];
                }
                else {
                    if( extR>3 )
                        here += _three_free[this_side]/side-200,
                        mark_[side&1][id_map(i,j)]|=2;
                        //cout<<"2: "<<i+1<<' '<<j+1<<' '<<extR<<endl;
                }
            }
            else {
                if( lenL==1 && lenR==1 && freeL && freeR && freeL + freeR > 2)
                    here += _three_free[this_side],
                    mark_[side&1][id_map(i,j)]|=2;
                    //cout<<"4: "<<i+1<<' '<<j+1<<' '<<extR<<endl;
                else if( lenL==1 && freeL && extR >=3 )
                    here += _three_free[this_side],
                    mark_[side&1][id_map(i,j)]|=2;
                    //cout<<"3: "<<i+1<<' '<<j+1<<' '<<extR<<endl;
                else if( lenR==1 && freeR && extL >=3 )
                    here += _three_free[this_side],
                    mark_[side&1][id_map(i,j)]|=2;
                   // cout<<"3: "<<i+1<<' '<<j+1<<' '<<extL<<endl;
            }
            
        }
        else if( alyL + alyR == 1 ){
            if( extL >= 3 && extR >=3 && extL + extR >= 7){
                here += _two_free[this_side];
                if( side == ALLY )
                    mark_[1][id_map(i,j)]|=4;
            }
        }
       
       else if ( alyL + alyR == 0 ){
            if( extL >= 3 && extR >=3 && extL + extR >= 7){
                here += _one_free[this_side] * 
                    ( get_further_allies_(i,j,dir,side) + get_further_allies_(i,j,dir+4,side) );
                if( get_further_allies_(i,j,dir,side) || get_further_allies_(i,j,dir+4,side))
                    mark_[1][id_map(i,j)]|=4;
            }
        }

    }

    /*
    all_ij 
    for(int side=1;side<=2;side++)
    {
        if( mark_[side&1][id_map(i,j)] & 3 == 3 ){
            here+=_four_free[this_side];
        }
    }
    */


    /*
        const int _five [2] =         {(int)1e8,(int)1e7};
        const int _four_free [2] =    {(int)3e6,(int)5e5};
        const int _four_dead [2] =    {10000,2000};
        const int _three_free [2] =   {30000,15000};
        const int _three_dead [2] =   {300,50};
        const int _two_free [2] =     {1000,500};
    */

    int res=0;
    all_ij
        if(sep_val_map_[0][id_map(i,j)]>=1e8 && is_me)
            return 1e9;
    all_ij
        if(sep_val_map_[1][id_map(i,j)]>=1e7 && !is_me)
            return -1e9;
    all_ij
        if(sep_val_map_[0][id_map(i,j)]>=3e6 && is_me)
            return 1e9;
    all_ij
        if(sep_val_map_[1][id_map(i,j)]>=5e5 && !is_me)
            return -1e9;

    all_ij
        res+=sep_val_map_[0][id_map(i,j)],
        res-=sep_val_map_[1][id_map(i,j)];

    //show_map_(sep_val_map_[0]);
    //show_map_(sep_val_map_[1]);
    //int x;cin>>x;
    
    return res;

}




#undef id_map(x,y)
#undef inmap(x,y)
#undef all_ij

}



