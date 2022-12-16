#pragma once
#include "board.hpp"
#include "diagBoard.hpp"
#include "errorCheck.hpp"
#include "Viewer.hpp"
#include "stack.hpp"
using namespace std;

//Need to forward declare board so the game class can be setup
// class board;


//-------------------------------------------------------------
// Game Class Definition
//-------------------------------------------------------------
class game : public logicError, public gameError {
  
  private:
    const string menu[8]= {"1. Mark","2. Undo","3. Redo","4. Save Game","5. Restore Game","6. Quit Game", "7. Test Board", "8. Turn off Value"};
    board* bd;
    short gameSize;
    char gameType;
    ifstream& puzFile;
    Stack undoStack, redoStack;
    

  public:
    game(ifstream& puzFile);
    ~game() = default;
    void inputter(int choice);
    void mark(int column, int row, int value);
    void turnOff(int column, int row, int value);
    void run();  
};