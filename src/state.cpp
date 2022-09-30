#include "state.hpp"

//-------------------------------------------------------------
// ******** Square Methods defined here ******** //
//-------------------------------------------------------------
square::square(char value, short row, short column) : squareState(value), row(row), column(column) {
    cerr << "Square: [" << row << "," << column << "] Constructed!" << endl;
}   

//Function for printing the Square in the [x,y] format, additionally calls the state print method as well
void square::print(ostream& os) const{
    cout << "Square: [" << row << "," << column << "]" << endl;
    cout << squareState << endl;
}

//-------------------------------------------------------------
/***** STATE METHODS DEFINED HERE ******/
//-------------------------------------------------------------

//Constructor to create tiles depending on if they are filled or not
state::state(char param) {
    value = param;

    if (isdigit(value)) { 
        //std::cout << "This is a digit" << std::endl;    //Debugging statement
        posList = 0;
        fixed = true;
    } else if (value == '-') { //initialize the fixed flag to false and the possibility list to 0x3fe
        //std::cout << "This not a digit!" << endl;
        fixed = false;
        posList = 0x3f9;
    } else {
        cerr << "ERROR! Unrecognized Value!";
        //fatal("ERROR! Unrecognized Value!");    //What should I do here? Can't return a value and delete it
    }
}

//Allows a square to be marked, returns an error output if the flag is fixed
void state::mark(char ch) {
    if (fixed) {
        cerr << "ERROR: State is fixed!" << endl;
    } else if (ch >= '1' || ch <= '9'){
        value = ch;
        cout << "Value marked!" << endl; //Debugging Statement
        posList = 0;
    } else {
        cerr << "Invalid mark! Use a number between 1 & 9!" << endl;
    }
}

//Prints all data in the state in a readable way
void state::print(ostream &os) const{ 
    int tmplist = posList; 
    cout << "Possible Bits: ";
    for (int i = 1; i < 10; i++) {
        
        if ((tmplist & 0x01) == 1) {  //Bitmask using 1 0000 0001
            cout << i;          
        }
        else  {
            cout << "-";    //If value doesn't exist print a dash as it isn't feasible
        }
        tmplist = tmplist >> 1; //Right shift the bits 1
        
    }
}

