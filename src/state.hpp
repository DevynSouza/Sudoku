#include "tools.hpp"

using namespace std;

class state {
  public:
    state() = default;
    ~state() = default;
    state(char param);  //Need to initialize with dashes or something
    void print(ostream &os) const; //Print the state thing eg, 0x3fe = 9 8 7 6 5 4 3 2 1 
    void mark(char ch); //Print an error comment if this State is fixed, and do not mark it. Otherwise, make ch the new value in the State. Do not abort
    
  private:
    short possibilities;
    char value;
    bool fixed;  
    
};

inline ostream& operator<<(ostream& os, const state& obj) {
    obj.print(os);
    return os;
}