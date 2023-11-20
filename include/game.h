#ifndef __GAME_H__
#define __GAME_H__

#include "board.h"
#include "player.h"

namespace gobang {

class Game {
    static const int WIN_COUNT = 5;
    
public:
    Game(Player *bp, Player *wp, Board *board);

    const Player *GetBlackPlayer() const;
    const Player *GetWhitePlayer() const;
    const Board *GetBoard() const;

    void SetBlackPlayer(Player *p);
    void SetWhitePlayer(Player *p);
    void SetBoard(Board *b);
    
    void Start() const;
    
private:
    void Judge() const;
    bool CheckRows() const;
    bool CheckCols() const;
    bool CheckDiags() const;
    bool CheckWinning(int x, int y, int &count, int &cur_state) const;
    
    Player *bp_;
    Player *wp_;
    Board *board_;
};

} // namespace gobang

#endif
