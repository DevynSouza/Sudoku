#pragma once
#include "square.hpp"
#include "cluster.hpp"

enum clusterType {
    row, column, box
};
static const char* clusterType[3] = {"row", "column", "box"};

class board{
    private:
        void getPuzzle();
        ifstream& puzFile;
        int n;  //Size of board
        square *bd; //Declared later as new bd[n*n];
        short remDash; //Tracks remaining squares with a -, initialize to n*n
        vector<cluster*> clusterVec;
        void makeClusters();
        void createRow(short j);
        void createColumn(short k);
        void createBox(short j, short k);

    public:
        board(char type, ifstream& puzFile);
        square& sub(int r, int c );
        void print(ostream& out) const;
        ~board(){delete [] bd;};
        void test();    //Test function for making sure things work
    
    
    
};


inline ostream& operator<< (ostream& out, board& b) {
    b.print(out);
    return out;
}
