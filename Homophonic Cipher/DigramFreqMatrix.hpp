//
//  DigramFreqMatrix.hpp
//  Homophonic Cipher
//
//  Created by Mandy Kong on 10/6/18.
//  Copyright © 2018 Mandy Kong. All rights reserved.
//

#ifndef DigramFreqMatrix_hpp
#define DigramFreqMatrix_hpp

#include <stdio.h>
#include <vector>
#include <string>
using std::vector;

class DigramFreqMatrix {
private:
    unsigned num_rows;
    unsigned num_columns;
    vector<vector<int>> matrix;
    
public:
    DigramFreqMatrix(unsigned, unsigned, double);
    
    void setValue(const unsigned &, const unsigned &, int value);
    int& operator()(const unsigned &, const unsigned &);
    void print() const;
};

#endif /* DigramFreqMatrix_hpp */
