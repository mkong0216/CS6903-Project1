//
//  DigramFreqMatrix.cpp
//  Homophonic Cipher
//
//  Created by Mandy Kong on 10/6/18.
//  Copyright © 2018 Mandy Kong. All rights reserved.
//

#include "DigramFreqMatrix.hpp"
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
using namespace std;

// Constructor for Any Matrix
DigramFreqMatrix::DigramFreqMatrix(unsigned rowSize, unsigned colSize, double initial){
    num_rows = rowSize;
    num_columns = colSize;
    matrix.resize(rowSize);
    for (unsigned i = 0; i < matrix.size(); i++) {
        matrix[i].resize(colSize, initial);
    }
}

void DigramFreqMatrix::setValue(const unsigned &rowNo, const unsigned & colNo, const int value) {
    this->matrix[rowNo][colNo] = value;
}

// Returns value of given location when asked in the form A(x,y)
int& DigramFreqMatrix::operator()(const unsigned &rowNo, const unsigned & colNo) {
    return this->matrix[rowNo][colNo];
}

// Prints the matrix
void DigramFreqMatrix::print() const
{
    cout << "Digram Frequency Matrix:" << endl;
    for (unsigned i = 0; i < num_rows; i++) {
        for (unsigned j = 0; j < num_columns; j++) {
            cout << "[" << matrix[i][j] << "] ";
        }
        cout << endl;
    }
}

