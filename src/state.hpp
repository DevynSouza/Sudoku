#include "tools.hpp"

using namespace std;

//-------------------------------------------------------------
//State Definition
//-------------------------------------------------------------
class state {
  public:
    state() = default;
    ~state() = default;
    state(char param);  //Need to initialize with dashes or something
    void print(ostream &os) const; //Print the state thing eg, 0x3fe = 9 8 7 6 5 4 3 2 1 
    void mark(char ch); //Print an error comment if this State is fixed, and do not mark it. Otherwise, make ch the new value in the State. Do not abort
    const char getValue() {return value;};
    
  private:
    int posList;
    char value;
    bool fixed;  
    
};

//-------------------------------------------------------------
//State Definition
//Class comprised of location data and the state object contained inside the square.
//-------------------------------------------------------------
class square {
  public:
    square();
    ~square() {cout << "Square Deleted: [" << column << "," << row << "]"<< endl;};
    square(char value, short row, short column);
    void print(ostream &os) const;
    //Used to interface with the mark function from the state class
    inline void mark(char ch) {squareState.mark(ch);} //Calls state's function

  private:
    state squareState;
    short  row;
    short column;
    vector<square> squares;
};

//Operator extension to allow objects to be printed without calling the function
inline ostream& operator<<(ostream& os, const state& obj) {
    obj.print(os);
    return os;
}

inline ostream& operator<<(ostream& os, const square& obj) {
    obj.print(os);
    return os;
}