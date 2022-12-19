#include "game.hpp"

//-------------------------------------------------------------
/***** Game Constructor ******/
//-------------------------------------------------------------

game::game(ifstream& puzFile) : puzFile(puzFile) {
    string line;
    puzFile >> gameType;
    gameType = tolower(gameType);

    if (gameType == 't' ) {bd = new board(gameType, puzFile);}
    else if (gameType =='d') {bd = new diagBoard(gameType, puzFile);}//Make diagonal board }
    else if(gameType == 's') {bd = new board(gameType, puzFile);}              //Statements to set game size according to gameType gathered from game::game();
    else {badGameCode();}

    //This will set an initial undo frame so we can always go back to zero
    undoStack.push(bd->createFrame());  //This will copy all the frames and then push that frame to the undoStack
  
};



//The running method of the game, this will run a menu in a loop until the player quits the game. 
void game::run() 
{
    Viewer fancyView(9, 9, *bd);

    string entries = "12345678";  //Valid entries to be passed to the menu function
    char choice;

    //Infinite while loop until the choice is 6(quit) program will then end.
    while (choice != '6')
    {
        //cout << *bd; //Prints my version of board.
        
        fancyView.show(cout); //Very important do not delete, prints entire board!

        choice = menu_c("Please select the number corresponding to the selection you would like.", 8, menu, entries);  //Prints out the menu


        switch (choice) 
        {
            case '1':   //Calls the mark function
                inputter(1);
                break;
            case '2':   //Undo
                undo();
                break;
            case '3':   //Redo
                redo();
                break;
            case '4':   //Save Game
                saveGame();
                break;
            case '5':   //Restore Game
                restoreGame();  
                break;
            case '6':   //Exit game
                bye();
                break;
            case '7':   //Test Board
                bd->test();
                break;
            case '8': 
                inputter(2);
                break;    
        }
    }

};

void game::undo() {
    if(undoStack.size() < 1) {cout << "No moves to undo!" << endl; return;}   //Stack is empty nothing to undo
    redoStack.push(undoStack.top());    //Pushes the last element from the undo stack to the redo stack
    undoStack.pop();                    //Removes the last element from the stack
    bd->restoreState(undoStack.top());  //Restore the board state to the top of the undo stack
}


void game::redo() {
    if(redoStack.size() < 1){cout << "No moves to redo!" << endl; return;}   //Stack is empty nothing to redo
    undoStack.push(redoStack.top());    //Pushes the last element from the redo stack to the undo stack
    bd->restoreState(redoStack.top());  //Restore the board
    redoStack.pop();
}


void game::saveGame() {
    //Get input and save the frame at the top of the undoStack to the file. Just write the board basically
    string outputFile;
    cout << "Pleaese enter the name to create your save file: ";
    cin >> outputFile;
    ofstream gameOut(outputFile);
    gameOut << gameType << endl;    //We need to output the gameType so when we read it again we can create the correct board
    

    try {   //Try catch to ensure there is a size to the stack to save, otherwise no moves have been made
        if(undoStack.size() == 0) {throw "There is nothing to save";}
        int index = undoStack.size()-1;
        undoStack.saveGame(gameOut);
    } 
    catch (const char* msg) {
        cout << msg << endl;
    }
    
    
};

void game::restoreGame() {
    //Get the save file and recreate the board. Delete the old board and rebuild it using this board
    string inputFile;
    cout << "Please enter the name of the save file: ";
    cin >> inputFile;
    ifstream gameIn(inputFile);
    gameIn >> gameType;

    //There is an issue with realize I believe, it is not copying the frames correctly, or not pushing the frame to the undoStack as there is a segfault when I try to restore the state
    redoStack.zap();
    undoStack.zap();
    // undoStack.realize(gameIn);
    // cout << "Realied gameIn" << endl;
    // cout << "Size of undoStack: " << undoStack.size() << endl;
    // bd->restoreState(undoStack.top());
    //This will copy all the frames and then push that frame to the undoStack

    delete bd;  //Delete the old board 

    if (gameType == 't' ) {bd = new board(gameType, gameIn);}                 //Makes a traditional board
    else if (gameType =='d') {bd = new diagBoard(gameType, gameIn);}          //Make diagonal board }
    else if(gameType == 's') {bd = new board(gameType, gameIn);}              //Statements to set game size according to gameType gathered from game::game();
    else {badGameCode();}

};


void game::inputter(int choice) {
    char value;
    int row, column;
    cout << "\nPlease enter a column you wish to turn off: ";
    column = intValidator();
    cout << "\nPlease enter a row you wish to turn off: ";
    row = intValidator();
    cout << "\nPlease enter a value you wish to turn off: ";
    //cin >> value;
    value = charIntValidator(); 

    if(row > 0 && row <= bd->getSize() && column > 0 && column <= bd->getSize()) {
        if (bd->sub(row,column).getValue() == '-') {bd->remDashSub();}
        if(choice == 1) {
            return mark(column, row, value);
        } else if (choice == 2) {
            return turnOff(column, row, value);
        }
    } else {
        cout << "\nInvalid square, please try again." << endl;
    }

}

void game::mark(int column, int row, int value) {
    bd->sub(row,column).mark(value);    
    undoStack.push(bd->createFrame());  //This will copy all the frames and then push that frame to the undoStack
    redoStack.zap();                    //Clears the redo stack so that the redo function will not work
}

void game::turnOff(int column, int row, int value) {
    bd->sub(row,column).turnOff(value);   //Calls the turnOff function to change the possibility of that squares value
    undoStack.push(bd->createFrame());  //This will copy all the frames and then push that frame to the undoStack
    redoStack.zap();                    //Clears the redo stack so that the redo function will not work
}