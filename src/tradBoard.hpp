#pragma once
#include "board.hpp"

class tradBoard : public board {
    protected:
        int n;
        vector<cluster*> clusterVec;
    public:
        tradBoard(char type, ifstream& puzFile);
        void makeClusters();
        void createRow(short r);
        void createColumn(short c);
        void createBox(short c, short r);
        square& sub(int c, int r) const {return board::sub(c, r);}
        //Need to get the clusterVec from board
        //vector<cluster*> getClusterVec() {return board::clusterVec;}
};