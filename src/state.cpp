#include "state.hpp"


//Constructor to create tiles depending on if they are filled or not
state::state(char param) {
    value = param;

    if (isdigit(value)) { 
        std::cout << "This is a digit" << std::endl;    //Debugging statement
        possibilities = 0;
        fixed = true;
    } else if (value == '-') { //initialize the fixed flag to false and the possibility list to 0x3fe
        fixed = false;
        possibilities = 0x3fe;
        std::cout << "This not a digit!" << endl;
    } else {
        fatal("ERROR! Unrecognized Value!");
    }
}

//Allows a square to be marked, returns an error output if the flag is fixed
void state::mark(char ch) {
    if (fixed == true) {
        cout << "ERROR: State is fixed!" << endl;
    } else {
        value = ch;
        cout << "Value marked!" << endl; //Debugging Statement
    }
}

//Prints all data in the state in a readable way
void state::print(ostream &os) const{ 
    short tmplist = possibilities; 
    for (int i = 1; i < 9; i++) {
        tmplist = tmplist >> 1; //Right shift the bits 1
        if ((tmplist & 0x01) == 1) {  //Bitmask using 1 0000 0001
            cout << i;          
        }
        else  {
            cout << "-";    //If value doesn't exist print a dash as it isn't feasible
        }
    }
}

