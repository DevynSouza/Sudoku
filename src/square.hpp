#pragma once
#include "state.hpp"


//-------------------------------------------------------------
//Square Definition
//Class comprised of location data and the state object contained inside the square.
//-------------------------------------------------------------
class cluster;


class square {
  public:
    square() = default;
    square(char value, short row, short column);
    void print(ostream &os) const;
    //Used to interface with the mark function from the state class
    void mark(char ch); //Calls state's mark functino and also shoops clues
    char getValue() {return squareState.getValue();}
    ~square() {};//{cout << "Square Deleted: [" << row << "," << column << "]"<< endl;};
    void addCluster(cluster* t ) {clues.push_back(t);}
    void turnOff(int n) {squareState.turnoff(n);}

  private:
    state squareState;
    short  row;
    short column;
    vector<square> squares;
    vector<cluster*> clues; //
};

inline ostream& operator<<(ostream& os, const square& obj) {
    obj.print(os);
    return os;

}