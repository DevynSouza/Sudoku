#include "square.hpp"
#include "cluster.hpp"
//-------------------------------------------------------------
// ******** Square Methods defined here ******** //
//-------------------------------------------------------------
square::square(char value, short row, short column) : squareState(value), row(row), column(column) {
    //cerr << "Square: [" << row << "," << column << "] Constructed!" << endl;
}   

//Function for printing the Square in the [x,y] format, additionally calls the state print method as well
void square::print(ostream& os) const{
    cout << "[" << row << "," << column << "]";
    cout << squareState << endl;
}

void square::mark(char ch) {
    squareState.mark(ch); 
    //cout << "The size of my clues is: " <<  clues.size();
    for (unsigned int i = 0; i < clues.size(); i++) {
        clues[i]->shoop(ch);
        
    }
    // for (int i = 0; i < clues.size(); i++) { //This will print the clusters the square is contained in. Used for debug purposes
    //     //clues[i]->shoop(ch);
    //     clues[i]->print(cout);
    // }

}