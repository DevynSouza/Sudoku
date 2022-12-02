#include "square.hpp"
#include "cluster.hpp"
//-------------------------------------------------------------
// ******** Square Methods defined here ******** //
//-------------------------------------------------------------
square::square(char value, short column, short row) : squareState(value), row(row), column(column) {
    //cerr << "Square: [" << row << "," << column << "] Constructed!" << endl;
}   

//Function for printing the Square in the [x,y] format, additionally calls the state print method as well
void square::print(ostream& os) const{
    cout << "[" << column << "," << row << "]";
    cout << squareState << endl;
}

void square::mark(char ch) {
    squareState.mark(ch); 
    //cout << "The size of my clues is: " <<  clues.size();
    for (unsigned int k = 0; k < clues.size(); k++) {
        clues[k]->shoop(ch);   
    }
    
}

void square::test() {
    for (int k = 0; k < (int)clues.size(); k++) { //This will print the clusters the square is contained in. Used for debug purposes
        //clues[k]->shoop(ch);
        clues[k]->print(cout);
    }
}