#pragma once
#include "tools.hpp"

class streamError {
    private:
        int test = 1;
    public:
        streamError() = default;
        int getTest() {return test;}
        

};

class logicError {
    private:
    public:
        logicError() = default;
        int intValidator();
        char charIntValidator();
        bool validSub(int value, int n);
};
