#include "frame.hpp"

void frame::serialize(ofstream& gameOut) {
    //Used to output the game to the saveFile
    const int n = sqrt(frameVec.size());
    //Now we need to print all the values
    for (int k = 0; k < n; k++) {
        for (int j = 0; j < n; j++) {
            gameOut << frameVec[k*n+j].getValue();
        }
        gameOut << endl;
    }
    gameOut.close();
}

void frame::realize(ifstream& gameIn) { 
    //This was not needed but maybe I'll find out it was
    //Rather than creating a whole thing for reading a board and setting the new inputs
    //I just used the board constructor and it took care of the rest
    
    for (int index = 0; index < frameVec.size(); index++) {
        char value;
        gameIn >> value;
        frameVec[index] = state(value);
    }


}