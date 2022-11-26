#pragma once
#include "square.hpp"

class cluster{
    private:
        const char* type;   //Stores the print name of the enum cluster type (row, column, box)
        square* clusterBD = new square[9]; //Should only be 9 squares
        int n;  //size of clusterBD
        
    public:
        cluster(const char* type, square* arr, int n);
        ~cluster() {delete [] clusterBD;}  //No longer causes a seg fault for some reason
        void print(ostream& out) const;   //Prints cluster type and 9 squares
        enum ClusterType {row, column, box, diag};
        void shoop(char val);
        const char* getType() {return type;}
};

inline ostream& operator<< (ostream& out, cluster& b) {
    b.print(out);
    return out;
}