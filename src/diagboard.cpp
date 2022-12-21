#include "diagBoard.hpp"

diagBoard::diagBoard(char type, ifstream& puzFile) : tradBoard(type, puzFile) {
    topDiag();
    bottomDiag(); //this has a bad_array_new_length error
}

//Creates a cluster of the diagonals from the top left to the bottom right
void diagBoard::topDiag() {
    square** temp = new square*[n];
    int r = 0;
    int c = 0;
    for (int i = 0; i < 9; i++) {
        temp[i] = &sub(c+1, r+1);    //sub(r+1, c+1) is the same as sub(1,1)
        r++;
        c++;
    }

    cluster* create = new cluster(clusterType[diag], temp, n);
    
    r = c = 0;
    for (int i = 0; i < n; i++) {
        sub(c+1, r+1).addCluster(create);
        create->shoop( temp[i]->getValue());
        r++;
        c++;
    }
    //Pushes to the board cluster vector
    clusterVec.push_back(create);
    delete [] temp;

}

//Creates a cluster of the diagonals from the bottom left to the top right
void diagBoard::bottomDiag() {
    square** temp = new square*[n];
    int r = n;
    int c = 0;
    for (int i = 0; i < n; i++) {       //Creates diagonal from 9,1 to 1,9
        temp[c] = &sub(c, r+1);
        r--;
        c++;
    }

    //Add temp cluster to clusterVec
    cluster* create = new cluster(clusterType[diag], temp, n);
    
    r = n;
    c = 0;
    for (int i = 0; i < n; i++) {   //Creates diagonal from 9,1 to 1,9
        sub(c, r+1).addCluster(create);
        r--;
        c++;
    }
        //Pushes to the board cluster vector
    clusterVec.push_back(create);
    delete [] temp;

}