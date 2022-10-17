#pragma once
#include "state.hpp"


//-------------------------------------------------------------
//Square Definition
//Class comprised of location data and the state object contained inside the square.
//-------------------------------------------------------------

class square {
  public:
    square() = default;
    square(char value, short row, short column);
    void print(ostream &os) const;
    //Used to interface with the mark function from the state class
    inline void mark(char ch) {squareState.mark(ch);} //Calls state's function
    char getValue() {return squareState.getValue();}
    ~square() {};//{cout << "Square Deleted: [" << row << "," << column << "]"<< endl;};

  private:
    state squareState;
    short  row;
    short column;
    vector<square> squares;
};

inline ostream& operator<<(ostream& os, const square& obj) {
    obj.print(os);
    return os;
}