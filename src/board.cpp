#include "board.hpp"

board::board(char type, ifstream& puzFile) : puzFile(puzFile) {
    cout << "Board has been created";

    if (type == 't' || type =='d') { n = 9;}
    else if(type == 's') {n = 7; } 
    else {fatal("Invalid Game Code");}

    bd = new square[n*n];   //Allocated a new array of squares n*n

    getPuzzle(); //Do other stuff

 };

void board::getPuzzle() {
    cout << "Get puzzle reached" << endl;
}

void board::print(ostream& out) const{
    cout << "Print Not yet defined!";
}

square& board::sub(int r, int c) {
    int value;
    value = (r-1);
    value += value * 9;
    value += (c -1);
    return bd[value];
}