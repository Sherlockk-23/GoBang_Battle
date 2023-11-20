#ifndef __BOARD_H__
#define __BOARD_H__

namespace gobang {

class Board {
    static const int DEFAULT_SIZE = 15;
    
public:
    static const int BLACK = 1;
    static const int WHITE = -1;
    static const int EMPTY = 0;
    Board();
    Board(int size);
    ~Board();
    
    int GetSize() const;
    int GetState(int x, int y) const;
    bool SetStateBlack(int x, int y);
    bool SetStateWhite(int x, int y);

    int CheckPos(int x,int y) const;

    void Draw() const;

    int lastx,lasty;

    
private:
    void Init();
    bool SetState(int x, int y, int state);
    
    int size_;
    int *state_;
};

} // namespace gobang

#endif
