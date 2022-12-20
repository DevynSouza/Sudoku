#pragma once
#include "tools.hpp"

class streamError {
    private:
    public:
        streamError() = default;
        void badInputFile() {cerr << "Invalid Input file re-enter input file as argument!" << endl; exit(1); };
        virtual void print() {cerr << "Stream Error detected!" << endl;}

};

class boardError : public streamError {
    public:
        void unrecognizedInput() {streamError::print(); cerr << "Unrecognized input in file! Verify your board is valid." << endl;  exit(1);};
};

class gameError : public streamError {
    public:
        void badGameCode() {streamError::print(); cerr << "Bad game code! Edit the input file with a correct game code: d, t, s" << endl;  exit(1);}

};


class logicError {
    private:
    public:
        logicError() = default;
        int intValidator();
        char charIntValidator(char gameType);
};
