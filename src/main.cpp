#include "state.hpp"

void testCase() {

    cout <<"\n" <<"<------------------------>" << endl;
    cout <<"Creating object with digit" << endl;
    char test1 = '1';
    state caseTest(test1);
    cout << "Attempting to mark!" << endl;
    char oneTest = '1';
    caseTest.mark(oneTest);
    cout <<"Printing bit set!" << endl;
    caseTest.print();


    cout <<"\n\n" <<"<------------------------>" << endl;
    cout <<"Creating object with -" << endl;
    char testDash = '-';
    state caseDashTest(testDash);
    cout << "Marking with fixed flag!" << endl;
    caseDashTest.mark(testDash);
    cout <<"Printing bit set!" << endl;
    caseDashTest.print();
    

    cout << "\n\n" << "<------------------------>" << endl;
    cout << "Creating object against the rules: E" << endl;
    char testBad = 'E';
    state errorTest(testBad);



};



int main(void) {
    std::cout << "Hello world" << endl;
    testCase();
    //char so = 'd';
    //state thing(so);
}
