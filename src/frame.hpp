#pragma once
#include "state.hpp"
#include <cmath>

class frame {
    private:
        vector<state> frameVec;
    
    public:
        void copyState(state obj) {frameVec.push_back(obj);}   
        state getState(int index) {return frameVec[index];}
        void serialize(ofstream& gameOut);  //Used to save the game to an output file
        void realize(ifstream& gameIn);     //Used to input the game from the saveFile

};
