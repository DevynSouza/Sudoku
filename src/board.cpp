#include "board.hpp"

board::board(char type, ifstream& puzFile) : puzFile(puzFile) {
    if (type == 't' || type =='d') { n = 9;}
    else if(type == 's') {n = 6; }              //Statements to set game size according to gameType gathered from game::game();
    else {fatal("Invalid Game Code");}

    bd = new square[n*n];   //Allocated a new array of squares n*n
    
    
    
    getPuzzle(); //Fills out bd

    //Build 27 clusters
    makeClusters();


    //sub(1,3).print(cout);
    //clusterVec[4]->print(cout);
 };

void board::getPuzzle() {    
    //Loop through puzFile and fill out array
    string input;   //Single line item taken for input
    for (long int i = 0; i <= n; i++) {
        //if (puzFile.eof()) {fatal("End of file reached!");}
        getline(puzFile, input);   //Get input line by line
        for (unsigned long k = 1; k <= input.length(); ++k) {  //Iterate over string to pull out square values
            if ((isdigit(input[k-1]) && input[k-1] != 0) || input[k-1] == '-' ) 
            {
                sub(i, k) = square(input[k-1], i, k);
                //bd->sub(i,k) = square(input[k], i, k);
            } else { fatal("Unrecognized Input");}
            
        }
    }


}

//Dynamic Board Printing, prints n square sized board
void board::print(ostream& out) const{
    for (int p = 0; p < n; p++) {       //Prints Top section of board
        cout << "-*-";
    }
    cout << "\n";
    for (int p = 0; p < n; p++) {      //Prints row Number of board
        cout << "-" << p << "-";
    }
    cout << "\n";
    for (int p = 0; p < n; p++) {       //Prints bottom sectino of top section
        cout << "-*-";
    }

    cout << "\n";
    for (int i = 0; i < n*n; i++) {
        if (i % n == 0 && i != 0) cout << "\n"; //Sub() doesn't work so we modulo i to see if it = gameSize, that lets us know to create a new line
        cout << "|" << bd[i].getValue() << "|";
    }
    cout << "\n";
    for (int p = 0; p < n; p++) {
        cout << "-*-";
    }


    //Cluster::print
}

/***********************************/
/*Section for buidling the clusters*/
/***********************************/
void board::makeClusters() {

    //9 For loop to create rows
    for (int i = 0; i < n; i++) {   //Something in this loop causes a seg fault
        //Call createRow();  
        createRow(i);
    }  
    

    //9 for loop to create columns
    for (int i = 0; i < n; i++) {
        //Call createColumn();   
        createColumn(i);
    }
    //9 loop to create the 9 boxes

    //Replaced Create box function with this
    for (int j = 1; j < 10; j+=3) {
        for (int k = 1; k < 10; k+=3) {
            createBox(j, k);
        }
    }
}

void board::createRow(short j) {
    square* temp = new square[n];   //Dynamic array of size n
    for (int i = 0; i < n; i++) {   //Runs n times (N = 9) (We have 9 rows and columns 81 in bd)
        temp[i] = sub(i+1, j+1);       
    }   //Creates a column [n,j], [n2, j], ...
    cluster* create = new cluster(clusterType[row], temp, n);
    for (int i = 0; i < n; i++) {
        sub(i+1, j+1).addCluster(create); 
        //[n, j], [n2, j]
    }

    clusterVec.push_back(create);    //Object created and passed to the clusterVec as a reference. Object may go out of scope we shall see
    delete [] temp;
}

void board::createColumn(short k) {
    square* temp = new square[9];
    for (int i = 0; i < n; i++) {
        temp[i] = sub(k+1, i+1);    
    }   //Creates column [k, n1], [k, n2], [k, n3]...

    cluster* create = new cluster(clusterType[column], temp, n);
    for (int i = 0; i < n; i++) {
        sub(k+1, i+1).addCluster(create); 
    }
    clusterVec.push_back(create);
    delete [] temp;
}


void board::createBox(short j, short k) {
   square* temp = new square[9];
   int count = 0;
    for (int p = j; p < (j+3); p++) {    
        for (int i = k; i < (k+3); i++) {
            temp[count] = sub(p, i);
            count++;   
        }
    }
    
    cluster* create = new cluster(clusterType[box], temp, n);
    count = 0;
    for (int p = j; p < (j+3); p++) {    
        for (int i = k; i < (k+3); i++) {
            sub(p, i).addCluster(create); 
            count++;   
        }
    }
    clusterVec.push_back(create);
}



/***********************************/
/*      End of Cluster Building    */
/***********************************/

void board::test() {
    
    clusterVec[0]->print(cout);    
    clusterVec[11]->print(cout);
    clusterVec[18]->print(cout);


    cout << "\n\nboard::test() Now it is time to mark!" << endl;
    cout << "board::test() Marking [1,3] with a 5" << endl;
    sub(3,1).mark('5');
    cout << "\n\n";

    clusterVec[0]->print(cout);    
    clusterVec[11]->print(cout);
    clusterVec[18]->print(cout);

}


square& board::sub(int r, int c) {
    int value;
    value = ((r-1) * 9 + (c-1));
    return bd[value];
}