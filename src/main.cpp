#include "state.hpp"



//Function to test all parameters of Program
void testCase() {
    //Tests functions using the digit as a parameter
    cout <<"\n" <<"<------------------------>" << endl;
    cout <<"Creating object with digit" << endl;
    char test1 = '1';
    state caseTest(test1);
    cout << "Attempting to mark!" << endl;
    char oneTest = '1';
    caseTest.mark(oneTest);
    cout <<"Printing bit set!" << endl;
    cout << caseTest << endl;

    //Tests the functions using a dash as parameter
    cout <<"\n\n" <<"<------------------------>" << endl;
    cout <<"Creating object with -" << endl;
    char testDash = '-';
    state caseDashTest(testDash);
    cout << "Marking with fixed flag!" << endl;
    caseDashTest.mark(testDash);
    cout <<"Printing bit set!" << endl;
    cout << caseDashTest;
    
    

    //Tests the constructor using an invalid input
    cout << "\n\n" << "<------------------------>" << endl;
    cout << "Creating object against the rules: E" << endl;
    char testBad = 'E';
    state errorTest(testBad);



};



int main(void) {
    testCase(); //Runs the testCase function to test all inputs
}
