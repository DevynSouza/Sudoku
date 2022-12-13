#pragma once
#include "frame.hpp"
#include <vector>

class Stack : private vector<frame> {
    private:
        vector<frame*> stackFrame;
    public:
        Stack() = default;
        ~Stack() = default;
        void pop() {stackFrame.pop_back();}
        frame* top() {return stackFrame.back();}
        void push(frame* frame) {stackFrame.push_back(frame);}
        int size() {return stackFrame.vector::size();} //Returns the size of the stack
        void zap() {stackFrame.clear();}   //Empties the entire stack
};

