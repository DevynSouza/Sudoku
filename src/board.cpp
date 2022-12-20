#include "board.hpp"
board::board(char type, ifstream& puzFile) : puzFile(puzFile) {
    
    if (type == 't' || type =='d') { n = 9;}
    else if(type == 's') {n = 6; }              //Statements to set game size according to gameType gathered from game::game();

    bd = new square[n*n];   //Allocated a new array of squares n*n
    
    //Fills out bd
    getPuzzle(); 


    //Now we want to build the frame
    createFrame();
};

void board::getPuzzle() {    
    //Loop through puzFile and fill out array
    string input;   //Single line item taken for input
    for (long int r = 0; r <= n; r++) { //R lines in files
        getline(puzFile, input);    
        for (unsigned long c = 1; c <= input.length(); ++c) {  //Iterate over string to pull out square values, each character is another row
            if ((isdigit(input[c-1]) && input[c-1] != 0) || input[c-1] == '-' ) 
            {
                sub(c, r) = square(input[c-1], c, r);
                if (input[c-1] == '-') {remDash++;}
                
            } else { unrecognizedInput();}   
        }
    }
    puzFile.close();
}

frame* board::createFrame() {
    //We need to loop through and save the state of each square to the frame
    frame* newFrame = new frame();

    //We need to copy the 81 states to the frameVec in frame
    for (int index = 0; index < n*n; index++) {
        newFrame->copyState(bd[index].getState());
    }
    return newFrame;
}

void board::restoreState(frame* f) {            //Used to restore the state of the game based on the undo and restore vectors from game. Basically back and forth buttons
    for (int index = 0; index < n*n; index++) {
        bd[index].setState(f->getState(index)); //Will set the state of the square to the state that was contained inside frame
    }
}





void board::test() {
    
    //Lets just print out the clusters themselves from the squares using a test print in square
    //We shall mark then we will call the test function in square
    cout << "Now it is time to mark the board!" << endl;
    cout << "Testing Top Left to Bottom Right Diagonal" << endl;
    cout << "Marking [1,1] with a 5" << endl;
    sub(1,1).mark('5');
    cout << "Now printing the clusters associated!" << endl;
    sub(1,1).test();

    cout << "\n\n\nNow it is time to mark the board again!" << endl;
    cout << "Testing Top Right to Bottom Left Diagonal" << endl;
    cout << "Marking [9,1] with a 9" << endl;
    sub(9,1).mark('9');
    cout << "Now printing the clusters associated!" << endl;
    sub(9,1).test();

    cout << "Marking completed and tested!\n Please compare output to verify it worked!" << endl;

}

//Dynamic Board Printing, prints n square sized board
void board::print(ostream& out) const{
    for (int p = 0; p < n; p++) {       //Prints Top section of top section of board
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
    for (int k = 0; k < n*n; k++) {
        if (k % n == 0 && k != 0) cout << "\n"; //Sub() doesn't work so we modulo k to see if it = gameSize, that lets us know to create a new line
        cout << "|" << bd[k].getValue() << "|";
    }
    cout << "\n";
    for (int p = 0; p < n; p++) {
        cout << "-*-";
    }


}

square& board::sub(int c, int r) const { 
    int value;
    //value = validSub(c, r, n);  //Valides the sub value and ensures it is not out of bounds
    value = ((r-1) * 9 + (c-1));
    return bd[value];
}