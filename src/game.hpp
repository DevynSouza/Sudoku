#pragma once
#include "board.hpp"
using namespace std;

//Need to forward declare board so the game class can be setup
// class board;


//-------------------------------------------------------------
// Game Class Definition
//-------------------------------------------------------------
class game 
{
  public:
    game(ifstream& puzFile);
    void run();
    void test(); //Function for testing parts of program. 
  private:
    const string menu[7]= {"1. Mark","2. Undo","3. Redo","4. Save Game","5. Restore Game","6. Quit Game", "7. Test Board"};
    board* bd;
    short gameSize;
    char gameType;
    ifstream& puzFile;
};