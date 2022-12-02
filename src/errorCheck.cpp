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

char logicError::charIntValidator() {
    //Try catch to validate input
    char input;
    while (true) {
        try {
            cin >> input;
            if (cin.fail()) {
                throw "Invalid input. Please enter a number.";
            }
            if (input < '1' || input > '9') {
                throw "Invalid input. Please enter a number between 1 and 9.";
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