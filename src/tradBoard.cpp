#include "tradBoard.hpp"

tradBoard::tradBoard(char type, ifstream& puzFile) : board(type, puzFile) {
    //Board will be made in the board constructor
    //We need to make the clusters
    clusterVec = board::getClusterVec();
    n = board::getSize();
    makeClusters(); 
}

/***********************************/
/*Section for buidling the clusters*/
/***********************************/
void tradBoard::makeBoxes() {

    //9 loop to create the 9 boxes
    for (int c = 1; c < 10; c+=3) {
        for (int r = 1; r < 10; r+=3) {
            createBox(c, r);
        }
    }
}

void tradBoard::createBox(short c, short r) {
   square** temp = new square*[9];
   int count = 0;
    for (int p = c; p < (c+3); p++) {    
        for (int L = r; L < (r+3); L++) {
            temp[count] = &sub(p, L);
            count++;   
        }
    }
    cluster* create = new cluster(clusterType[box], temp, n);
    count = 0;
    for (int p = c; p < (c+3); p++) {    
        for (int L = r; L < (r+3); L++) {
            sub(p, L).addCluster(create); 
            count++;   
        }
    }
    for (int index = 0; index < n; index++) {
        create->shoop( temp[index]->getValue());
    }
    clusterVec.push_back(create);
    delete [] temp;
}

/***********************************/
/*      End of Cluster Building    */
/***********************************/