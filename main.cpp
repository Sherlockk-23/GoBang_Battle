#include "board.h"
#include "game.h"
#include "player.h"

int main() {
    gobang::Board board;
    gobang::Player player1(true,0, "Clever You"), player2(false,3, "Dull Robot");
    gobang::Game game(&player1, &player2, &board,0);
    game.Start();
}
