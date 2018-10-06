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
using namespace std;

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
            cout << "Preparing candidate plaintexts.\n";
            candidates = readTestOneFile();
        } else if (test_num == "2") {
            cout << "Preparing dictionary words.\n";
        } else {
            cout << "That is an invalid test number. Please try again.\n";
            done = false;
        }
    }
    return 0;
}
