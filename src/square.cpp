#include "square.hpp"

//-------------------------------------------------------------
// ******** Square Methods defined here ******** //
//-------------------------------------------------------------
square::square(char value, short row, short column) : squareState(value), row(row), column(column) {
    cerr << "Square: [" << row << "," << column << "] Constructed!" << endl;
}   

//Function for printing the Square in the [x,y] format, additionally calls the state print method as well
void square::print(ostream& os) const{
    cout << "[" << row << "," << column << "]";
    cout << squareState << endl;
}