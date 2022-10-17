#include "game.hpp"

//-------------------------------------------------------------
/***** Game Constructor ******/
//-------------------------------------------------------------

//Opens File and retrieves the first character to initiliaze the game type
game::game(ifstream& puzFile) : puzFile(puzFile) {
    //Need to open an puzFile stream
    string line;
    puzFile.get(gameType);
    bd = new board(gameType, puzFile);    
    

};



//The running method of the game, this will run a menu in a loop until the player quits the game. 
void game::run() 
{
    

    string entries = "123456";  //Valid entries to be passed to the menu function
    char choice;

    //Infinite while loop until the choice is 6(quit) program will then end.
    while (choice != '6')
    {
        cout << *bd; //Very important do not delete, prints entire board!

        choice = menu_c("Please Make An Entry", 6, menu, entries);

        //For now only 1 choice has to be made
        switch (choice) 
        {
            case '1':
                //Mark stuff ask for intput to mark row, column and value, then call board::mark();
                char value;
                short row, column;
                cout << "\nPlease enter a row you wish to mark: ";
                cin >> row;
                cout << "\nPlease enter a column you wish to mark: ";
                cin >> column;
                cout << "\nPlease enter a value you wish to mark: ";
                cin >> value;
                //board mark stuffrow, column, value);

                bd->sub(row,column).mark(value);    //So it appears I can't actually interact with the mark function of bd
                cout << bd->sub(row, column);
                
                break;
            case '2':
                break;
        }
    }

};
