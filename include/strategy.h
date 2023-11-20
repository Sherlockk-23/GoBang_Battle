#ifndef __STRATEGY_H__
#define __STRATEGY_H__

#include "board.h"

namespace gobang{

class Strategy{
    public:
        virtual void get_pos(const Board* board,bool is_black,int &x,int &y){};
        Strategy();
    protected:
        int size_;
} ;

class Human: public Strategy{
    public:
        void get_pos(const Board* board,bool is_black,int &x,int &y) override;
    
};


}


/*  
std::cout << "enter coordinates (e.g., 1 2), 0 0 to forfeit:" << std::endl;
std::cin >> x >> y;  
*/
#endif