#include "sixyBoard.hpp"

sixyBoard::sixyBoard(char gameType, ifstream& puzFile) : board(gameType, puzFile) { 
    clusterVec = board::getClusterVec();
    makeBoxes();

}

void sixyBoard::makeBoxes() {   //Lets do real horizontal
    for (int c = 1; c < 6; c+=3) {  // 1 4
        for (int r = 1; r < 6; r+=2) {  // 1 3 5
            hBox(c, r); //Gets called 6 times 
        }
    }
    for (int c = 1; c < 6; c+=2) {  // 1 3 5
        for (int r = 1; r < 6; r+=3) {  // 1 4
            vBox(c, r); //Gets called 6 times
            
        }
    }
}

void sixyBoard::hBox(int c, int r) { //Pass in the first left quadrant of the box
    //[1,1] [1,2] [2,1] [2,2] [3,1] [3,2]
    square** temp = new square*[6];
    int count = 0;
    for (int p = c; p < (c+3); p++) { //p = 1, 2, 3    stops at 3 ahead of column
        for (int L = r; L < (r+2); L++) {   //L = 1, 2  stops at 2 ahead of row
            temp[count] = &sub(p, L);
            count++;   
        }
    }
    cluster* create = new cluster(clusterType[box], temp, n);
    count = 0;
    for (int p = c; p < (c+3); p++) { //p = 1, 2, 3    stops at 3 ahead of column
        for (int L = r; L < (r+2); L++) {   //L = 1, 2  stops at 2 ahead of row
            sub(p, L).addCluster(create); //Adding clusters to the squares
            count++;   
        }
    }
    for(int index = 0; index < n; index++) {
        create->shoop( temp[index]->getValue());
    }
    clusterVec.push_back(create);
    delete [] temp;
}

void sixyBoard::vBox(int c, int r) {
    //[1,1] [1,2] [1,3] [2,1] [2,2] [2,3]
    square** temp = new square*[6];
    int count = 0;
    for (int p = c; p < (c+2); p++) { //p = 1, 2    stops at 2 ahead of column
        for (int L = r; L < (r+3); L++) {   //L = 1, 2, 3  stops at 3 ahead of row
            temp[count] = &sub(p, L);
            count++;   
        }
    }
    cluster* create = new cluster(clusterType[box], temp, n);
    count = 0;
    for (int p = c; p < (c+2); p++) { //p = 1, 2    stops at 2 ahead of column
        for (int L = r; L < (r+3); L++) {   //L = 1, 2, 3  stops at 3 ahead of row
            sub(p, L).addCluster(create); //Adding clusters to the squares
            count++;   
        }
    }
    for(int index = 0; index < n; index++) {
        create->shoop( temp[index]->getValue());
    }
    clusterVec.push_back(create);
    delete [] temp;
}