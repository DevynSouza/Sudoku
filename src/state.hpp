#pragma once
#include "tools.hpp"

//-------------------------------------------------------------
//State Definition to hold the state of the square
//-------------------------------------------------------------
class state {
  private:
    short posList;
    char value;
    bool fixed;  

  public:
    state() = default;
    ~state() = default;
    state(char param);  //Need to initialize with dashes or something
    void print(ostream &os) const; //Print the state thing eg, 0x3fe = 9 8 7 6 5 4 3 2 1 
    void mark(char ch); //Print an error comment if this State is fixed, and do not mark it. Otherwise, make ch the new value in the State. Do not abort
    const char getValue() {return value;};
    void turnOff(int n);  
    string getPosList();
    
  
    
};

//Operator extension to allow objects to be printed without calling the function
inline ostream& operator<<(ostream& os, const state& obj) {
    obj.print(os);
    return os;
}

