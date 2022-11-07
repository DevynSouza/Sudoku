#include "game.hpp"

//-------------------------------------------------------------
/***** Game Constructor ******/
//-------------------------------------------------------------

game::game(ifstream& puzFile) : puzFile(puzFile) {
    string line;
    puzFile >> gameType;
    bd = new board(gameType, puzFile);    
};



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
                cout << "\nPlease enter a column you wish to mark: ";
                cin >> column;
                cout << "\nPlease enter a row you wish to mark: ";
                cin >> row;
                cout << "\nPlease enter a value you wish to mark: ";
                cin >> value;

                bd->sub(row,column).mark(value);   //Calls the mark function of the square class
            
                break;
            case '2':
                break;
            case '3':
                break;
            case '4':
                break;
            case '6':   //Will never hit this as the while loop will end
                bye();
                break;
            case '7':
                bd->test();
                break;
                
        }
    }
    bye();

};
