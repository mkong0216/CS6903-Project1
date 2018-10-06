//
//  main.cpp
//  Homophonic Cipher
//
//  Created by Mandy Kong on 10/5/18.
//  Copyright © 2018 Mandy Kong. All rights reserved.
//

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "DigramFreqMatrix.hpp"
using namespace std;

// Reading text file for Test One and inserting each plaintext into vector
vector<string> readTestOneFile () {
    ifstream file;
    file.open("test1_candidate_5_plaintexts.txt");
    
    vector<string> candidates;
    string line;
    
    if (!file) {
        cerr << "Unable to open file\n";
        exit(1);
    }
    
    while (getline(file, line)) {
        if (line.find("Candidate plaintext") == string::npos && line.length() != 1) {
            candidates.push_back(line);
        }
    }

    file.close();
    return candidates;
}

int main(int argc, const char * argv[]) {
    bool done = false;
    string ciphertext;
    string test_num;
    
    vector<string> candidates;

    while (!done) {
        cout << "Enter the ciphertext:\n";
        getline(cin, ciphertext);
        cout << "Which test is being run? Enter 1 for test 1 and 2 for test 2. \n";
        getline(cin, test_num);
        
        if (test_num == "1") {
            // If candidate plaintexts haven't been read from file yet.
            if (candidates.size() == 0) {
                cout << "Preparing candidate plaintexts.\n";
                candidates = readTestOneFile();
                vector<DigramFreqMatrix> frequencyMatrices;
                // Creating a 26 x 26 matrix to represent A-Z letters with initial values zero for each candidate

                for (size_t i = 0; i < candidates.size(); i++) {
                    DigramFreqMatrix plainTextMatrix = DigramFreqMatrix(27, 27, 0);
                    plainTextMatrix.setFrequencyValues(candidates[0]);
                    // Saving each digram frequency matrix for each candidate plaintext in vector frequencyMatrices
                    // DigramFreqMatrix in index 0 corresponds to candidate plaintext 1, and so on.
                    frequencyMatrices.push_back(plainTextMatrix);
                }
            }
            
            done = true;
        } else if (test_num == "2") {
            cout << "Preparing dictionary words.\n";
            done = true;
        } else {
            cout << "That is an invalid test number. Please try again.\n";
            done = false;
        }
    }
    return 0;
}
