#include "cluster.hpp"

cluster::cluster(const char* type, square* arr, int n) : type(type), n(n)  {
    for (int i = 0; i < n; i++) {
        clusterBD[i] = arr[i];
    }
}

void cluster::shoop(char val) {
    int temp = int(val);
    for (int i = 0; i < n; i++) {
        clusterBD[i].turnOff(temp);
    }
}

void cluster::print(ostream& out) const {
    cout << "Cluster Type: " << type << endl;
    for (int i = 0; i < n; i++) {   //Print the 9 squares in the cluster one per line
        cout << clusterBD[i];
    }
}