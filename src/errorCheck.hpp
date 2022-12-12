#pragma once
#include "tools.hpp"

class streamError {
    private:
    public:
        streamError() = default;
        

};

class logicError {
    private:
    public:
        logicError() = default;
        int intValidator();
        char charIntValidator();
        bool validSub(int value, int n);
};
