#include "errorCheck.hpp"

int logicError::intValidator() {
   //Try catch to validate input
    short input;
    while (true) {
        try {
            cin >> input;
            if (cin.fail()) {
                throw "Invalid input. Please enter a number.";
            }
            break;
        }
        catch (const char* msg) {
            cout << msg << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return input;
};

char logicError::charIntValidator(char gameType) {
    //Try catch to validate input
    char input;
    while (true) {
        try {
            cin >> input;
            if (cin.fail()) {
                throw "Invalid input. Please enter a number.";
            }
            switch(gameType) {
                case 't'||'d':  //Used for tradBoards and diagBoards
                    if (input < '1' || input > '9') {
                        throw "Invalid input. Please enter a number between 1 and 9.";
                    }   
                    break;
                case 's':   //Used for sixy boards
                    if (input < '1' || input > '6') {
                        throw "Invalid input. Please enter a number between 1 and 6.";
                    }  
                    break;

            }
            
            break;
        }
        catch (const char* msg) {
            cout << msg << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return input;
};