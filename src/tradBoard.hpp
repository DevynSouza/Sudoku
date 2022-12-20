#pragma once
#include "board.hpp"

class tradBoard : public board {
    private:

    public:
        tradBoard(char type, ifstream& puzFile) : board(type, puzFile) {};

};