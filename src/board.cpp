#include "board.hpp"

board::board(char type, ifstream& puzFile) : puzFile(puzFile) {
    if (type == 't' || type =='d') { n = 9;}
    else if(type == 's') {n = 7; }              //Statements to set game size according to gameType gathered from game::game();
    else {fatal("Invalid Game Code");}

    bd = new square[n*n];   //Allocated a new array of squares n*n

    getPuzzle(); //Fills out bd
 };

void board::getPuzzle() {
    cout << "Get puzzle reached" << endl;
    
    //Loop through puzFile and fill out array
    string input;   //Single line item taken for input
    for (long int i = 0; i <= n; i++) {
        //if (puzFile.eof()) {fatal("End of file reached!");}
        getline(puzFile, input);   //Get input line by line
        for (unsigned long k = 1; k <= input.length(); ++k) {  //Iterate over string to pull out square values

            if ((isdigit(input[k-1]) && input[k-1] != 0) || input[k-1] == '-' ) 
            {
                sub(i, k) = square(input[k-1], i, k);
                //bd->sub(i,k) = square(input[k], i, k);
            } else { fatal("Unrecognized Input");}
            
        }
    }

}

//Non Dynamic Board Printing, prints 81 square sized board, needs fixing 
void board::print(ostream& out) const{
    for (int p = 0; p < n; p++) {       //Prints Top section of board
        cout << "-*-";
    }
    cout << "\n";
    for (int p = 0; p < n; p++) {      //Prints row Number of board
        cout << "-" << p << "-";
    }
    cout << "\n";
    for (int p = 0; p < n; p++) {       //Prints bottom sectino of top section
        cout << "-*-";
    }

    cout << "\n";
    for (int i = 0; i < n*n; i++) {
        if (i % n == 0 && i != 0) cout << "\n"; //Sub() doesn't work so we modulo i to see if it = gameSize, that lets us know to create a new line
        cout << "|" << bd[i].getValue() << "|";
    }
    cout << "\n";
    for (int p = 0; p < n; p++) {
        cout << "-*-";
    }
}

square& board::sub(int r, int c) {
    int value;
    value = ((r-1) * 9 + (c-1));
    return bd[value];
}