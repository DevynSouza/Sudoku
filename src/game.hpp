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
    const char* menu[6] = {"MenuItem1", "MenuItem2", "MenuItem3", "MenuItem4", "MenuItem5", "MenuItem6" };
  private:
    board* thing;
    short gameSize;
    ifstream input;
};