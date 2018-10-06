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

vector<int> parseCiphertext(string str){
    vector<int> ciphertext;
    int cipherSymbol;
    while(str.size()){
        int index = str.find(',');
        if (index != string::npos){
            cipherSymbol = stoi(str.substr(0, index));
            ciphertext.push_back(cipherSymbol);
            str = str.substr(index + 1);
            if(str.size()==0) {
                cipherSymbol = stoi(str);
                ciphertext.push_back(cipherSymbol);
            }
        } else {
            cipherSymbol = stoi(str);
            ciphertext.push_back(cipherSymbol);
            str = "";
        }
    }
    return ciphertext;
}

int main(int argc, const char * argv[]) {
    bool done = false;
    bool validTest = false;
    string ciphertext;
    string test_num;
    
    vector<string> candidates;
    vector<int> parsedCiphertext;
    vector<DigramFreqMatrix*> frequencyMatrices;

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
        }
    }
    return 0;
}
