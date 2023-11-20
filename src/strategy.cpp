#include "strategy.h"

#include <iostream>
#include <cstdio>

namespace gobang {

Strategy::Strategy (){ size_=15; }

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


}