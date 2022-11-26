#include "state.hpp"

//-------------------------------------------------------------
/***** STATE METHODS DEFINED HERE ******/
//-------------------------------------------------------------
//Constructor to create tiles depending on if they are filled or not
state::state(char param) {
    value = param;

    if (isdigit(value)) { 
        posList = 0;
        fixed = true;
    } else if (value == '-') { //initialize the fixed flag to false and the possibility list to 0x3fe
        fixed = false;
        posList = 0x3fe;
    } else {
        cerr << "ERROR! Unrecognized Value!";
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
    int tmplist = posList; //Right shift the bits 1
    cout << "\nPossible Bits: ";
    for (int i = 1; i < 10; i++) {
        tmplist = tmplist >> 1;
        if ((tmplist & 0x01) == 1) {  //Bitmask using 1 0000 0001
            cout << i;          
        }
        else  {
            cout << "-";    //If value doesn't exist print a dash as it isn't feasible
        }
        
    }
    //cout << "state::print posList = " << posList << endl;
}


//Turns off the nth bit
void state::turnOff(int n) {
    short mask = 0x01;
    mask = mask << n;
    posList &= ~mask;

}
