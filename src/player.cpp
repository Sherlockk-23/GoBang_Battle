#include "player.h"

#include <cstring>
#include <iostream>

namespace gobang {

Player::Player(bool is_black, int strategy_id, const char *name) :
    is_black_(is_black), state_(IN_GAME) {
    strcpy(name_, name);
	switch(strategy_id){
		case 0: strategy_= new Human; break;
		case 1: strategy_= new Bot1;  break;
	}
}

bool Player::IsBlack() const { return is_black_; }
void Player::SetRole(bool is_black) { is_black_ = is_black; }
const char *Player::GetName() { return name_; }

bool Player::IsWin() const { return (state_ == WIN); }
bool Player::IsLost() const { return (state_ == LOST); }
bool Player::IsInGame() const { return (state_ == IN_GAME); }
void Player::Win() { state_ = WIN; }
void Player::Lost() { state_ = LOST; }

void Player::Play(Board *board) {
    std::cout << name_;
    if (is_black_)
	std::cout << " (Black)'s turn, ";
    else
	std::cout << " (White)'s turn, ";
    bool play_success = false;
    while (!play_success) {
		int x = 0, y = 0;
			//  2!!  implement this!
		strategy_->get_pos( board, is_black_, x, y );          
	if ( !x && !y ){
		state_ = LOST; // forfeit
	    play_success = true;
	} else {                     //  1!!  here what if false ? like (x,y) is out of bound?
	    if (is_black_)                
		play_success = board->SetStateBlack(x - 1, y - 1);
	    else
		play_success = board->SetStateWhite(x - 1, y - 1);
	}
    }
}

} // namespace gobang
