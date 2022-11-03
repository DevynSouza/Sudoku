#include "game.hpp"

/* USAGE COMENT: ./myapp "file.txt" */


void clusterTest(game test) {
    //All clusters are made, test shoop and printing

    test.test();    //Runs the game test function and other recursive test functions to test cluster
}


//Function to test all parameters of square
void squareTest() {
    //-------------------------------------------------------------
    //Tests functions using the digit as a parameter
    //-------------------------------------------------------------
   
    cout <<"\n" <<"<------------------------>" << endl;
    cout <<"Creating object with digit" << endl;
    square squareTestDigit('1', 1, 1);
    cout << "Printing before marking!" << endl;
    cout << squareTestDigit;
    cout << "Attempting to mark!" << endl;
    squareTestDigit.mark('7');
    cout <<"Printing bit set!" << endl;
    cout << squareTestDigit << endl;
    //-------------------------------------------------------------
    //Tests the functions using a dash as parameter
    //-------------------------------------------------------------
    cout <<"\n" <<"<------------------------>" << endl;
    cout <<"Creating object with dash" << endl;
    square squareTestDash('-', 2, 2);
    cout << "Printing before marking!" << endl;
    cout << squareTestDash;
    cout << "Attempting to mark!" << endl;
    squareTestDash.mark('7');
    cout <<"Printing bit set!" << endl;
    cout << squareTestDash << endl;
    //-------------------------------------------------------------
    //Throws an error
    //-------------------------------------------------------------
    cout << "<------------------------>" << endl;
    cout << "Creating object against the rules: E" << endl;
    square errorTest('E', 3, 3);
    
}


//Function to test all parameters of state
void stateTestCase() {

    //-------------------------------------------------------------
    //Tests functions using the digit as a parameter
    //-------------------------------------------------------------
    cout <<"\n" <<"<------------------------>" << endl;
    cout <<"Creating object with digit" << endl;
    char test1 = '1';
    state caseTest(test1);
    cout << "Attempting to mark!" << endl;
    char oneTest = '1';
    caseTest.mark(oneTest);
    cout <<"Printing bit set!" << endl;
    cout << caseTest << endl;

    //-------------------------------------------------------------
    //Tests the functions using a dash as parameter
    //-------------------------------------------------------------
    cout <<"\n\n" <<"<------------------------>" << endl;
    cout <<"Creating object with -" << endl;
    char testDash = '-';
    state caseDashTest(testDash);
    cout << "Marking with fixed flag!" << endl;
    caseDashTest.mark(testDash);
    cout <<"Printing bit set!" << endl;
    cout << caseDashTest;
    
    
    //-------------------------------------------------------------
    //Tests the constructor using an invalid input
    //-------------------------------------------------------------
    cout << "\n\n" << "<------------------------>" << endl;
    cout << "Creating object against the rules: E" << endl;
    char testBad = 'E';
    state errorTest(testBad);



};


int main(int argc, char* argv[]) {
    banner();


    ifstream puzFile(argv[1]);
    if (!puzFile.is_open()) {fatal("Failed to open file \n Add a file ass a parameter: ./myapp filename.txt");} 
    
    game test(puzFile);
    test.run(); 

    //clusterTest(test);


    
    


    //Parse CMD line for first argument which shoudl be a file name
    // game test(argv[1]);
    // test.run();
    
    //squareTest();
    //stateTestCase(); //Runs th<< argv[1] << endl;on to test all inputs
}
