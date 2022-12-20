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
void tradBoard::makeClusters() {

    //9 For loop to create rows
    for (int r = 0; r < n; r++) {  
        createRow(r);
    }  
    

    //9 for loop to create columns
    for (int c = 0; c < n; c++) {
        //Call createColumn();   
        createColumn(c);
    }


    //9 loop to create the 9 boxes
    for (int c = 1; c < 10; c+=3) {
        for (int r = 1; r < 10; r+=3) {
            createBox(c, r);
        }
    }
}

//Static row and iterates columns
void tradBoard::createRow(short r) {
    square** temp = new square*[n];   //Dynamic array of size n
    for (int c = 0; c < n; c++) {   //Runs n times (N = 9) (We have 9 rows and columns 81 in bd)
        temp[c] = &sub(c+1, r+1);       
    }   //Creates a column [c,r], [c2, r], ...
    cluster* create = new cluster(clusterType[row], temp, n);
    for (int c = 0; c < n; c++) {
        sub(c+1, r+1).addCluster(create); //thanks I'm blind
        //temp[c].addCluster(create);   //Don't know what you changed that I didn't but it works now
        
    }

    clusterVec.push_back(create);    //Object created and passed to the clusterVec as a reference. Object may go out of scope we shall see
    delete [] temp;
}

void tradBoard::createColumn(short c) {
    square** temp = new square*[9];
    for (int r = 0; r < n; r++) {
        temp[r] = &sub(c+1, r+1);    
    }   //Creates column [c, r1], [c, r2], [c, r3]...

    cluster* create = new cluster(clusterType[column], temp, n);
    for (int r = 0; r < n; r++) {
        sub(c+1, r+1).addCluster(create); 
        //temp[r].addCluster(create);
    }
    clusterVec.push_back(create);
    delete [] temp;
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
    clusterVec.push_back(create);
    delete [] temp;
}



/***********************************/
/*      End of Cluster Building    */
/***********************************/