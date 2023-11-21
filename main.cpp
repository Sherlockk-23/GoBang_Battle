#include "board.h"
#include "game.h"
#include "player.h"

int main() {
    gobang::Board board;
    gobang::Player player1(true,1, "Robot1"), player2(false,2, "RoBot2");
    gobang::Game game(&player1, &player2, &board,0);
    game.Start();
}
