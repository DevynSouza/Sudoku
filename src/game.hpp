#include "tools.hpp"

using namespace std;

class board;

//-------------------------------------------------------------
// Game definition
//-------------------------------------------------------------
class game {
  public:
    game(char* fileName);
    void run();
  private:
    const string menu[6]= {"MenuItem1","MenuItem2","MenuItem3","MenuItem4","MenuItem5","MenuItem6"};
    board* bd;
    short gameSize;
    char gameType;
    ifstream input;
};