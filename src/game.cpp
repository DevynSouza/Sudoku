#include "game.hpp"

//-------------------------------------------------------------
/***** Game Constructor ******/
//-------------------------------------------------------------

game::game(ifstream& puzFile) : puzFile(puzFile) {
    //Need to open an puzFile stream
    string line;
    //puzFile.get(gameType);
    puzFile >> gameType;
    bd = new board(gameType, puzFile);    
    

};


void game::test() {
    bd->test();
}


//The running method of the game, this will run a menu in a loop until the player quits the game. 
void game::run() 
{

    string entries = "1234567";  //Valid entries to be passed to the menu function
    char choice;

    //Infinite while loop until the choice is 6(quit) program will then end.
    while (choice != '6')
    {
        cout << *bd; //Very important do not delete, prints entire board!

        choice = menu_c("Please Make An Entry", 7, menu, entries);  //Prints out the menu


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

                //Gotta call shoop now as well
                

                bd->sub(row,column).mark(value);    //So it appears I can't actually interact with the mark function of bd
                //cout << bd->sub(row, column);
                

                break;
            case '2':
                break;
            case '7':
                test();
                
        }
    }

};
