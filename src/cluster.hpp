#pragma once
#include "square.hpp"

enum ClusterType { test, me};

class cluster{
    private:
        const char* type;   //Stores the print name of the enum cluster type
        square* arr[9]; 

    public:
        cluster(char* type, square* arr);
        ~cluster();
        void print(ostream& out) const;   //Prints cluster type and 9 squares
        
        void shoop(char val);


};

inline ostream& operator<< (ostream& out, cluster& b) {
    b.print(out);
    return out;
}