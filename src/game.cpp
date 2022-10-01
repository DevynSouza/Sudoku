#include "game.hpp"

game::game(char* fileName) : input(fileName){
    //Need to open an input stream

    ifstream input(fileName, ios::in | ios::binary);
    //input.open(fileName, ios::binary);
    if (!input.is_open()) {
        cout << "Could not open file " << fileName << endl;
        exit(0);
    } else if (input.is_open()) {
        //Output all lines within the file
        while (!input.eof()) 
        {
            string line;
            getline(input, line);
            if (!line.empty()) {
                cout << line << endl;
            } 
        }
    }
};


// void game::run() {
//     //menu_c( const string title, int n, const string menu[], const string valid)

// };
