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

void DigramFreqMatrix::setFrequencyValues(const std::string& text) {
    // Setting frequency values for plaintext
    int prevChar;
    int currChar;
    for (size_t i = 1; i < text.length(); i++) {
        prevChar = (int)text[i-1];
        currChar = (int)text[i];
        
        if (currChar == 13) continue;
        
        // If the prevChar or currChar is a space, set index to 26,
        // Otherwise set it to a value between 0 and 25 (where a = 0, b = 1, etc.)
        prevChar = (prevChar == 32) ? 26 : (prevChar - 97);
        currChar = (currChar == 32) ? 26 : (currChar - 97);

        matrix[prevChar][currChar] += 1;
    }
}

void DigramFreqMatrix::setFrequencyValues(const vector<int> ciphertext) {
    int prevSymbol, currSymbol;
    for (size_t i = 1; i < ciphertext.size(); i++) {
        prevSymbol = ciphertext[i-1];
        currSymbol = ciphertext[i];
        
        matrix[prevSymbol][currSymbol] += 1;
    }
}

vector<vector<int>> DigramFreqMatrix::getMatrix() {
    return this->matrix;
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

