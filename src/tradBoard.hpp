#pragma once
#include "board.hpp"

class tradBoard : public board {
    protected:
        int n;
        vector<cluster*> clusterVec;
    public:
        tradBoard(char type, ifstream& puzFile);
        void makeBoxes();
        void createBox(short c, short r);
        square& sub(int c, int r) const {return board::sub(c, r);}
};

