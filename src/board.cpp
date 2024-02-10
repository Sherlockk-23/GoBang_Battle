#include "board.h"

#include <iostream>
#include <iomanip>

namespace gobang {

Board::Board(): size_(DEFAULT_SIZE)   { Init(); }
Board::Board(int size): size_(size) { Init(); }

void Board::Init() {
    lastx=lasty=-1;
    state_ = new int[size_ * size_];
    for (int i = 0; i < size_ * size_; i++) {
	state_[i] = EMPTY;
    }
}

Board::~Board() {
    delete[] state_;
}

int Board::GetSize() const { return size_; }

int Board::GetState(int x, int y) const {
    return state_[x * size_ + y];
}

int Board::CheckPos(int x,int y) const{
    if( x<0 || y<0 || x>=size_ || y>=size_ )return 1;
    if(state_[x*size_+y]!=EMPTY)return 2;
    return 0;
}

bool Board::SetStateBlack(int x, int y) {
    return SetState(x, y, BLACK);
}

bool Board::SetStateWhite(int x, int y) {
    return SetState(x, y, WHITE);
}

bool Board::SetStateEmpty(int x, int y) {
    return SetState(x, y, EMPTY);
}

bool Board::SetState(int x, int y, int state) {
    if (x < 0 || x >= size_ || y < 0 || y >= size_)
	return false;
    int cur_state = state_[x * size_ + y];
    if(state!=EMPTY){
        if(state_[x * size_ + y]!=EMPTY)return false;
        lastx=x,lasty=y;
        state_[x * size_ + y] = state;
        return true;
    }
    else {
	    state_[x * size_ + y] = state;
	    return true;
    }
    return false;
}

void Board::Draw(int x,int y) const {
    system("clear");
    std::cout << "   ";
    for (int j = 0; j < size_; j++) {
	std::cout << std::setw(3) << (j + 1);
    }
    std::cout << std::endl << std::endl;
    for (int i = 0; i < size_; i++) {
	std::cout << std::setw(3) << (i + 1);
	for (int j = 0; j < size_; j++) {
	    int state = state_[i * size_ + j];

        if( i==x && j==y ){
            std::cout << "\033[5m\033[36m" << std::setw(3) << "X" << "\033[0m";
            continue;
        }

        if (state == EMPTY){
            //std::cout<<i<<' '<<j<<' '<<( ((i/5)&1) && ((j/5)&1) )<<std::endl;
		    if( ( i/5 + j/5) & 1 )
                std::cout << "\033[34m" << std::setw(3) << "+" << "\033[0m";
            else
                std::cout << "\033[2m\033[34m" << std::setw(3) << "+" << "\033[0m";
            continue;
        }


        if( i==lastx && j==lasty ){
	        if (state == BLACK)
		        std::cout << "\033[1m\033[33m" << std::setw(3) << "@" << "\033[0m";
	        else if (state == WHITE)
		        std::cout << "\033[1m\033[33m" << std::setw(3) << "o" << "\033[0m";

        }
        else{
	        if (state == BLACK)
		        std::cout << "\x1B[91m" << std::setw(3) << "@" << "\033[0m";
	        else
		        std::cout << "\x1B[97m" << std::setw(3) << "o" << "\033[0m";

        }
	}
	std::cout << std::endl << std::endl;
    }

}

} // namespace gobang
