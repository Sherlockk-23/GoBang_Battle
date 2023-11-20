#ifndef __ROBOT1_H__
#define __ROBOT1_H__

#include "board.h"
#include "strategy.h"


namespace gobang{

class Bot1: public Strategy{
    public:
        void get_pos(const Board* board,bool is_black,int &x,int &y) override;
        Bot1();
        ~Bot1();
    private:
        const static int EMPTY=0;
        const static int ALLY=1;
        const static int OPON=2;
        const int move_x[8]={ 1, 1, 1, 0,-1,-1,-1, 0};
        const int move_y[8]={ 1, 0,-1, 1,-1, 0, 1,-1};

        void show_map_(const int* a)const;

        void init_map_(const Board* board,bool is_black);
        void init_value_map_();
        int get_len_(int x,int y,int dir,int is_A )const;
        int get_free_(int x,int y,int dir,int is_A)const;

        int* value_map_;
        int* map_;

};

}

#endif