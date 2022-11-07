#include "game.hpp"

/* USAGE COMENT: ./myapp "file.txt" */




int main(int argc, char* argv[]) {
    banner();


    ifstream puzFile(argv[1]);
    if (!puzFile.is_open()) {fatal("Failed to open file \n Add a file as a parameter: ./myapp filename.txt");} 
    
    game game(puzFile);
    game.run(); 


}
