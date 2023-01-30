#include "statistics.h"




void fillVector(ifstream& infile, vector<double>& v) {
    double number;

    while (!infile.eof()) {
        infile >> number;
        v.push_back(number);
    }
}




