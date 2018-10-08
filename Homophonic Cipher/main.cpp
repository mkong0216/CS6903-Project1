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

#include "utils.hpp"
#include "DigramFreqMatrix.hpp"
using namespace std;


int main(int argc, const char * argv[]) {
    bool done = false;
    bool validTest = false;

    string ciphertext;
    string test_num;
    
    // Variables for Test One
    vector<string> candidates;
    vector<DigramFreqMatrix*> frequencyMatrices;
    vector<vector<int>> freqCharTables;

    // Variables for Test Two
    string dictionaryWords;
    vector<int> freqCharTable;
    
    // Variables for Ciphertext
    vector<int> parsedCiphertext;
    vector<int> freqSymbolTable;

    while (!done) {
        cout << "Which test is being run? Enter 1 for test 1, 2 for test 2, or 0 for no more tests. \n";
        getline(cin, test_num);
        
        if (test_num == "0") {
            done = true;
            validTest = false;
        } else if (test_num == "1") {
            validTest = true;
            // If candidate plaintexts haven't been read from file yet.
            if (candidates.size() == 0) {
                cout << "Preparing candidate plaintexts.\n";
                candidates = readTestOneFile();
                
                // Constructing individual character frequencies for plaintexts
                for (size_t i = 0; i < candidates.size(); i++) {
                    vector<int> freqTable = getLetterFrequency(candidates[0], 27);
                    freqCharTables.push_back(freqTable);
                }
                
                // Constructing digram frequency matrices for each plaintext and adding each to frequencyMatrices vector.
                DigramFreqMatrix matrix1(27,27,0);
                matrix1.setFrequencyValues(candidates[0]);
                frequencyMatrices.push_back(&matrix1);
                
                DigramFreqMatrix matrix2(27,27,0);
                matrix2.setFrequencyValues(candidates[1]);
                frequencyMatrices.push_back(&matrix2);
                
                DigramFreqMatrix matrix3(27,27,0);
                matrix3.setFrequencyValues(candidates[2]);
                frequencyMatrices.push_back(&matrix3);
                
                DigramFreqMatrix matrix4(27,27,0);
                matrix4.setFrequencyValues(candidates[3]);
                frequencyMatrices.push_back(&matrix4);
                
                DigramFreqMatrix matrix5(27,27,0);
                matrix5.setFrequencyValues(candidates[4]);
                frequencyMatrices.push_back(&matrix5);
            }
        } else if (test_num == "2") {
            validTest = true;
            cout << "Preparing dictionary words.\n";
            dictionaryWords = readTestTwoFile();

            DigramFreqMatrix testTwoMatrix(27, 27, 0);
            testTwoMatrix.setFrequencyValues(dictionaryWords);
            freqCharTable = getLetterFrequency(dictionaryWords, 27);
        } else {
            validTest = false;
            cout << "That is an invalid test number. Please try again.\n";
        }
        
        if (validTest) {
            cout << "Enter the ciphertext:\n";
            getline(cin, ciphertext);
            parsedCiphertext = parseCiphertext(ciphertext);
            
            // Constructing digram frequency matrix for ciphertext
            DigramFreqMatrix cipherMatrix(106,106,0);
            cipherMatrix.setFrequencyValues(parsedCiphertext);
            
            // Construction individual symbol frequencies for ciphertext
            freqSymbolTable = getSymbolFrequency(parsedCiphertext, 106);
        }
    }
    return 0;
}
