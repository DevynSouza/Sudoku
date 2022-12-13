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
    else {fatal("Invalid Game Code in input file");}

    //Viewer fancyView(9, 9, bd);


    //bd = new board(gameType, puzFile);    
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

        choice = menu_c("Please select the number corresponding to the selection you would like.", 7, menu, entries);  //Prints out the menu


        switch (choice) 
        {
            case '1':
                //Mark stuff ask for intput to mark row, column and value, then call board::mark();
                char value;
                int row, column;
                cout << "\nPlease enter a column you wish to mark: ";
                column = intValidator();
                cout << "\nPlease enter a row you wish to mark: ";
                row = intValidator();
                cout << "\nPlease enter a value you wish to mark: ";
                //cin >> value;
                value = charIntValidator();
                
                if(row > 0 && row <= bd->getSize() && column > 0 && column <= bd->getSize()) {
                    if (bd->sub(row,column).getValue() == '-') {bd->remDashSub();}
                    bd->sub(row,column).mark(value);   //Calls the mark function of the square class
                } else {
                    cout << "\nInvalid square, please try again." << endl;
                }
                
                
            
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

};
