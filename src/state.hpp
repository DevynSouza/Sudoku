#include "tools.hpp"

using namespace std;
class square;
class state;

class square {
  public:
    square();
    ~square() {cout << "Square Deleted: [" << column << "," << row << "]"<< endl;};
    square(char value, short row, short column);
    void print(ostream &os) const;
    void mark(char); //Calls state's function

  private:
    state stateObject;
    short  row;
    short column;
    vector<square> squares;

};

class state {
  public:
    state() = default;
    ~state() = default;
    state(char param);  //Need to initialize with dashes or something
    void print(ostream &os) const; //Print the state thing eg, 0x3fe = 9 8 7 6 5 4 3 2 1 
    void mark(char ch); //Print an error comment if this State is fixed, and do not mark it. Otherwise, make ch the new value in the State. Do not abort
    const char getValue() {return value;};
    
  private:
    short possibilities;
    char value;
    bool fixed;  
    
};


//Operator overload to allow objects to be printed without calling the function
inline ostream& operator<<(ostream& os, const state& obj) {
    obj.print(os);
    return os;
}

inline ostream& operator<<(ostream& os, const square& obj) {
    obj.print(os);
    return os;
}