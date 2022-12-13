#pragma once
#include "square.hpp"
#include "cluster.hpp"
#include "errorCheck.hpp"   
#include "CanView.hpp"
#include "frame.hpp"

enum clusterType {
    row, column, box, diag
};
static const char* clusterType[4] = {"row", "column", "box", "diag"};

class board : public logicError, public streamError, public CanView {
    private:
        void getPuzzle();
        ifstream& puzFile;
        int n;  //Size of board
        square *bd; //Declared later as new bd[n*n];
        short remDash; //Tracks remaining squares with a -, initialize to n*n
        
        void makeClusters();    //Functions to facilititate cluster making
        void createRow(short r);
        void createColumn(short c);
        void createBox(short c, short r);


    protected:
        vector<cluster*> clusterVec;    //Stores all the clusters

    public:
        board(char type, ifstream& puzFile);
        square& sub(int c, int r );
        void print(ostream& out) const;
        ~board(){delete [] bd;};
        void test();    //Test function for making sure things work
        void remDashSub() {remDash--;}
        int getSize() {return n;}

        //Virtual Functions from CanView
        char getMarkChar(int row, int col) {return sub(col, row).getPosList();}
	    string getPossibilityString(int row, int col) {return "0";};

        frame* createFrame();

};


inline ostream& operator<< (ostream& out, board& b) {
    b.print(out);
    return out;
}
