#pragma once
#include "board.hpp"

//derive diagBoard from board
class diagBoard : public board {
    private:
        void topDiag();
        void bottomDiag();
        const int n = 9; //Size of board will always be 9 when using diag
    public:
        diagBoard(char type, ifstream& puzFile);
};
