#ifndef __VALUE_AGENT__
#define __VALUE_AGENT__

#include "board.h"
#include <vector>
using namespace std;


namespace gobang{

class VAL_AGENT{
    public:
        vector<pair<int,int> > get_high_positions(const Board* board,bool is_black,int top);
        int get_value(const Board* board, bool is_black, bool is_me);
        //more if winning

        VAL_AGENT();
        ~VAL_AGENT();
        
        
    private:
        const static int EMPTY=0;
        const static int ALLY=1;
        const static int OPON=2;
        const int move_x[8]={ 1, 1, 1, 0,-1,-1,-1, 0};
        const int move_y[8]={ 1, 0,-1, 1,-1, 0, 1,-1};

        void show_map_(const int* a)const;



        bool cmp1_(pair<int,int>p1, pair<int,int>p2);

        void init_map_(const Board* board,bool is_black);
        void init_value_map_();
        
        int get_len_(int x,int y,int dir,int side )const;
        int get_free_(int x,int y,int dir,int side)const;

        //int get_further_free_(int x,int y,int dir,int side)const;
        int get_extend_(int x,int y,int dir,int side )const;
        int get_allies_(int x,int y,int dir,int side)const;
        int get_further_allies_(int x,int y,int dir,int side)const;

        void go_further_();

        int* value_map_;
        int* map_;
        int *mark_[2];
        int* sep_val_map_[2];

        int size_;
        // 0:  four_dead
        // 1:  three_free

};

}

#endif