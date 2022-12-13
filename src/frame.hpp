#pragma once
#include "state.hpp"

class frame {
    private:
        vector<state> frameVec;
    
    public:
        void copyState(state obj) {frameVec.push_back(obj);}   
        state getState(int index) {return frameVec[index];}
        //void writeState(state obj) {frameVec.push_back(obj);}

};