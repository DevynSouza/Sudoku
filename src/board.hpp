#pragma once
#include "square.hpp"


class board{
    public:
        board(char type, ifstream& puzFile);
        square& sub(int r, int c );
        void print(ostream& out) const;
        
        ~board(){delete [] bd; cout << "bd deleted!" << endl;};
    private:
        void getPuzzle();
        ifstream& puzFile;
        int n;  //Size of board
        square *bd; //Declared later as new bd[n*n];
        short remDash; //Tracks remaining squares with a -, initialize to n*n

};


inline ostream& operator<< (ostream& out, board& b) {
    b.print(out);
    return out;
}
