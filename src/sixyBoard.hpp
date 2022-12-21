#pragma once
#include "board.hpp"

class sixyBoard : public board {
    private:
        int n = 6;
        vector<cluster*> clusterVec;
    public:
        sixyBoard(char gameType, ifstream& puzFile);
        
        void makeBoxes();
        void hBox(int c, int r);    //We need 6 of these boxes
        void vBox(int c, int r);    //we need 6 of these boxes

};