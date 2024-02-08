#ifndef __ROBOT_MMS_H__
#define __ROBOT_MMS_H__

#include "board.h"
#include "strategy.h"
#include "value_agent.h"
#include <vector>
using namespace std;


namespace gobang{

class Bot_mms: public Strategy{
    public:
        void get_pos(const Board* board,bool is_black,int &x,int &y) override;
        Bot_mms();
        ~Bot_mms();
    private:

        const static int Depth=4, Width=5;  // W^(D*2) 
        Board* my_board_;

        void init_(const Board* board,bool is_black);

        bool check_ending_state(bool is_me);
        // if val of evaluate_state_ is too large.

        int evaluate_state_(bool is_me);

        int max_search_(int dep,int& x,int& y,int a,int b);

        int min_search_(int dep,int a,int b);

        vector<pair<int,int> > get_actions_(bool is_me,int dep);

        VAL_AGENT* value_agent_;

        int size_;

        int tot_;

        int search_cnt_;


};

}

#endif