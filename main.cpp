#include "board.h"
#include "game.h"
#include "player.h"

int main() {
    gobang::Board board;
    gobang::Player player1(true,0, "PoorYou"), player2(false,1, "RoBot");
    gobang::Game game(&player1, &player2, &board);
    game.Start();
}
