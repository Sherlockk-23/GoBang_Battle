#include "game.h"

#include <iostream>

namespace gobang {

Game::Game(Player *bp, Player *wp, Board *board):
    bp_(bp), wp_(wp), board_(board) {}

const Player *Game::GetBlackPlayer() const { return bp_; }
const Player *Game::GetWhitePlayer() const { return wp_; }
const Board *Game::GetBoard() const { return board_; }

void Game::SetBlackPlayer(Player *p) {
    if (!bp_->IsInGame())
	bp_ = p;
}
void Game::SetWhitePlayer(Player *p) {
    if (!wp_->IsInGame())
	wp_ = p;
}
void Game::SetBoard(Board *b) {
    if (!bp_->IsInGame() && !wp_->IsInGame())
	board_ = b;
}

void Game::Start() const {
    std::cout << "Game Start!" << std::endl;
    bool is_black_turn = true;
    while (bp_->IsInGame()) {
	board_->Draw();
	if (is_black_turn) {
	    bp_->Play(board_);
	    if (bp_->IsLost()) { // check forfeit
		wp_->Win();
		break;
	    }
	} else {
	    wp_->Play(board_);
	    if (wp_->IsLost()) {
		bp_->Win();
		break;
	    }
	}
	is_black_turn = !is_black_turn;
	Judge();
    }
    board_->Draw();
    if (bp_->IsWin())
	std::cout << bp_->GetName() << " (Black) Win!" << std::endl;
    else
	std::cout << wp_->GetName() << " (White) Win!" << std::endl;
}

void Game::Judge() const {
    if (!CheckRows()) {
	if(!CheckCols())
	    CheckDiags();
    }
}

bool Game::CheckRows() const {
    int b_size = board_->GetSize();
    for (int i = 0; i < b_size; i++) {
	int count = 1;
	int cur_state = board_->GetState(i, 0);
	for (int j = 1; j < b_size; j++) {
	    if (CheckWinning(i, j, count, cur_state))
		return true;
	}
    }
    return false;
}

bool Game::CheckCols() const {
    int b_size = board_->GetSize();
    for (int j = 0; j < b_size; j++) {
	int count = 1;
	int cur_state = board_->GetState(0, j);
	for (int i = 1; i < b_size; i++) {
	    if (CheckWinning(i, j, count, cur_state))
		return true;
	}
    }
    return false;
}

bool Game::CheckDiags() const {
    int b_size = board_->GetSize();
    for (int i = 0; i < b_size - WIN_COUNT + 1; i++) {
	int count = 1;
	int y = 0;
	int cur_state = board_->GetState(i, y);
	for (int x = i + 1; x < b_size; x++) {
	    y++;
	    if (CheckWinning(x, y, count, cur_state))
		return true;
	}
    }

    for (int i = WIN_COUNT - 1; i < b_size; i++) {
	int count = 1;
	int y = 0;
	int cur_state = board_->GetState(i, y);
	for (int x = i - 1; x > -1; x--) {
	    y++;
	    if (CheckWinning(x, y, count, cur_state))
		return true;
	}
    }

    for (int i = 0; i < b_size - WIN_COUNT + 1; i++) {
	int count = 1;
	int y = b_size - 1;
	int cur_state = board_->GetState(i, y);
	for (int x = i + 1; x < b_size; x++) {
	    y--;
	    if (CheckWinning(x, y, count, cur_state))
		return true;
	}
    }

    for (int i = WIN_COUNT - 1; i < b_size; i++) {
	int count = 1;
	int y = b_size - 1;
	int cur_state = board_->GetState(i, y);
	for (int x = i - 1; x > -1; x--) {
	    y--;
	    if (CheckWinning(x, y, count, cur_state))
		return true;
	}
    }
    return false;
}

bool Game::CheckWinning(int x, int y, int &count, int &cur_state) const {
    int state = board_->GetState(x, y);
    if (state == cur_state) {
	count++;
	if (count >= WIN_COUNT) {
	    if (state == Board::BLACK) {
		bp_->Win();
		wp_->Lost();
		return true;
	    } else if (state == Board::WHITE){
		wp_->Win();
		bp_->Lost();
		return true;
	    }
	}
    } else {
	count = 1;
	cur_state = state;	
    }
    return false;
}

} // namespace gobang
