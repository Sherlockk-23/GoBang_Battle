#include "strategy.h"
#include "bot_mms.h"
#include "robot2.h"

#include <iostream>
#include <cstdio>
#include <time.h>
#include <cmath>
#include <queue>

using namespace std;

const int T=5e5, Depth=4, Width=10, Cnt=8; 
const int inf=1e9+10;
bool ckmin(int& x,int y){return x>y ? x=y,1 : 0;}
bool ckmax(int &x,int y){return x<y ? x=y,1 : 0;}


namespace gobang{


Bot_mms::Bot_mms(){
    value_agent_=new VAL_AGENT;
    my_board_=new Board;
    size_=my_board_->GetSize();
    tot_=0;
}
Bot_mms::~Bot_mms(){
    delete value_agent_;
    delete my_board_;
};

void Bot_mms::init_(const Board* board,bool is_black){
    size_=board->GetSize();
    tot_=0;

    for(int i=0;i<size_;i++)for(int j=0;j<size_;j++)
        switch(board->GetState(i,j)){
            case Board::BLACK:
                tot_++;
                if(is_black)
                    my_board_->SetStateBlack(i,j);
                else 
                    my_board_->SetStateWhite(i,j);
                break;
            case Board::WHITE:
                tot_++;
                if(!is_black)
                    my_board_->SetStateBlack(i,j);
                else 
                    my_board_->SetStateWhite(i,j);
                break;
            case Board::EMPTY:
                my_board_->SetStateEmpty(i,j);
                break;
        }
}
// i am black

void Bot_mms::get_pos(const Board* board,bool is_black,int &x,int &y){
    srand(time(0));
    init_(board,is_black);
    if( tot_<5 ){
        pair<int,int> pos=get_actions_(1,0)[rand()%3];
        x=pos.first;y=pos.second;
    }
    else if(check_ending_state(1)){
        pair<int,int> pos=get_actions_(1,0)[0];
        x=pos.first;y=pos.second;
    }
    else {
        cout<<" begin search !!"<<endl;
        search_cnt_=0;
        int res=max_search_(0,x,y,-1e9,1e9);
        cout<<res<<endl;
    }
    x++;y++;
    //cout<<x<<' '<<y<<endl;
}

vector<pair<int,int> > Bot_mms::get_actions_(bool is_black,int dep){
    return value_agent_->get_high_positions(my_board_,is_black,Width+Depth-dep);
}

int Bot_mms::max_search_(int dep,int& x,int& y,int a,int b){
    search_cnt_++;

    //cout<<"max search, dep="<<dep<<':'<<endl;
    //cout<<" my map is now:"<<endl;
    //my_board_->Draw();


    if( dep==Depth || check_ending_state(1) )
        return evaluate_state_(1);
    vector<pair<int,int> > actions;
    actions=get_actions_(1,dep);
    int res=-1e9;
    for(vector<pair<int,int> >::iterator it=actions.begin();it!=actions.end();it++){
        my_board_->SetStateBlack(it->first,it->second);
        int tmp=min_search_(dep,a,b);
        if(ckmax(res,tmp))
            x=it->first, y=it->second;
        my_board_->SetStateEmpty(it->first,it->second);

        if(res>b)return res;
        ckmax(a,res);
    }
    return res;
}
int Bot_mms::min_search_(int dep,int a,int b){
    search_cnt_++;
    //cout<<"min search, dep="<<dep<<':'<<endl;
    //cout<<" my map is now:"<<endl;
    //my_board_->Draw();
    

    if( check_ending_state(0) )
        return evaluate_state_(0);
    vector<pair<int,int> > actions;
    actions=get_actions_(0,dep);
    //cout<<actions.size()<<' ';
    int res=1e9;
    for(vector<pair<int,int> >::iterator it=actions.begin();it!=actions.end();it++){
        my_board_->SetStateWhite(it->first,it->second);
        int xxx,yyy;
        int tmp=max_search_(dep+1,xxx,yyy,a,b);
        ckmin(res,tmp);
        my_board_->SetStateEmpty(it->first,it->second);

        if(res<a)return res;
        ckmin(b,res);
    }
    return res;
}

bool Bot_mms::check_ending_state(bool is_me){
    return abs(evaluate_state_(is_me))>=1e9;
}

int Bot_mms::evaluate_state_(bool is_me){
    return value_agent_->get_value(my_board_,1,is_me);
}


}


